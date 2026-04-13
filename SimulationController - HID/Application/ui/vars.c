
#include <stdio.h>
#include <stdlib.h>
#include "vars.h"
#include "InputCollection.h"
#include "screens.h"
#include "string.h"
#include "lvgl_lcd.h"
#include "flash_settings.h"

static char calibration_status[30] = {0};
static char force_feedback_status[100] = { 0 };
char real_samling_frequency_hz[100] = { 0 };
char frequencies[100] = { 0 };
char axis_min_max[250] = { 0 };
char deadzone_char[10] = { 0 };
char ffb_settings[300] = { 0 };

int32_t selected_frequency_position;
bool ffb_state;
int32_t brightness;
int32_t deadzone;
int32_t setting_value;
int32_t ffb_settings_selected;
char setting_value_str[20] = { 0 };


extern const RawInputs* Inputs_GetLatestSnapshot(void);

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
// =============================================================================
// ANALOG INPUTS – All now read from the atomic RawInputs snapshot
// =============================================================================
int32_t get_var_wheel(void)     { return Inputs_GetLatestSnapshot()->wheel; }
void    set_var_wheel(int32_t value) { /* not used by hardware – keep empty or remove setter in EEZ */ }

int32_t get_var_throttle(void)  { return Inputs_GetLatestSnapshot()->throttle; }
void    set_var_throttle(int32_t value) { /* no direct write allowed */ }

int32_t get_var_brake(void)     { return Inputs_GetLatestSnapshot()->brake; }
void    set_var_brake(int32_t value)    { /* no direct write allowed */ }

int32_t get_var_clutch(void)    { return Inputs_GetLatestSnapshot()->clutch; }
void    set_var_clutch(int32_t value)   { /* no direct write allowed */ }

int32_t get_var_joy_x(void)     { return Inputs_GetLatestSnapshot()->misko_x; }   // Misko joystick X
void    set_var_joy_x(int32_t value)    { /* no direct write */ }

int32_t get_var_joy_y(void)     { return Inputs_GetLatestSnapshot()->misko_y; }   // Misko joystick Y
void    set_var_joy_y(int32_t value)    { /* no direct write */ }

int32_t get_var_lh_x(void)       { return Inputs_GetLatestSnapshot()->lh_x; }
void    set_var_lh_x(int32_t value)     { /* no direct write */ }

int32_t get_var_lh_y(void)      { return Inputs_GetLatestSnapshot()->lh_y; }
void    set_var_lh_y(int32_t value)     { /* no direct write */ }

int32_t get_var_lh_r(void)      { return Inputs_GetLatestSnapshot()->lh_slider; }  // Slider = rotary on left hand
void    set_var_lh_r(int32_t value)     { /* no direct write */ }

// =============================================================================
// END OF ANALOG INPUTS
// =============================================================================
#pragma endregion



#pragma region BUTTON_INPUTS
// =============================================================================
// DIGITAL BUTTONS – Also from the same atomic snapshot
// =============================================================================

static inline bool button_bit(uint16_t buttons, uint8_t bit)
{
    return (buttons >> bit) & 1U;
}

bool get_var_btn_joy(void)     { return button_bit(Inputs_GetLatestSnapshot()->buttons, 0); }
void set_var_btn_joy(bool value)     { /* no write from UI */ }

bool get_var_btn_esc(void)     { return button_bit(Inputs_GetLatestSnapshot()->buttons, 1); }
void set_var_btn_esc(bool value)     { /* no write */ }

bool get_var_btn_ok(void)      { return button_bit(Inputs_GetLatestSnapshot()->buttons, 2); }
void set_var_btn_ok(bool value)      { /* no write */ }

bool get_var_btn_up(void)      { return button_bit(Inputs_GetLatestSnapshot()->buttons, 3); }
void set_var_btn_up(bool value)      { /* no write */ }

bool get_var_btn_left(void)    { return button_bit(Inputs_GetLatestSnapshot()->buttons, 4); }
void set_var_btn_left(bool value)    { /* no write */ }

bool get_var_btn_right(void)   { return button_bit(Inputs_GetLatestSnapshot()->buttons, 5); }
void set_var_btn_right(bool value)   { /* no write */ }

bool get_var_btn_down(void)     { return button_bit(Inputs_GetLatestSnapshot()->buttons, 6); }
void set_var_btn_down(bool value)    { /* no write */ }

bool get_var_lh_btn1(void)     { return button_bit(Inputs_GetLatestSnapshot()->buttons, 7); }
void set_var_lh_btn1(bool value)     { /* no write */ }

bool get_var_lh_btn2(void)     { return button_bit(Inputs_GetLatestSnapshot()->buttons, 8); }
void set_var_lh_btn2(bool value)     { /* no write */ }

bool get_var_base_btn1(void)   { return button_bit(Inputs_GetLatestSnapshot()->buttons, 9); }
void set_var_base_btn1(bool value)   { /* no write */ }

bool get_var_base_btn2(void)   { return button_bit(Inputs_GetLatestSnapshot()->buttons, 10); }
void set_var_base_btn2(bool value)   { /* no write */ }

bool get_var_base_btn3(void)   { return button_bit(Inputs_GetLatestSnapshot()->buttons, 11); }
void set_var_base_btn3(bool value)   { /* no write */ }

bool get_var_base_btn4(void)   { return button_bit(Inputs_GetLatestSnapshot()->buttons, 12); }
void set_var_base_btn4(bool value)   { /* no write */ }

bool get_var_shifter_l(void)   { return button_bit(Inputs_GetLatestSnapshot()->buttons, 13); }
void set_var_shifter_l(bool value)   { /* no write */ }

bool get_var_shifter_r(void)   { return button_bit(Inputs_GetLatestSnapshot()->buttons, 14); }
void set_var_shifter_r(bool value)   { /* no write */ }

// =============================================================================
// END OF BUTTON INPUTS
// =============================================================================
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

#pragma region Calibration_Indication

const char *get_var_axis_min_max() {
    return axis_min_max;
}

void set_var_axis_min_max(const char *value) {
    strncpy(axis_min_max, value, sizeof(axis_min_max) / sizeof(char));
    axis_min_max[sizeof(axis_min_max) / sizeof(char) - 1] = 0;
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

int32_t get_var_ffb_state() {
    return ffb_state;
}

void set_var_ffb_state(int32_t value) {
    ffb_state = value;
}

int32_t get_var_brightness() {
    return brightness;
}

void set_var_brightness(int32_t value) {
    brightness = value;
}

int32_t get_var_deadzone(){
	return deadzone;
}

void set_var_deadzone(int32_t value){
	deadzone = value;
}

const char *get_var_deadzone_char(){
	return deadzone_char;
}

void set_var_deadzone_char(const char *value) {
    strncpy(deadzone_char, value, sizeof(deadzone_char) / sizeof(char));
    deadzone_char[sizeof(deadzone_char) / sizeof(char) - 1] = 0;
}

#pragma endregion

#pragma region FFB_Settings

const char *get_var_ffb_settings() {
    return ffb_settings;
}
void set_var_ffb_settings(const char *value) {
    strncpy(ffb_settings, value, sizeof(ffb_settings) / sizeof(char));
    ffb_settings[sizeof(ffb_settings) / sizeof(char) - 1] = 0;
}


const char *get_var_setting_value() {
    return setting_value_str;
}
void set_var_setting_value(const char *value) {
    int32_t parsed = atoi(value);
    if (parsed < 0) {
        parsed = 0;
    }
    setting_value = parsed;
    strncpy(setting_value_str, value, sizeof(setting_value_str));
    setting_value_str[sizeof(setting_value_str) / sizeof(char) - 1] = 0;
}



int32_t get_var_ffb_settings_selected() {
    return ffb_settings_selected;
}
void set_var_ffb_settings_selected(int32_t value) {
    ffb_settings_selected = value;
}

#pragma endregion

