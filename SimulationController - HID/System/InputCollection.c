/*=====================================================================
  InputCollection.c – Final clean version (2025)
=====================================================================*/

#include "InputCollection.h"
#include "flash_settings.h"
#include "usbd_custom_hid_if.h"

extern TIM_HandleTypeDef htim2, htim4;
extern ADC_HandleTypeDef hadc1, hadc2, hadc4;
extern USBD_HandleTypeDef hUsbDeviceFS;
extern SystemSettings system_settings;

/* DMA buffers – private to this file */
static uint16_t adc1_values[ADC1_BUFFERSIZE];
static uint16_t adc2_values[ADC2_BUFFERSIZE];
static uint16_t adc4_values[ADC4_BUFFERSIZE];

/* Global */
static CalibrationState g_calibration = {0};
static RawInputs g_latest_inputs = {0};
hid1_report_t hid1_rep = {};

/*=====================================================================*/
void Inputs_Init(void)
{
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc4, ADC_SINGLE_ENDED);

    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc1_values, ADC1_BUFFERSIZE);
    HAL_ADC_Start_DMA(&hadc2, (uint32_t*)adc2_values, ADC2_BUFFERSIZE);
    HAL_ADC_Start_DMA(&hadc4, (uint32_t*)adc4_values, ADC4_BUFFERSIZE);
}

/*=====================================================================*/
void Inputs_CollectAll(RawInputs *out)
{
    if (!out) return;

    RawInputs temp = {0}; // Initialize all to zero

    // Map buttons with explicit bit positions
    temp.buttons = 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(MiskoJOY_BTN_GPIO_Port,      MiskoJOY_BTN_Pin))      ? (1UL << 0) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(BTN_ESC_GPIO_Port,           BTN_ESC_Pin))           ? (1UL << 1) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(BTN_OK_GPIO_Port,            BTN_OK_Pin))            ? (1UL << 2) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(BTN_UP_GPIO_Port,            BTN_UP_Pin))            ? (1UL << 3) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port,          BTN_LEFT_Pin))          ? (1UL << 4) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(BTN_RIGHT_GPIO_Port,         BTN_RIGHT_Pin))         ? (1UL << 5) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(BTN_DOWN_GPIO_Port,          BTN_DOWN_Pin))          ? (1UL << 6) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(LEFT_HAND_JOY_BTN1_GPIO_Port,LEFT_HAND_JOY_BTN1_Pin))? (1UL << 7) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(LEFT_HAND_JOY_BTN2_GPIO_Port,LEFT_HAND_JOY_BTN2_Pin))? (1UL << 8) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(BASE_BTN1_GPIO_Port,         BASE_BTN1_Pin))         ? (1UL << 9) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(BASE_BTN2_GPIO_Port,         BASE_BTN2_Pin))         ? (1UL << 10) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(BASE_BTN3_GPIO_Port,         BASE_BTN3_Pin))         ? (1UL << 11) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(BASE_BTN4_GPIO_Port,         BASE_BTN4_Pin))         ? (1UL << 12) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(WHEEL_GEAR_L_GPIO_Port,      WHEEL_GEAR_L_Pin))      ? (1UL << 13) : 0;
    temp.buttons |= (!HAL_GPIO_ReadPin(WHEEL_GEAR_R_GPIO_Port,      WHEEL_GEAR_R_Pin))      ? (1UL << 14) : 0;

    // Read analog values
    temp.wheel = (uint16_t)__HAL_TIM_GET_COUNTER(&htim4);
    temp.throttle   = adc1_values[0];
    temp.brake      = adc1_values[1];
    temp.clutch     = adc1_values[2];
    temp.lh_x       = adc2_values[0];
    temp.lh_y       = adc2_values[1];
    temp.lh_slider  = adc2_values[2];
    temp.misko_x    = adc4_values[0];
    temp.misko_y    = adc4_values[1];

    *out = temp;
    g_latest_inputs = temp;
}

const RawInputs* Inputs_GetLatestSnapshot(void)
{
    return &g_latest_inputs;
}

/*=====================================================================*/
void Inputs_MapAxes(const RawInputs *raw, MappedAxes *mapped)
{
    if (!raw || !mapped)
        return;

    const uint16_t r[MAX_AXES] = {
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
        uint32_t raw_val = r[i];
        uint32_t min     = system_settings.axis_min[i];
        uint32_t max     = system_settings.axis_max[i];
        uint32_t range   = max - min;

        int32_t output;

        if (raw_val <= min)
            output = 0;
        else if (raw_val >= max)
            output = 65534;
        else if (range == 0)
            output = 0;
        else
            output = (int32_t)((uint64_t)(raw_val - min) * 65534ULL / range);

        if (system_settings.axis_deadzone[i] > 0) {
            uint16_t half_dz = (uint16_t)(system_settings.axis_deadzone[i] / 2);
            uint16_t dz_low  = (uint16_t)INT16_MAX - half_dz;
            uint16_t dz_high = (uint16_t)INT16_MAX + half_dz;
            if (output >= dz_low && output <= dz_high)
                output = INT16_MAX;
        }

        mapped->values[i] = (uint16_t)output;
    }
}
/*=====================================================================*/


void Inputs_BuildAndSendReport(const MappedAxes *mapped, uint16_t button_mask_16bit)
{
    hid1_rep.report_id = 4;
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

    const uint16_t v[MAX_AXES] = {
        raw.wheel, raw.throttle, raw.brake, raw.clutch,
        raw.lh_x, raw.lh_y, raw.lh_slider,
        raw.misko_x, raw.misko_y
    };

    char buf[400] = "Live values:\n";
    for (size_t i = 0; i < st->num_axes; i++) {
        uint32_t axis = st->axes_to_calibrate[i];
        uint16_t val = v[axis];

        if (val < (uint16_t)system_settings.axis_min[axis])
            system_settings.axis_min[axis] = val;
        if (val > (uint16_t)system_settings.axis_max[axis])
            system_settings.axis_max[axis] = val;

        char line[64];
        snprintf(line, sizeof(line), "A%d: %5d - %5d\n",
                 (int)axis, system_settings.axis_min[axis], system_settings.axis_max[axis]);
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
        system_settings.axis_min[a] = 65535;
        system_settings.axis_max[a] = 0;
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
