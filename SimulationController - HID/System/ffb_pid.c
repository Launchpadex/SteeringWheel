/*
 * ffb_pid.c — STM32 USB HID PID force-feedback state machine
 * Printf → route to UART in syscalls.c or use ITM_SendChar for SWO.
 */

#include "ffb_pid.h"
#include <stdio.h>
#include <string.h>

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
} EffectState_t;

static EffectState_t gEffectStates[MAX_EFFECTS + 1]; /* index 0 unused */
PIDBlockLoad_t       gNewEffectBlockLoad;
static uint8_t       gDeviceGain = 255U;

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

int16_t FFB_GetForce(void)
{
    int32_t force = 0;
    for (uint8_t i = FIRST_EID; i <= MAX_EFFECTS; i++) {
        if (gEffectStates[i].state != 2U) continue;
        switch (gEffectStates[i].type) {
        case 0x01U: /* Constant */
            force += (int32_t)gEffectStates[i].magnitude *
                     gEffectStates[i].gain / 32767;
            break;
        /* add Periodic, Spring, Damper later */
        default: break;
        }
    }
    force = force * gDeviceGain / 255;
    if (force >  32767) force =  32767;
    if (force < -32767) force = -32767;
    return (int16_t)force;
}
