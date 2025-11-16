#include <stdio.h>
#include <string.h>
#include "inputCollection.h"
#include "FLASH_PAGE.h"
#include "SaveUserData.h"
#include "main.h"
#include "usbd_custom_hid_if.h"

// Define variables
int16_t Button_States[NUMBER_OF_BUTTONS];
uint16_t Encoder_Value;

// Define global variables
static CalibrationState calib_state;

// handles
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim2;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern ADC_HandleTypeDef hadc4;

extern SystemSettings system_settings;

extern USBD_HandleTypeDef hUsbDeviceFS;

// DMA buffers
uint16_t adc1_values[ADC1_BUFFERSIZE]; // Throttle, Brake, Clutch
uint16_t adc2_values[ADC2_BUFFERSIZE]; // Left-Hand X, Y, Slider
uint16_t adc4_values[ADC4_BUFFERSIZE]; // Misko X, Y

uint16_t mapped_values[MAX_AXES];

char sampling_frequency_str[32];

// Sampling frequency
void Set_Sampling_Frequency(int32_t frequency_hz) {
    if (frequency_hz < 10) {
        frequency_hz = 10;
    } else if (frequency_hz > 1000) {
        frequency_hz = 1000;
    }
    int32_t arr = (100000 / frequency_hz) - 1;
    __HAL_TIM_SET_AUTORELOAD(&htim2, arr);
}


void Read_Actual_Sampling_Frequency(uint32_t cycle_count_delta, char* output_str, size_t str_size) {
    static const uint32_t CPU_FREQ_HZ = 170000000; // CPU frequency (170 MHz)
    int real_sampling_frequency_hz; // Changed to int

    if (cycle_count_delta != 0) // Prevent division by zero
    {
        real_sampling_frequency_hz = CPU_FREQ_HZ / cycle_count_delta; // Integer division
    }
    else
    {
        real_sampling_frequency_hz = 0; // Handle edge case
    }

    // Convert int to string
    snprintf(output_str, str_size, "%d Hz", real_sampling_frequency_hz); // Format as integer
}

// Initialize ADCs
void InitADC(void) {
  // Calibrate ADCs
  HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
  HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
  HAL_ADCEx_Calibration_Start(&hadc4, ADC_SINGLE_ENDED);
}

// Collect button states
void CollectButton_StatesMisko(int16_t states[]) {
  states[0] = !HAL_GPIO_ReadPin(MiskoJOY_BTN_GPIO_Port, MiskoJOY_BTN_Pin);
  states[1] = !HAL_GPIO_ReadPin(BTN_ESC_GPIO_Port, BTN_ESC_Pin);
  states[2] = !HAL_GPIO_ReadPin(BTN_OK_GPIO_Port, BTN_OK_Pin);
  states[3] = !HAL_GPIO_ReadPin(BTN_UP_GPIO_Port, BTN_UP_Pin);
  states[4] = !HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port, BTN_LEFT_Pin);
  states[5] = !HAL_GPIO_ReadPin(BTN_RIGHT_GPIO_Port, BTN_RIGHT_Pin);
  states[6] = !HAL_GPIO_ReadPin(BTN_DOWN_GPIO_Port, BTN_DOWN_Pin);
  states[7] = !HAL_GPIO_ReadPin(LEFT_HAND_JOY_BTN1_GPIO_Port, LEFT_HAND_JOY_BTN1_Pin);
  states[8] = !HAL_GPIO_ReadPin(LEFT_HAND_JOY_BTN2_GPIO_Port, LEFT_HAND_JOY_BTN2_Pin);
  states[9] = !HAL_GPIO_ReadPin(BASE_BTN1_GPIO_Port, BASE_BTN1_Pin);
  states[10] = !HAL_GPIO_ReadPin(BASE_BTN2_GPIO_Port, BASE_BTN2_Pin);
  states[11] = !HAL_GPIO_ReadPin(BASE_BTN3_GPIO_Port, BASE_BTN3_Pin);
  states[12] = !HAL_GPIO_ReadPin(BASE_BTN4_GPIO_Port, BASE_BTN4_Pin);
  states[13] = !HAL_GPIO_ReadPin(WHEEL_GEAR_L_GPIO_Port, WHEEL_GEAR_L_Pin);
  states[14] = !HAL_GPIO_ReadPin(WHEEL_GEAR_R_GPIO_Port, WHEEL_GEAR_R_Pin);

}

// Collect encoder value
void CollectEncoderValue(uint16_t *encoder_value) {
  *encoder_value = (uint16_t)__HAL_TIM_GET_COUNTER(&htim4);
}

// Collect all inputs
void CollectAllInputs(void) {
  // Collect button states
  CollectButton_StatesMisko(Button_States);

  // Collect encoder value
  CollectEncoderValue(&Encoder_Value);
}


//Function that maps values to 16bit value
void MapAxis(uint16_t* output_mapped_values){
    uint16_t all_axis_values[MAX_AXES];

    // Axis 0: Encoder (wheel)
    all_axis_values[0] = Encoder_Value;

    // Copy ADC buffers (assuming they are up-to-date)
    memcpy(all_axis_values + 1, adc1_values, ADC1_BUFFERSIZE * sizeof(uint16_t));
    memcpy(all_axis_values + 1 + ADC1_BUFFERSIZE, adc2_values, ADC2_BUFFERSIZE * sizeof(uint16_t));
    memcpy(all_axis_values + 1 + ADC1_BUFFERSIZE + ADC2_BUFFERSIZE, adc4_values, ADC4_BUFFERSIZE * sizeof(uint16_t));

    for(size_t i = 0; i < MAX_AXES; i++){
    	uint16_t raw = all_axis_values[i];
    	uint16_t min_val = system_settings.axis_min[i];
    	uint16_t max_val = system_settings.axis_max[i];

    	if(raw <= min_val){
    		output_mapped_values[i] = 0;
    	}
    	else if(raw >= max_val){
    		output_mapped_values[i] = UINT16_MAX;
    	}
    	else {
    		uint16_t range = max_val - min_val;
    		if(range == 0){
    			output_mapped_values[i] = 0;
    		}
    		uint32_t numerator = (raw - min_val) * UINT16_MAX;
    		output_mapped_values[i] = numerator / range;
    	}
    }
}


void Send_to_HID(void)
{
    // 1. Map raw values to 0..65535
    MapAxis(mapped_values);

    // 2. Build 1-byte-per-button + 2-byte-per-axis report
    uint8_t report[NUMBER_OF_BUTTONS + MAX_AXES*2] = {0};

    // Pack buttons (1 byte each, 0=off, 1=on)
    for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
        report[i] = Button_States[i] ? 1 : 0;

    // Pack axes (little-endian 16-bit)
    for (int i = 0; i < MAX_AXES; i++) {
        report[NUMBER_OF_BUTTONS + i*2 + 0] = mapped_values[i] & 0xFF;
        report[NUMBER_OF_BUTTONS + i*2 + 1] = mapped_values[i] >> 8;
    }

    // 3. Send (replace with your HID send function)
    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, sizeof(report));
}


// Timer callback for calibration - runs continuously until stopped
static void calibration_timer_cb(lv_timer_t *timer) {
    CalibrationState *state = (CalibrationState *)lv_timer_get_user_data(timer);
    char min_max_values[250];

    // Stop if calibration was canceled
    if (!state->is_calibrating) {
        set_var_calibration_status("Calibration stopped");
        lv_timer_del(state->timer);
        state->timer = NULL;
        state->current_axis_index = 0;
        return;
    }

    // Only proceed if we have axes to calibrate
    if (state->num_axes == 0) {
        set_var_calibration_status("No axes selected");
        state->is_calibrating = false;
        lv_timer_del(state->timer);
        state->timer = NULL;
        return;
    }

    // === STEP 1: Build fresh all_axis_values array from current ADC/encoder readings ===
    uint16_t all_axis_values[MAX_AXES];

    // Axis 0: Encoder (wheel)
    all_axis_values[0] = Encoder_Value;

    // Copy ADC buffers (assuming they are up-to-date)
    memcpy(all_axis_values + 1, adc1_values, ADC1_BUFFERSIZE * sizeof(uint16_t));
    memcpy(all_axis_values + 1 + ADC1_BUFFERSIZE, adc2_values, ADC2_BUFFERSIZE * sizeof(uint16_t));
    memcpy(all_axis_values + 1 + ADC1_BUFFERSIZE + ADC2_BUFFERSIZE, adc4_values, ADC4_BUFFERSIZE * sizeof(uint16_t));

    // === STEP 2: Update min/max for ALL axes to calibrate (in a loop) ===
    for (size_t i = 0; i < state->num_axes; i++) {
        uint32_t axis_id = state->axes_to_calibrate[i];

        if (axis_id >= MAX_AXES) continue;

        uint16_t current_value = all_axis_values[axis_id];

        // Initialize min/max on first run for this axis
        //if (state->current_axis_index == 0 && i == 0) {  // First tick ever
        //    system_settings.axis_min[axis_id] = current_value;
        //    system_settings.axis_max[axis_id] = current_value;
        //}

        // Update min/max
        if (current_value < system_settings.axis_min[axis_id]) {
            system_settings.axis_min[axis_id] = current_value;
        }
        if (current_value > system_settings.axis_max[axis_id]) {
            system_settings.axis_max[axis_id] = current_value;
        }

        // min and max textbox display
        char line[100];
                snprintf(line, sizeof(line),
                         "axis %lu: %ld, %ld\n",
                         (unsigned long)(axis_id),
                         (long)system_settings.axis_min[axis_id],
                         (long)system_settings.axis_max[axis_id]);

                strncat(min_max_values, line,
                        sizeof(min_max_values) - strlen(min_max_values) - 1);
    }

    // === STEP 3: Update UI (optional: show progress or live values) ===
    static uint32_t tick_count = 0;
    tick_count++;

    char status[64];
    snprintf(status, sizeof(status), "Calibrating... (%lu samples)", (unsigned long)tick_count);
    set_var_calibration_status(status);

    set_var_axis_min_max(min_max_values);


    // Reset index (we now loop forever)
    //state->current_axis_index = 0;
}

void start_calibration(void) {
    if (calib_state.is_calibrating) {
        set_var_calibration_status("Calibration already in progress");
        return;
    }

    calib_state.num_axes = 0;
    calib_state.current_axis_index = 0;
    calib_state.is_calibrating = true;

    // === Collect axes ===
    if (get_var_wheel_calib()) {
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 0;
    }
    if (get_var_pedals_calib()) {
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 1;
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 2;
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 3;
    }
    if (get_var_l_joy_calib()) {
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 4;
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 5;
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 6;
    }
    if (get_var_misko_joy_calib()) {
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 7;
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 8;
    }

    if (calib_state.num_axes == 0) {
        set_var_calibration_status("No axes selected for calibration");
        calib_state.is_calibrating = false;
        return;
    }

    // === RESET min/max for all axes to be calibrated ===
    for (size_t i = 0; i < calib_state.num_axes; i++) {
        uint32_t axis_id = calib_state.axes_to_calibrate[i];
        if (axis_id < MAX_AXES) {
            system_settings.axis_min[axis_id] = UINT16_MAX;
            system_settings.axis_max[axis_id] = 0;
        }
    }

    // Start timer
    calib_state.timer = lv_timer_create(calibration_timer_cb, 50, &calib_state); // 50ms = 20Hz sampling
    set_var_calibration_status("Calibration started - Move all controls!");
}

void stop_calibration(void) {
    if (!calib_state.is_calibrating || calib_state.timer == NULL) {
        return;
    }

    calib_state.is_calibrating = false;

    // Timer will clean itself up in next callback
    // But force delete to be safe
    lv_timer_del(calib_state.timer);
    calib_state.timer = NULL;

    set_var_calibration_status("Calibration complete");
}
