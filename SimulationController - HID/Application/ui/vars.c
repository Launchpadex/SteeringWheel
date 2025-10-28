
#include "vars.h"
#include "InputCollection.h"
#include "screens.h"
#include "string.h"
#include "lvgl_lcd.h"

static char calibration_status[30] = {0};
static char force_feedback_status[100] = { 0 };
char real_samling_frequency_hz[100] = { 0 };
char frequencies[100] = { 0 };
int32_t selected_frequency_position;
bool ffb_state;
int32_t brightness;

//Calibration_variables
static bool wheel_calib = false;
static bool pedals_calib = false;
static bool l_joy_calib = false;
static bool misko_joy_calib = false;
//Calibration_variables


#pragma region MainScreen
const char *get_var_real_samling_frequency_hz() {
    return real_samling_frequency_hz;
}
void set_var_real_samling_frequency_hz(const char *value) {
    strncpy(real_samling_frequency_hz, value, sizeof(real_samling_frequency_hz) / sizeof(char));
    real_samling_frequency_hz[sizeof(real_samling_frequency_hz) / sizeof(char) - 1] = 0;
}
#pragma endregion


#pragma region Sensor_Status
//ANALOG_INPUTS
int32_t get_var_wheel() { return Encoder_Value; }
void set_var_wheel(int32_t value) { Encoder_Value = value; }

int32_t get_var_throttle() { return adc1_values[0]; }
void set_var_throttle(int32_t value) { adc1_values[0] = value; }

int32_t get_var_brake() { return adc1_values[1]; }
void set_var_brake(int32_t value) { adc1_values[1] = value; }

int32_t get_var_clutch() { return adc1_values[2]; }
void set_var_clutch(int32_t value) { adc1_values[2] = value; }

int32_t get_var_joy_x() { return adc4_values[0]; }
void set_var_joy_x(int32_t value) { adc4_values[0] = value; }

int32_t get_var_joy_y() { return adc4_values[1]; }
void set_var_joy_y(int32_t value) { adc4_values[1] = value; }

int32_t get_var_lh_x() { return adc2_values[0]; }
void set_var_lh_x(int32_t value) { adc2_values[0] = value; }

int32_t get_var_lh_y() { return adc2_values[1]; }
void set_var_lh_y(int32_t value) { adc2_values[1] = value; }

int32_t get_var_lh_r() { return adc2_values[2]; }
void set_var_lh_r(int32_t value) { adc2_values[2] = value; }

//ANALOG_INPUTS
#pragma endregion

//BUTTON_INPUTS
bool get_var_btn_joy() { return Button_States[0]; }
void set_var_btn_joy(bool value) { Button_States[0] = value; }

bool get_var_btn_esc() { return Button_States[1]; }
void set_var_btn_esc(bool value) { Button_States[1] = value; }

bool get_var_btn_ok() { return Button_States[2]; }
void set_var_btn_ok(bool value) { Button_States[2] = value; }

bool get_var_btn_up() { return Button_States[3]; }
void set_var_btn_up(bool value) { Button_States[3] = value; }

bool get_var_btn_left() { return Button_States[4]; }
void set_var_btn_left(bool value) { Button_States[4] = value; }

bool get_var_btn_right() { return Button_States[5]; }
void set_var_btn_right(bool value) { Button_States[5] = value; }

bool get_var_btn_down() { return Button_States[6]; }
void set_var_btn_down(bool value) { Button_States[6] = value; }

bool get_var_lh_btn1() { return Button_States[7]; }
void set_var_lh_btn1(bool value) { Button_States[7] = value; }

bool get_var_lh_btn2() { return Button_States[8]; }
void set_var_lh_btn2(bool value) { Button_States[8] = value; }

bool get_var_base_btn1() { return Button_States[9]; }
void set_var_base_btn1(bool value) { Button_States[9] = value; }

bool get_var_base_btn2() { return Button_States[10]; }
void set_var_base_btn2(bool value) { Button_States[10] = value; }

bool get_var_base_btn3() { return Button_States[11]; }
void set_var_base_btn3(bool value) { Button_States[11] = value; }

bool get_var_base_btn4() { return Button_States[12]; }
void set_var_base_btn4(bool value) { Button_States[12] = value; }

bool get_var_shifter_l() { return Button_States[13]; }
void set_var_shifter_l(bool value) { Button_States[13] = value; }

bool get_var_shifter_r() { return Button_States[14]; }
void set_var_shifter_r(bool value) { Button_States[14] = value; }
//BUTTON_INPUTS
#pragma endregion



#pragma region Calibration

//DESIRED_CALIBRATION_OBJECTS
bool get_var_wheel_calib() { return wheel_calib; }
void set_var_wheel_calib(bool value) { wheel_calib = value; }

bool get_var_pedals_calib() { return pedals_calib; }
void set_var_pedals_calib(bool value) { pedals_calib = value; }

bool get_var_l_joy_calib() { return l_joy_calib; }
void set_var_l_joy_calib(bool value) { l_joy_calib = value; }

bool get_var_misko_joy_calib() { return misko_joy_calib; }
void set_var_misko_joy_calib(bool value) { misko_joy_calib = value; }
//DESIRED_CALIBRATION_OBJECTS

void set_var_calibration_status(const char *value) {
    strncpy(calibration_status, value, sizeof(calibration_status));
    calibration_status[sizeof(calibration_status) - 1] = '\0';
    lv_label_set_text(objects.calibration_status_calibration, calibration_status);
    lv_label_set_text(objects.calibration_status_main, calibration_status);
}

const char *get_var_calibration_status() {
    return calibration_status;
}
#pragma endregion

#pragma region Settings
void set_var_force_feedback_status(const char *value) {
    const char *state = (value && strcmp(value, "0") != 0) ? "FFB ON" : "FFB OFF";
    strncpy(force_feedback_status, state, sizeof(force_feedback_status));
    force_feedback_status[sizeof(force_feedback_status) - 1] = '\0';
    lv_label_set_text(objects.force_feedback_status_main, force_feedback_status);
}

const char *get_var_force_feedback_status() {
    return force_feedback_status;
}


const char *get_var_frequencies() {
    return frequencies;
}

void set_var_frequencies(const char *value) {
    strncpy(frequencies, value, sizeof(frequencies) / sizeof(char));
    frequencies[sizeof(frequencies) / sizeof(char) - 1] = 0;
}

int32_t get_var_selected_frequency_position() {
    return selected_frequency_position;
}

void set_var_selected_frequency_position(int32_t value) {
    selected_frequency_position = value;
}

bool get_var_ffb_state() {
    return ffb_state;
}

void set_var_ffb_state(bool value) {
    ffb_state = value;
}

int32_t get_var_brightness() {
    return brightness;
}

void set_var_brightness(int32_t value) {
    brightness = value;
}
#pragma endregion

