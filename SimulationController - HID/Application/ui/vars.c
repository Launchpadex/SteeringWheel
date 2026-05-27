
#include <stdio.h>
#include <stdlib.h>
#include "vars.h"
#include "InputCollection.h"
#include "screens.h"
#include "string.h"
#include "lvgl_lcd.h"
#include "flash_settings.h"
#include "ffb_pid.h"
#include "flash_settings.h"

static char calibration_status[30] = {0};
static char force_feedback_status[100] = { 0 };
char axis_min_max[250] = { 0 };

int32_t brightness;
char setting_value_str[20] = { 0 };


extern const RawInputs* Inputs_GetLatestSnapshot(void);

//Calibration_variables
static bool wheel_calib = false;
static bool pedals_calib = false;
static bool l_joy_calib = false;
static bool misko_joy_calib = false;
//Calibration_variables



#pragma region Sensor_Status
// =============================================================================
// ANALOG INPUTS – All now read from the atomic RawInputs snapshot
// =============================================================================
int32_t get_var_wheel(void)     { return Inputs_GetLatestMapped()->values[AXIS_WHEEL]; }
void    set_var_wheel(int32_t value) { }

int32_t get_var_throttle(void)  { return Inputs_GetLatestMapped()->values[AXIS_THROTTLE]; }
void    set_var_throttle(int32_t value) { }

int32_t get_var_brake(void)     { return Inputs_GetLatestMapped()->values[AXIS_BRAKE]; }
void    set_var_brake(int32_t value)    { }

int32_t get_var_clutch(void)    { return Inputs_GetLatestMapped()->values[AXIS_CLUTCH]; }
void    set_var_clutch(int32_t value)   { }

int32_t get_var_joy_x(void)     { return Inputs_GetLatestMapped()->values[AXIS_MISKO_X]; }
void    set_var_joy_x(int32_t value)    { }

int32_t get_var_joy_y(void)     { return Inputs_GetLatestMapped()->values[AXIS_MISKO_Y]; }
void    set_var_joy_y(int32_t value)    { }

int32_t get_var_lh_x(void)     { return Inputs_GetLatestMapped()->values[AXIS_LH_X]; }
void    set_var_lh_x(int32_t value)     { }

int32_t get_var_lh_y(void)     { return Inputs_GetLatestMapped()->values[AXIS_LH_Y]; }
void    set_var_lh_y(int32_t value)     { }

int32_t get_var_lh_r(void)     { return Inputs_GetLatestMapped()->values[AXIS_LH_SLIDER]; }
void    set_var_lh_r(int32_t value)     { }

int32_t get_var_ffb_force(void) {
    int32_t force = FFB_GetLastForce();
    return force > 0 ? force : 0;
}

int32_t get_var_ffb_force_start(void) {
    int32_t force = FFB_GetLastForce();
    return force < 0 ? -force : 0;
}

void    set_var_ffb_force(int32_t v)           { }
void    set_var_ffb_force_start(int32_t v)     { }

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
    strncpy(force_feedback_status, value, sizeof(force_feedback_status));
    force_feedback_status[sizeof(force_feedback_status) - 1] = '\0';
    lv_label_set_text(objects.force_feedback_status_main, force_feedback_status);
}

const char *get_var_force_feedback_status() {
    return force_feedback_status;
}

int32_t get_var_brightness() {
    return brightness;
}

void set_var_brightness(int32_t value) {
    brightness = value;
}

#pragma endregion

#pragma region Settings

static char settings_options[300] = { 0 };
static int32_t settings_selected  = 0;

const char *get_var_settings() { return settings_options; }
void set_var_settings(const char *value) {
    strncpy(settings_options, value, sizeof(settings_options));
    settings_options[sizeof(settings_options) - 1] = '\0';
}

int32_t get_var_settings_selected() { return settings_selected; }
void set_var_settings_selected(int32_t value) { settings_selected = value; }

const char *get_var_setting_value() { return setting_value_str; }
void set_var_setting_value(const char *value) {
    strncpy(setting_value_str, value, sizeof(setting_value_str));
    setting_value_str[sizeof(setting_value_str) - 1] = '\0';
}

#pragma endregion

#pragma region EEZ_Stubs
/* Declared in EEZ-generated vars.h but unused — stubs prevent linker errors on regeneration. */

bool get_var_fs25_click1(void)  { return false; } void set_var_fs25_click1(bool v)  { }
bool get_var_fs25_click2(void)  { return false; } void set_var_fs25_click2(bool v)  { }
bool get_var_fs25_click3(void)  { return false; } void set_var_fs25_click3(bool v)  { }
bool get_var_fs25_click4(void)  { return false; } void set_var_fs25_click4(bool v)  { }
bool get_var_fs25_click_back(void) { return false; } void set_var_fs25_click_back(bool v) { }

bool get_var_fs25_switch1(void) { return false; } void set_var_fs25_switch1(bool v) { }
bool get_var_fs25_switch2(void) { return false; } void set_var_fs25_switch2(bool v) { }
bool get_var_fs25_switch3(void) { return false; } void set_var_fs25_switch3(bool v) { }
bool get_var_fs25_switch4(void) { return false; } void set_var_fs25_switch4(bool v) { }

int32_t get_var_fs25_slider1(void) { return 0; } void set_var_fs25_slider1(int32_t v) { }
int32_t get_var_fs25_slider2(void) { return 0; } void set_var_fs25_slider2(int32_t v) { }
int32_t get_var_fs25_slider3(void) { return 0; } void set_var_fs25_slider3(int32_t v) { }
int32_t get_var_fs25_slider4(void) { return 0; } void set_var_fs25_slider4(int32_t v) { }

static char stub_str[1] = "";
const char *get_var_calibration_values(void)      { return stub_str; } void set_var_calibration_values(const char *v)      { }
const char *get_var_frequencies(void)             { return stub_str; } void set_var_frequencies(const char *v)             { }
int32_t     get_var_selected_frequency_position(void) { return 0;    } void set_var_selected_frequency_position(int32_t v) { }

#pragma endregion

