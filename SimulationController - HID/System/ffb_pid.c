/*
 * ffb_pid.c — STM32 USB HID PID force-feedback state machine
 * Printf → route to UART in syscalls.c or use ITM_SendChar for SWO.
 */

#include "ffb_pid.h"
#include <stdio.h>
#include <string.h>
#include "stm32g4xx_hal.h"  /* for HAL_GetTick() */
#include "Inc/InputCollection.h"  /* for MAX_AXES */
#include "Inc/FLASH_PAGE.h"  /* for SystemSettings */
#include <stdlib.h>  /* for labs */

/* Extern system settings */
extern SystemSettings system_settings;

/* Fixed point defines: Q15 format, 1.0 = 32767 */
typedef int16_t fixed_t;
#define FIXED_ONE 32767
#define FIXED_PI 10294  /* pi in Q15: 3.14159 * 32767 ≈ 10294 */
#define FIXED_2PI 20588 /* 2*pi in Q15 */

/* Sine lookup table: sin(2*pi*i/256) * 32767 */
static const int16_t sin_table[256] = {
    0, 804, 1607, 2410, 3211, 4011, 4807, 5601, 6392, 7179, 7961, 8739, 9511, 10278, 11038, 11792,
    12539, 13278, 14009, 14732, 15446, 16150, 16845, 17530, 18204, 18867, 19519, 20159, 20787, 21402,
    22004, 22594, 23169, 23731, 24278, 24811, 25329, 25831, 26318, 26789, 27244, 27683, 28105, 28510,
    28900, 29268, 29621, 29955, 30272, 30571, 30851, 31113, 31356, 31580, 31785, 31970, 32137, 32284,
    32412, 32520, 32609, 32678, 32727, 32757, 32767, 32757, 32727, 32678, 32609, 32520, 32412, 32284,
    32137, 31970, 31785, 31580, 31356, 31113, 30851, 30571, 30272, 29955, 29621, 29268, 28900, 28510,
    28105, 27683, 27244, 26789, 26318, 25831, 25329, 24811, 24278, 23731, 23169, 22594, 22004, 21402,
    20787, 20159, 19519, 18867, 18204, 17530, 16845, 16150, 15446, 14732, 14009, 13278, 12539, 11792,
    11038, 10278, 9511, 8739, 7961, 7179, 6392, 5601, 4807, 4011, 3211, 2410, 1607, 804,
    0, -804, -1607, -2410, -3211, -4011, -4807, -5601, -6392, -7179, -7961, -8739, -9511, -10278, -11038, -11792,
    -12539, -13278, -14009, -14732, -15446, -16150, -16845, -17530, -18204, -18867, -19519, -20159, -20787, -21402,
    -22004, -22594, -23169, -23731, -24278, -24811, -25329, -25831, -26318, -26789, -27244, -27683, -28105, -28510,
    -28900, -29268, -29621, -29955, -30272, -30571, -30851, -31113, -31356, -31580, -31785, -31970, -32137, -32284,
    -32412, -32520, -32609, -32678, -32727, -32757, -32767, -32757, -32727, -32678, -32609, -32520, -32412, -32284,
    -32137, -31970, -31785, -31580, -31356, -31113, -30851, -30571, -30272, -29955, -29621, -29268, -28900, -28510,
    -28105, -27683, -27244, -26789, -26318, -25831, -25329, -24811, -24278, -23731, -23169, -22594, -22004, -21402,
    -20787, -20159, -19519, -18867, -18204, -17530, -16845, -16150, -15446, -14732, -14009, -13278, -12539, -11792,
    -11038, -10278, -9511, -8739, -7961, -7179, -6392, -5601, -4807, -4011, -3211, -2410, -1607, -804
};

typedef struct {
    uint8_t  state;       /* 0=free, 1=allocated, 2=playing */
    uint8_t  type;
    uint16_t duration;
    uint16_t startDelay;
    int16_t  gain;
    uint8_t  triggerButton;
    uint8_t  enableAxis;
    uint16_t direction;
    /* Constant force */
    int16_t  magnitude;
    /* Periodic */
    int16_t  periodicMagnitude;
    int16_t  periodicOffset;
    uint8_t  phase;
    uint16_t period;
    /* Envelope */
    uint8_t  attackLevel, fadeLevel;
    uint16_t attackTime, fadeTime;
    /* Condition */
    uint8_t  parameterBlockOffset;
    int16_t  cpOffset, positiveCoefficient;
    uint8_t  deadBand;
    /* Ramp */
    int8_t   rampStart, rampEnd;
    /* Operation */
    uint8_t  loopCount;
    /* Internal timing */
    uint32_t startTime;
} EffectState_t;

static EffectState_t gEffectStates[MAX_EFFECTS + 1]; /* index 0 unused */
PIDBlockLoad_t       gNewEffectBlockLoad;
static uint8_t       gDeviceGain = 255U;

/* Axis state for speed/accel calculation */

static AxisState_t gAxisStates[MAX_AXES] = {0};

/* ------------------------------------------------------------------ */
/* Speed and acceleration calculation functions */

int32_t FFB_CalculateSpeed(uint8_t axis_id, int32_t current_pos, uint32_t current_time_ms)
{
    if (axis_id >= MAX_AXES) return 0;
    AxisState_t *state = &gAxisStates[axis_id];

    if (state->prev_pos_time == 0) {
        state->prev_pos = current_pos;
        state->prev_pos_time = current_time_ms;
        state->prev_speed = 0;
        state->prev_speed_time = current_time_ms;
        state->curr_speed = 0;
        state->curr_speed_time = current_time_ms;
        return 0;
    }

    int32_t dt = (int32_t)(current_time_ms - state->prev_pos_time);
    if (dt <= 0) return state->curr_speed;

    int32_t speed = ((current_pos - state->prev_pos) * 1000) / dt;  // speed in pos/s

    state->prev_pos = current_pos;
    state->prev_pos_time = current_time_ms;

    state->prev_speed = state->curr_speed;
    state->prev_speed_time = state->curr_speed_time;
    state->curr_speed = speed;
    state->curr_speed_time = current_time_ms;

    return speed;
}

int32_t FFB_CalculateAccel(uint8_t axis_id, int32_t current_speed, uint32_t current_time_ms)
{
    if (axis_id >= MAX_AXES) return 0;
    AxisState_t *state = &gAxisStates[axis_id];

    if (state->prev_speed_time == 0 || state->prev_speed_time == state->curr_speed_time) {
        state->curr_speed = current_speed;
        state->curr_speed_time = current_time_ms;
        return 0;
    }

    int32_t dt = (int32_t)(current_time_ms - state->prev_speed_time);
    if (dt <= 0) return 0;

    int32_t accel = ((current_speed - state->prev_speed) * 1000) / dt;  // accel in pos/s²

    return accel;
}

/* ------------------------------------------------------------------ */
/* Effect math functions */

static int16_t ConstrainEffect(int32_t val) {
    if (val > 32767) return 32767;
    if (val < -32767) return -32767;
    return (int16_t)val;
}

static int16_t ApplyEnvelope(int16_t magnitude, uint32_t elapsed, uint8_t attackLevel, uint8_t fadeLevel, uint16_t attackTime, uint16_t fadeTime, uint16_t duration, uint16_t startDelay) {
    if (elapsed < startDelay) return 0;
    uint32_t effectTime = elapsed - startDelay;
    if (effectTime >= duration) return 0;

    if (effectTime < attackTime && attackTime > 0) {
        return (int16_t)((int32_t)magnitude * attackLevel / 255);
    } else if (effectTime > (duration - fadeTime) && fadeTime > 0) {
        return (int16_t)((int32_t)magnitude * fadeLevel / 255);
    }
    return magnitude;
}

static int16_t SineEffect(int16_t mag, uint16_t period, uint8_t phase, uint32_t t) {
    if (period == 0) return 0;
    uint32_t t_mod = t % period;
    uint32_t angle = (t_mod * 256UL) / period;
    angle = (angle + phase) % 256;
    int16_t sin_val = sin_table[angle];
    return (int16_t)((int32_t)mag * sin_val / FIXED_ONE);
}

static int16_t RampEffect(int8_t start, int8_t end, uint16_t duration, uint32_t t) {
    if (duration == 0) return (int16_t)start * 256;
    int32_t delta = (int32_t)(end - start) * 256;
    int32_t val = (int32_t)start * 256 + delta * (int32_t)t / (int32_t)duration;
    return ConstrainEffect(val);
}

static int16_t SpringEffect(int32_t err, int16_t mag) {
    return ConstrainEffect((int32_t)mag * err * system_settings.ffb_spring_coef / 256);
}

static int16_t DamperEffect(int32_t spd, int16_t mag) {
    if (labs(spd) < system_settings.ffb_spd_threshold) return 0;
    return ConstrainEffect(-(int32_t)mag * spd * system_settings.ffb_damper_coef / 512);
}

static int16_t InertiaEffect(int32_t acl, int16_t mag) {
    if (labs(acl) < system_settings.ffb_acl_threshold) return 0;
    return ConstrainEffect(-(int32_t)mag * acl * system_settings.ffb_inertia_coef / 32);
}

static int16_t FrictionEffect(int32_t spd, int16_t mag) {
    if (labs(spd) < system_settings.ffb_frc_threshold) return ConstrainEffect(-(int32_t)spd * mag * system_settings.ffb_friction_coef / (system_settings.ffb_frc_threshold * 32));
    return ConstrainEffect(-(int32_t)mag * system_settings.ffb_friction_coef / 32 * (spd > 0 ? 1 : -1));
}

/* ------------------------------------------------------------------ */

void FFB_Init(void)
{
    memset(gEffectStates, 0, sizeof(gEffectStates));
    memset(&gNewEffectBlockLoad, 0, sizeof(gNewEffectBlockLoad));
    gDeviceGain = 255U;
    printf("[FFB] Init\r\n");
}

/* ------------------------------------------------------------------ */

static uint8_t GetNextFreeEffect(void)
{
    for (uint8_t i = FIRST_EID; i <= MAX_EFFECTS; i++)
        if (gEffectStates[i].state == 0U) return i;
    return 0U;
}

void FFB_CreateNewEffect(CreateNewEffect_t *in, PIDBlockLoad_t *out)
{
    uint8_t eid = GetNextFreeEffect();
    out->report_id = 6U;
    if (eid == 0U) {
        out->effect_block_index = 0U;
        out->load_status        = 2U; /* Full */
        out->ram_pool_available = 0U;
        printf("[FFB] CreateNewEffect type=%d -> FULL\r\n", in->effect_type);
    } else {
        gEffectStates[eid].state = 1U;
        gEffectStates[eid].type  = in->effect_type;
        out->effect_block_index  = eid;
        out->load_status         = 1U; /* Success */
        out->ram_pool_available  = 0xFFFFU;
        printf("[FFB] CreateNewEffect type=%d -> eid=%d\r\n", in->effect_type, eid);
    }
}

void FFB_GetPIDPool(PIDPool_t *out)
{
    out->report_id                = 7U;
    out->ram_pool_size            = 0xFFFFU;
    out->max_simultaneous_effects = MAX_EFFECTS;
    out->memory_management        = 3U;
    printf("[FFB] GetPIDPool\r\n");
}

/* ------------------------------------------------------------------ */

void FFB_ProcessOutputReport(uint8_t *buf, uint16_t len)
{
    if (len < 1U) return;
    uint8_t rid = buf[0];

    switch (rid) {

    case 0x01U: /* Set Effect */
        if (len >= 13U) {
            uint8_t  eid  = buf[1];
            uint8_t  type = buf[2];
            uint16_t dur  = (uint16_t)(buf[3]  | ((uint16_t)buf[4]  << 8));
            int16_t  gain = (int16_t) (buf[7]  | ((uint16_t)buf[8]  << 8));
            uint16_t dir  = (uint16_t)(buf[11] | ((uint16_t)buf[12] << 8));
            printf("[FFB] SetEffect eid=%d type=%d dur=%u gain=%d dir=%u\r\n",
                   eid, type, dur, gain, dir);
            if (eid >= FIRST_EID && eid <= MAX_EFFECTS) {
                gEffectStates[eid].type      = type;
                gEffectStates[eid].duration  = dur;
                gEffectStates[eid].gain      = gain;
                gEffectStates[eid].direction = dir;
                gEffectStates[eid].triggerButton = buf[9];
                gEffectStates[eid].enableAxis    = buf[10];
                if (len >= 15U)
                    gEffectStates[eid].startDelay =
                        (uint16_t)(buf[13] | ((uint16_t)buf[14] << 8));
            }
        }
        break;

    case 0x02U: /* Set Envelope */
        if (len >= 8U) {
            uint8_t eid = buf[1];
            printf("[FFB] SetEnvelope eid=%d atk=%u fade=%u atkT=%u fadT=%u\r\n",
                   eid, buf[2], buf[3],
                   (uint16_t)(buf[4]|(uint16_t)(buf[5]<<8)),
                   (uint16_t)(buf[6]|(uint16_t)(buf[7]<<8)));
            if (eid >= FIRST_EID && eid <= MAX_EFFECTS) {
                gEffectStates[eid].attackLevel = buf[2];
                gEffectStates[eid].fadeLevel   = buf[3];
                gEffectStates[eid].attackTime  = (uint16_t)(buf[4]|(uint16_t)(buf[5]<<8));
                gEffectStates[eid].fadeTime    = (uint16_t)(buf[6]|(uint16_t)(buf[7]<<8));
            }
        }
        break;

    case 0x03U: /* Set Condition */
        if (len >= 7U) {
            uint8_t eid   = buf[1];
            int16_t cpOff = (int16_t)(buf[3]|(uint16_t)(buf[4]<<8));
            int16_t posK  = (int16_t)(buf[5]|(uint16_t)(buf[6]<<8));
            printf("[FFB] SetCondition eid=%d pbo=%d cpOff=%d posK=%d dead=%u\r\n",
                   eid, buf[2], cpOff, posK, len>=8U ? buf[7] : 0);
            if (eid >= FIRST_EID && eid <= MAX_EFFECTS) {
                gEffectStates[eid].parameterBlockOffset = buf[2];
                gEffectStates[eid].cpOffset             = cpOff;
                gEffectStates[eid].positiveCoefficient  = posK;
                gEffectStates[eid].deadBand             = len>=8U ? buf[7] : 0U;
            }
        }
        break;

    case 0x04U: /* Set Periodic */
        if (len >= 8U) {
            uint8_t  eid = buf[1];
            int16_t  mag = (int16_t)(buf[2]|(uint16_t)(buf[3]<<8));
            int16_t  off = (int16_t)(buf[4]|(uint16_t)(buf[5]<<8));
            uint16_t per = (uint16_t)(buf[7]|(uint16_t)(buf[8]<<8));
            printf("[FFB] SetPeriodic eid=%d mag=%d off=%d phase=%u period=%u\r\n",
                   eid, mag, off, buf[6], per);
            if (eid >= FIRST_EID && eid <= MAX_EFFECTS) {
                gEffectStates[eid].periodicMagnitude = mag;
                gEffectStates[eid].periodicOffset    = off;
                gEffectStates[eid].phase             = buf[6];
                gEffectStates[eid].period            = per;
            }
        }
        break;

    case 0x05U: /* Set Constant Force  ← main force report */
        if (len >= 4U) {
            uint8_t eid = buf[1];
            int16_t mag = (int16_t)(buf[2] | ((uint16_t)buf[3] << 8));
            printf("[FFB] SetConstantForce eid=%d magnitude=%d\r\n", eid, mag);
            if (eid >= FIRST_EID && eid <= MAX_EFFECTS)
                gEffectStates[eid].magnitude = mag;
        }
        break;

    case 0x06U: /* Set Ramp Force */
        if (len >= 4U) {
            uint8_t eid = buf[1];
            printf("[FFB] SetRampForce eid=%d start=%d end=%d\r\n",
                   eid, (int8_t)buf[2], (int8_t)buf[3]);
            if (eid >= FIRST_EID && eid <= MAX_EFFECTS) {
                gEffectStates[eid].rampStart = (int8_t)buf[2];
                gEffectStates[eid].rampEnd   = (int8_t)buf[3];
            }
        }
        break;

    case 0x0AU: /* Effect Operation */
        if (len >= 4U) {
            uint8_t eid = buf[1];
            uint8_t op  = buf[2];
            uint8_t lp  = buf[3];
            printf("[FFB] EffectOp eid=%d op=%s(%d) loop=%d\r\n",
                   eid,
                   op==1U?"Start":op==2U?"StartSolo":op==3U?"Stop":"?",
                   op, lp);
            if (eid >= FIRST_EID && eid <= MAX_EFFECTS) {
                if (op == 2U) { /* StartSolo — stop all others */
                    for (uint8_t i = FIRST_EID; i <= MAX_EFFECTS; i++)
                        if (i != eid && gEffectStates[i].state == 2U)
                            gEffectStates[i].state = 1U;
                }
                if (op == 1U || op == 2U) {
                    gEffectStates[eid].state     = 2U;
                    gEffectStates[eid].loopCount = lp;
                    gEffectStates[eid].startTime = HAL_GetTick();  /* assuming HAL_GetTick() for time */
                } else if (op == 3U) {
                    if (gEffectStates[eid].state == 2U)
                        gEffectStates[eid].state = 1U;
                }
            }
        }
        break;

    case 0x0BU: /* Block Free */
        if (len >= 2U) {
            uint8_t eid = buf[1];
            printf("[FFB] BlockFree eid=%d\r\n", eid);
            if (eid >= FIRST_EID && eid <= MAX_EFFECTS)
                memset(&gEffectStates[eid], 0, sizeof(EffectState_t));
        }
        break;

    case 0x0CU: /* Device Control */
        if (len >= 2U) {
            uint8_t c = buf[1];
            printf("[FFB] DeviceControl 0x%02X%s%s%s%s%s%s\r\n", c,
                   c&0x01U?" EnActuators":"", c&0x02U?" DisActuators":"",
                   c&0x04U?" StopAll":"",   c&0x08U?" Reset":"",
                   c&0x10U?" Pause":"",     c&0x20U?" Continue":"");
            if (c & 0x08U)
                memset(gEffectStates, 0, sizeof(gEffectStates));
            else if (c & 0x04U)
                for (uint8_t i = FIRST_EID; i <= MAX_EFFECTS; i++)
                    if (gEffectStates[i].state == 2U) gEffectStates[i].state = 1U;
        }
        break;

    case 0x0DU: /* Device Gain */
        if (len >= 2U) {
            gDeviceGain = buf[1];
            printf("[FFB] DeviceGain=%d\r\n", gDeviceGain);
        }
        break;

    default:
        printf("[FFB] Unknown rid=0x%02X len=%d\r\n", rid, len);
        break;
    }
}

/* ------------------------------------------------------------------ */
/*  Call this from your motor/PWM control loop                         */
/* ------------------------------------------------------------------ */

int32_t FFB_GetForce(int32_t position, int32_t speed, int32_t accel, uint32_t current_time_ms)
{
    int32_t force = 0;
    for (uint8_t i = FIRST_EID; i <= MAX_EFFECTS; i++) {
        if (gEffectStates[i].state != 2U) continue;
        uint32_t elapsed = current_time_ms - gEffectStates[i].startTime;
        int16_t effect_force = 0;
        int16_t mag = gEffectStates[i].magnitude;

        switch (gEffectStates[i].type) {
        case 0x01U: /* Constant */
            mag = ApplyEnvelope(mag, elapsed, gEffectStates[i].attackLevel, gEffectStates[i].fadeLevel,
                                gEffectStates[i].attackTime, gEffectStates[i].fadeTime,
                                gEffectStates[i].duration, gEffectStates[i].startDelay);
            effect_force = (int32_t)mag * gEffectStates[i].gain / 32767;
            break;

        case 0x02U: /* Ramp */
            mag = RampEffect(gEffectStates[i].rampStart, gEffectStates[i].rampEnd, gEffectStates[i].duration, elapsed);
            mag = ApplyEnvelope(mag, elapsed, gEffectStates[i].attackLevel, gEffectStates[i].fadeLevel,
                                gEffectStates[i].attackTime, gEffectStates[i].fadeTime,
                                gEffectStates[i].duration, gEffectStates[i].startDelay);
            effect_force = (int32_t)mag * gEffectStates[i].gain / 32767;
            break;

        case 0x03U: /* Square */
        case 0x04U: /* Sine */
        case 0x05U: /* Triangle */
        case 0x06U: /* SawtoothUp */
        case 0x07U: /* SawtoothDown */
            /* Simplified: use sine for all periodic */
            mag = SineEffect(gEffectStates[i].periodicMagnitude, gEffectStates[i].period, gEffectStates[i].phase, elapsed);
            mag += gEffectStates[i].periodicOffset;
            mag = ApplyEnvelope(mag, elapsed, gEffectStates[i].attackLevel, gEffectStates[i].fadeLevel,
                                gEffectStates[i].attackTime, gEffectStates[i].fadeTime,
                                gEffectStates[i].duration, gEffectStates[i].startDelay);
            effect_force = (int32_t)mag * gEffectStates[i].gain / 32767;
            break;

        case 0x08U: /* Spring */
            effect_force = SpringEffect(position - gEffectStates[i].cpOffset, gEffectStates[i].positiveCoefficient);
            break;

        case 0x09U: /* Damper */
            effect_force = DamperEffect(speed - gEffectStates[i].cpOffset, gEffectStates[i].positiveCoefficient);
            break;

        case 0x0AU: /* Inertia */
            effect_force = InertiaEffect(accel - gEffectStates[i].cpOffset, gEffectStates[i].positiveCoefficient);
            break;

        case 0x0BU: /* Friction */
            effect_force = FrictionEffect(speed - gEffectStates[i].cpOffset, gEffectStates[i].positiveCoefficient);
            break;

        default:
            break;
        }

        force += effect_force;
    }

    force = force * gDeviceGain / 255;
    force = ConstrainEffect(force);

    /* Scale force to current in mA */
    int32_t current_mA = (force * system_settings.ffb_gain * system_settings.ffb_max_current_mA) / (32767 * 100);

    return current_mA;
}

/* ------------------------------------------------------------------ */
/*  Motor output helper - replace pins/timer with your hardware setup    */
/* ------------------------------------------------------------------ */

void FFB_SetMotorCurrent(int32_t current_mA)
{
    /* Placeholder for VESC current control */
    /* current_mA: desired motor current in mA, negative for reverse */
    /* Clamp to max current from settings */
    if (current_mA > system_settings.ffb_max_current_mA) {
        current_mA = system_settings.ffb_max_current_mA;
    } else if (current_mA < -system_settings.ffb_max_current_mA) {
        current_mA = -system_settings.ffb_max_current_mA;
    }

    /* TODO: Send current command to VESC */
    /* For now, just print or do nothing */
    (void)current_mA;  /* Suppress unused warning */
}
