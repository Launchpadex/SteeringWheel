#include <stdio.h>
#include <string.h>
#include "inputCollection.h"
#include "FLASH_PAGE.h"
#include "SaveUserData.h"
#include "main.h"

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

// DMA buffers
uint16_t adc1_values[ADC1_BUFFERSIZE]; // Throttle, Brake, Clutch
uint16_t adc2_values[ADC2_BUFFERSIZE]; // Left-Hand X, Y, Slider
uint16_t adc4_values[ADC4_BUFFERSIZE]; // Misko X, Y

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

// Axis Calibration
void CalibrateAxis(const uint32_t* axis_ids, size_t num_axes) {
    uint16_t all_axis_values[MAX_AXES];

    // Set Encoder_Value as the first axis
    all_axis_values[0] = Encoder_Value;

    // Combine other arrays, starting at index 1
    memcpy(all_axis_values + 1, adc1_values, ADC1_BUFFERSIZE * sizeof(uint16_t));
    memcpy(all_axis_values + 1 + ADC1_BUFFERSIZE, adc2_values, ADC2_BUFFERSIZE * sizeof(uint16_t));
    memcpy(all_axis_values + 1 + ADC1_BUFFERSIZE + ADC2_BUFFERSIZE, adc4_values, ADC4_BUFFERSIZE * sizeof(uint16_t));

    // Calibrate each axis
    for (size_t i = 0; i < num_axes; i++) {
        uint32_t axis_id = axis_ids[i];
        // Ensure axis_id is valid
        if (axis_id < MAX_AXES) {
            system_settings.axis_min[axis_id] = DEFAULT_AXIS_MAX;
            system_settings.axis_max[axis_id] = DEFAULT_AXIS_MIN;

            // Update min and max based on the current value for the axis
            uint16_t current_value = all_axis_values[axis_id];
            if (current_value < system_settings.axis_min[axis_id]) {
                system_settings.axis_min[axis_id] = current_value;
            }
            if (current_value > system_settings.axis_max[axis_id]) {
                system_settings.axis_max[axis_id] = current_value;
            }
        }
    }
}

// Timer callback for calibration
static void calibration_timer_cb(lv_timer_t *timer) {
    // Retrieve CalibrationState using lv_timer_get_user_data
    CalibrationState *state = (CalibrationState *)lv_timer_get_user_data(timer);

    // Check if calibration is still ongoing
    if (state->current_axis_index < state->num_axes && state->is_calibrating) {
        // Calibrate one axis at a time
        CalibrateAxis(&state->axes_to_calibrate[state->current_axis_index], 1);
        state->current_axis_index++;

        // Update UI status
        char status[64];
        snprintf(status, sizeof(status), "Calibrating axis %u/%u",
                 (unsigned)state->current_axis_index + 1, (unsigned)state->num_axes);
        set_var_calibration_status(status);
    } else {
        // Calibration complete or stopped
        set_var_calibration_status(state->is_calibrating ? "Calibration complete" : "Calibration stopped");
        state->is_calibrating = false;
        lv_timer_del(state->timer); // Delete the timer
        state->timer = NULL;
        state->current_axis_index = 0; // Reset for next calibration
    }
}

// Start calibration process
void start_calibration(void) {
    // Prevent starting a new calibration if one is already in progress
    if (calib_state.is_calibrating) {
        set_var_calibration_status("Calibration already in progress");
        return;
    }

    // Initialize calibration state
    calib_state.num_axes = 0;
    calib_state.current_axis_index = 0;
    calib_state.is_calibrating = true;

    // Conditionally append axes to calibrate
    if (get_var_wheel_calib()) {
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 0; // Wheel - Encoder_Value
    }
    if (get_var_pedals_calib()) {
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 1; // Throttle
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 2; // Brake
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 3; // Clutch
    }
    if (get_var_l_joy_calib()) {
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 4; // LH_X
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 5; // LH_Y
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 6; // LH_SLIDER
    }
    if (get_var_misko_joy_calib()) {
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 7; // MISKO_X
        calib_state.axes_to_calibrate[calib_state.num_axes++] = 8; // MISKO_Y
    }

    // Start calibration if there are axes to calibrate
    if (calib_state.num_axes > 0) {
        // Create a timer to handle calibration iteratively
        calib_state.timer = lv_timer_create(calibration_timer_cb, 100, &calib_state); // 100ms interval
        set_var_calibration_status("Calibration started");
    } else {
        set_var_calibration_status("No axes selected for calibration");
        calib_state.is_calibrating = false;
    }
}

// Stop calibration process
void stop_calibration(void) {
    if (calib_state.is_calibrating) {
        calib_state.is_calibrating = false; // Signal to stop calibration
    }
}
