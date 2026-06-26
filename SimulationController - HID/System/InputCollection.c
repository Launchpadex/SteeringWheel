/*=====================================================================
  InputCollection.c – Final clean version (2025)
=====================================================================*/

#include "InputCollection.h"
#include "flash_settings.h"
#include "usbd_custom_hid_if.h"

extern TIM_HandleTypeDef htim2, htim4;
extern ADC_HandleTypeDef hadc1, hadc2, hadc4;
extern I2C_HandleTypeDef hi2c2;
extern USBD_HandleTypeDef hUsbDeviceFS;
extern SystemSettings system_settings;

/* DMA buffers – private to this file */
static uint16_t adc1_values[ADC1_BUFFERSIZE];
static uint16_t adc2_values[ADC2_BUFFERSIZE];
static uint16_t adc4_values[ADC4_BUFFERSIZE];

/* Global */
static CalibrationState g_calibration = {0};
static RawInputs  g_latest_inputs  = {0};
static MappedAxes g_latest_mapped  = {0};
static uint16_t g_wheel_center = 0;
static int32_t  g_brake_cached = 0;   /* updated independently of main sample rate */

#define NUM_BUTTONS     15
#define DEBOUNCE_TICKS  5
static uint8_t  btn_count[NUM_BUTTONS] = {0};
static uint32_t btn_state = 0;
hid1_report_t hid1_rep = {};
uint16_t g_wheel_pos_raw    = 0;
uint16_t g_wheel_pos_mapped = 0;

/*=====================================================================*/
void Inputs_Init(void)
{
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc4, ADC_SINGLE_ENDED);

    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc1_values, ADC1_BUFFERSIZE);
    HAL_ADC_Start_DMA(&hadc2, (uint32_t*)adc2_values, ADC2_BUFFERSIZE);
    HAL_ADC_Start_DMA(&hadc4, (uint32_t*)adc4_values, ADC4_BUFFERSIZE);

    volatile bool nau_ok = NAU7802_Init(&hi2c2, NAU7802_GAIN_128, NAU7802_SPS_320);
    NAU7802_Tare(&hi2c2);

    Inputs_SetWheelCenter();
}

/* Call from a lower-rate timer (≤ NAU7802 sample rate). */
void Inputs_UpdateBrake(void)
{
	volatile bool ready = NAU7802_IsDataReady(&hi2c2);
	if (ready)
	    g_brake_cached = NAU7802_ReadTared(&hi2c2);
}

/*=====================================================================*/
void Inputs_CollectAll(RawInputs *out)
{
    if (!out) return;

    RawInputs temp = {0}; // Initialize all to zero

    // Read raw button states (active-low)
    uint32_t raw_btns = 0;
    raw_btns |= (!HAL_GPIO_ReadPin(MiskoJOY_BTN_GPIO_Port,      MiskoJOY_BTN_Pin))      ? (1UL << 0) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(BTN_ESC_GPIO_Port,           BTN_ESC_Pin))           ? (1UL << 1) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(BTN_OK_GPIO_Port,            BTN_OK_Pin))            ? (1UL << 2) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(BTN_UP_GPIO_Port,            BTN_UP_Pin))            ? (1UL << 3) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port,          BTN_LEFT_Pin))          ? (1UL << 4) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(BTN_RIGHT_GPIO_Port,         BTN_RIGHT_Pin))         ? (1UL << 5) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(BTN_DOWN_GPIO_Port,          BTN_DOWN_Pin))          ? (1UL << 6) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(LEFT_HAND_JOY_BTN1_GPIO_Port,LEFT_HAND_JOY_BTN1_Pin))? (1UL << 7) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(LEFT_HAND_JOY_BTN2_GPIO_Port,LEFT_HAND_JOY_BTN2_Pin))? (1UL << 8) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(BASE_BTN1_GPIO_Port,         BASE_BTN1_Pin))         ? (1UL << 9) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(BASE_BTN2_GPIO_Port,         BASE_BTN2_Pin))         ? (1UL << 10) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(BASE_BTN3_GPIO_Port,         BASE_BTN3_Pin))         ? (1UL << 11) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(BASE_BTN4_GPIO_Port,         BASE_BTN4_Pin))         ? (1UL << 12) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(WHEEL_GEAR_L_GPIO_Port,      WHEEL_GEAR_L_Pin))      ? (1UL << 13) : 0;
    raw_btns |= (!HAL_GPIO_ReadPin(WHEEL_GEAR_R_GPIO_Port,      WHEEL_GEAR_R_Pin))      ? (1UL << 14) : 0;

    // Debounce: require DEBOUNCE_TICKS consecutive samples before registering change
    for (int i = 0; i < NUM_BUTTONS; i++) {
        if ((raw_btns >> i) & 1) {
            if (btn_count[i] < DEBOUNCE_TICKS) btn_count[i]++;
            if (btn_count[i] == DEBOUNCE_TICKS) btn_state |= (1UL << i);
        } else {
            btn_count[i] = 0;
            btn_state &= ~(1UL << i);
        }
    }
    temp.buttons = btn_state;

    // Read analog values
    temp.wheel = (uint16_t)__HAL_TIM_GET_COUNTER(&htim4);
    g_wheel_pos_raw = temp.wheel;
    temp.throttle   = adc1_values[0];
    temp.clutch     = adc1_values[1];
    temp.brake = g_brake_cached;
    temp.lh_x       = adc2_values[0];
    temp.lh_y       = adc2_values[1];
    temp.lh_slider  = adc2_values[2];
    temp.misko_x    = adc4_values[0];
    temp.misko_y    = adc4_values[1];

    *out = temp;
    g_latest_inputs = temp;
}

const RawInputs* Inputs_GetLatestSnapshot(void)  { return &g_latest_inputs; }
const MappedAxes* Inputs_GetLatestMapped(void)   { return &g_latest_mapped; }

/*=====================================================================*/
void Inputs_MapAxes(const RawInputs *raw, MappedAxes *mapped)
{
    if (!raw || !mapped)
        return;

    const int32_t r[MAX_AXES] = {
        raw->wheel,
        raw->throttle,
        raw->brake,
        raw->clutch,
        raw->lh_x,
        raw->lh_y,
        raw->lh_slider,
        raw->misko_x,
        raw->misko_y
    };

    for (int i = 0; i < MAX_AXES; ++i)
    {
        int32_t raw_val = r[i];
        int32_t output;

        if (i == AXIS_WHEEL) {
            int32_t half          = (int32_t)(system_settings.degrees_of_rotation * WHEEL_COUNTS_PER_DEG(system_settings.wheel_ppr) / 2.0f + 0.5f);
            int16_t signed_offset = (int16_t)(g_wheel_pos_raw - g_wheel_center);
            int32_t pos_from_min  = (int32_t)signed_offset + half;                // 0 = left lock, 2*half = right lock
            if (pos_from_min <= 0)
                output = 0;
            else if (pos_from_min >= 2 * half)
                output = 65534;
            else
                output = (int32_t)((int64_t)pos_from_min * 65534LL / (2 * half));
        } else {
            int32_t min   = system_settings.axis_min[i];
            int32_t max   = system_settings.axis_max[i];
            int32_t sval  = (int32_t)raw_val;
            int32_t range = max - min;
            if (sval <= min)
                output = 0;
            else if (sval >= max)
                output = 65534;
            else if (range <= 0)
                output = 0;
            else
                output = (int32_t)((int64_t)(sval - min) * 65534LL / range);
        }

        if (system_settings.axis_deadzone[i] > 0) {
            int32_t dz = system_settings.axis_deadzone[i];
            bool centered = (i == AXIS_WHEEL || i == AXIS_LH_X || i == AXIS_LH_Y ||
                             i == AXIS_MISKO_X || i == AXIS_MISKO_Y);
            if (centered) {
                /* Center deadzone: dz=200 → ±100 around 32767 snaps to 32767 */
                int32_t half_dz = dz / 2;
                int32_t lo = 32767 - half_dz;
                int32_t hi = 32767 + half_dz;
                if (output <= lo)
                    output = (int32_t)((int64_t)output * 32767LL / lo);
                else if (output >= hi)
                    output = 32767 + (int32_t)((int64_t)(output - hi) * 32767LL / (65534 - hi));
                else
                    output = 32767;
            } else {
                /* Floor deadzone: values 0..dz snap to 0, rest rescaled */
                if (output <= dz)
                    output = 0;
                else
                    output = (int32_t)((int64_t)(output - dz) * 65534LL / (65534 - dz));
            }
        }

        mapped->values[i] = (uint16_t)output;
    }
    g_wheel_pos_mapped = mapped->values[AXIS_WHEEL];
    g_latest_mapped = *mapped;
}
/*=====================================================================*/


void Inputs_BuildAndSendReport(const MappedAxes *mapped, uint16_t button_mask_16bit)
{
    hid1_rep.report_id = 0x10;
    hid1_rep.steering = mapped->values[AXIS_WHEEL];
    hid1_rep.throttle = mapped->values[AXIS_THROTTLE];
    hid1_rep.brake    = mapped->values[AXIS_BRAKE];
    hid1_rep.clutch   = mapped->values[AXIS_CLUTCH];
    hid1_rep.x_axis   = mapped->values[AXIS_LH_X];
    hid1_rep.y_axis   = mapped->values[AXIS_LH_Y];
    hid1_rep.slider   = mapped->values[AXIS_LH_SLIDER];
    hid1_rep.buttons  = button_mask_16bit;

    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&hid1_rep, sizeof(hid1_rep));
}


/*=====================================================================
   CALIBRATION – now type-safe and saves to flash
=====================================================================*/
static void calibration_timer_cb(lv_timer_t *t)
{
    CalibrationState *st = (CalibrationState*)lv_timer_get_user_data(t);

    if (!st->is_calibrating) {
        lv_timer_del(t);
        st->timer = NULL;
        set_var_calibration_status("Cancelled");
        return;
    }

    RawInputs raw;
    Inputs_CollectAll(&raw);

    const int32_t v[MAX_AXES] = {
        raw.wheel, raw.throttle, raw.brake, raw.clutch,
        raw.lh_x, raw.lh_y, raw.lh_slider,
        raw.misko_x, raw.misko_y
    };

    char buf[400] = "Live values:\n";
    for (size_t i = 0; i < st->num_axes; i++) {
        uint32_t axis = st->axes_to_calibrate[i];
        int32_t val = v[axis];

        if (val < system_settings.axis_min[axis])
            system_settings.axis_min[axis] = val;
        if (val > system_settings.axis_max[axis])
            system_settings.axis_max[axis] = val;

        char line[64];
        snprintf(line, sizeof(line), "A%d: %5ld - %5ld\n",
                 (int)axis, (long)system_settings.axis_min[axis], (long)system_settings.axis_max[axis]);
        strncat(buf, line, sizeof(buf)-strlen(buf)-1);
    }

    static uint32_t cnt = 0;
    char status[64];
    snprintf(status, sizeof(status), "Calibrating… %lu samples", ++cnt);
    set_var_calibration_status(status);
    set_var_axis_min_max(buf);
}

void Inputs_StartCalibration(void)
{
    if (g_calibration.is_calibrating) {
        set_var_calibration_status("Already running!");
        return;
    }

    memset(&g_calibration, 0, sizeof(g_calibration));
    g_calibration.is_calibrating = true;

    if (get_var_wheel_calib())   g_calibration.axes_to_calibrate[g_calibration.num_axes++] = AXIS_WHEEL;
    if (get_var_pedals_calib()) {
        g_calibration.axes_to_calibrate[g_calibration.num_axes++] = AXIS_THROTTLE;
        g_calibration.axes_to_calibrate[g_calibration.num_axes++] = AXIS_BRAKE;
        g_calibration.axes_to_calibrate[g_calibration.num_axes++] = AXIS_CLUTCH;
    }
    if (get_var_l_joy_calib()) {
        g_calibration.axes_to_calibrate[g_calibration.num_axes++] = AXIS_LH_X;
        g_calibration.axes_to_calibrate[g_calibration.num_axes++] = AXIS_LH_Y;
        g_calibration.axes_to_calibrate[g_calibration.num_axes++] = AXIS_LH_SLIDER;
    }
    if (get_var_misko_joy_calib()) {
        g_calibration.axes_to_calibrate[g_calibration.num_axes++] = AXIS_MISKO_X;
        g_calibration.axes_to_calibrate[g_calibration.num_axes++] = AXIS_MISKO_Y;
    }

    if (g_calibration.num_axes == 0) {
        set_var_calibration_status("No axes selected");
        g_calibration.is_calibrating = false;
        return;
    }

    // Reset min/max to extreme values
    for (size_t i = 0; i < g_calibration.num_axes; i++) {
        uint32_t a = g_calibration.axes_to_calibrate[i];
        system_settings.axis_min[a] = INT32_MAX;
        system_settings.axis_max[a] = INT32_MIN;
    }

    g_calibration.timer = lv_timer_create(calibration_timer_cb, 50, &g_calibration);
    set_var_calibration_status("Move all controls fully!");
}

void Inputs_StopCalibration(void)
{
    if (!g_calibration.is_calibrating) return;

    g_calibration.is_calibrating = false;
    if (g_calibration.timer) {
        lv_timer_del(g_calibration.timer);
        g_calibration.timer = NULL;
    }

    system_settings.num_axes = MAX_AXES;
    system_settings.valid = 1;

    Flash_Write_All_Settings(FLASH_PAGE_ADDRESS, &system_settings);
    set_var_calibration_status("Calibration saved!");
}

bool Inputs_IsCalibrating(void) { return g_calibration.is_calibrating; }

void Inputs_SetWheelCenter(void)
{
    g_wheel_center = (uint16_t)__HAL_TIM_GET_COUNTER(&htim4);
}
