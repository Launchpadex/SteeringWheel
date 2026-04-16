/*
 * vars.cpp
 *
 * All UI variable state is now stored in EEZ Flow's global variable table.
 * Use setGlobalVariable / getGlobalVariable instead of static C buffers.
 *
 * All public functions preserve the same C signature so that callers in
 * InputCollection.c, actions.c and lvgl_lcd.c need no changes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eez-flow.h"
#include "vars.h"
#include "screens.h"
#include "lvgl_lcd.h"
#include "flash_settings.h"

using namespace eez;
using namespace eez::flow;

/* -----------------------------------------------------------------------
 * setting_value – still a plain C int so actions.c can access it via
 * "extern int32_t setting_value".  It is synced to Flow by every write.
 * --------------------------------------------------------------------- */
int32_t setting_value = 0;
int32_t deadzone      = 0;


/* =======================================================================
 * SENSOR AXES  (pushed by sensor_flow_update.cpp – no getters needed)
 * ===================================================================== */

/* Kept as empty stubs in case any legacy code still references them */
int32_t get_var_wheel(void)     { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_WHEEL).getInt32(); }
void    set_var_wheel(int32_t)  {}

int32_t get_var_throttle(void)  { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_THROTTLE).getInt32(); }
void    set_var_throttle(int32_t) {}

int32_t get_var_brake(void)     { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_BRAKE).getInt32(); }
void    set_var_brake(int32_t)  {}

int32_t get_var_clutch(void)    { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_CLUTCH).getInt32(); }
void    set_var_clutch(int32_t) {}

int32_t get_var_joy_x(void)     { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_JOY_X).getInt32(); }
void    set_var_joy_x(int32_t)  {}

int32_t get_var_joy_y(void)     { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_JOY_Y).getInt32(); }
void    set_var_joy_y(int32_t)  {}

int32_t get_var_lh_x(void)      { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_LH_X).getInt32(); }
void    set_var_lh_x(int32_t)   {}

int32_t get_var_lh_y(void)      { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_LH_Y).getInt32(); }
void    set_var_lh_y(int32_t)   {}

int32_t get_var_lh_r(void)      { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_LH_R).getInt32(); }
void    set_var_lh_r(int32_t)   {}


/* =======================================================================
 * BUTTON INPUTS  (also pushed by sensor_flow_update.cpp)
 * ===================================================================== */

static inline bool btn_from_flow(int varIdx) {
    return getGlobalVariable(varIdx).getBoolean();
}

bool get_var_btn_joy(void)    { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BTN_JOY); }
void set_var_btn_joy(bool v)  { setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_JOY,  BooleanValue(v)); }

bool get_var_btn_esc(void)    { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BTN_ESC); }
void set_var_btn_esc(bool v)  { setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_ESC,  BooleanValue(v)); }

bool get_var_btn_ok(void)     { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BTN_OK); }
void set_var_btn_ok(bool v)   { setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_OK,   BooleanValue(v)); }

bool get_var_btn_up(void)     { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BTN_UP); }
void set_var_btn_up(bool v)   { setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_UP,   BooleanValue(v)); }

bool get_var_btn_left(void)   { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BTN_LEFT); }
void set_var_btn_left(bool v) { setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_LEFT, BooleanValue(v)); }

bool get_var_btn_right(void)  { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BTN_RIGHT); }
void set_var_btn_right(bool v){ setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_RIGHT,BooleanValue(v)); }

bool get_var_btn_down(void)   { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BTN_DOWN); }
void set_var_btn_down(bool v) { setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_DOWN, BooleanValue(v)); }

bool get_var_lh_btn1(void)    { return btn_from_flow(FLOW_GLOBAL_VARIABLE_LH_BTN1); }
void set_var_lh_btn1(bool v)  { setGlobalVariable(FLOW_GLOBAL_VARIABLE_LH_BTN1,  BooleanValue(v)); }

bool get_var_lh_btn2(void)    { return btn_from_flow(FLOW_GLOBAL_VARIABLE_LH_BTN2); }
void set_var_lh_btn2(bool v)  { setGlobalVariable(FLOW_GLOBAL_VARIABLE_LH_BTN2,  BooleanValue(v)); }

bool get_var_base_btn1(void)  { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BASE_BTN1); }
void set_var_base_btn1(bool v){ setGlobalVariable(FLOW_GLOBAL_VARIABLE_BASE_BTN1,BooleanValue(v)); }

bool get_var_base_btn2(void)  { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BASE_BTN2); }
void set_var_base_btn2(bool v){ setGlobalVariable(FLOW_GLOBAL_VARIABLE_BASE_BTN2,BooleanValue(v)); }

bool get_var_base_btn3(void)  { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BASE_BTN3); }
void set_var_base_btn3(bool v){ setGlobalVariable(FLOW_GLOBAL_VARIABLE_BASE_BTN3,BooleanValue(v)); }

bool get_var_base_btn4(void)  { return btn_from_flow(FLOW_GLOBAL_VARIABLE_BASE_BTN4); }
void set_var_base_btn4(bool v){ setGlobalVariable(FLOW_GLOBAL_VARIABLE_BASE_BTN4,BooleanValue(v)); }

bool get_var_shifter_l(void)  { return btn_from_flow(FLOW_GLOBAL_VARIABLE_SHIFTER_L); }
void set_var_shifter_l(bool v){ setGlobalVariable(FLOW_GLOBAL_VARIABLE_SHIFTER_L,BooleanValue(v)); }

bool get_var_shifter_r(void)  { return btn_from_flow(FLOW_GLOBAL_VARIABLE_SHIFTER_R); }
void set_var_shifter_r(bool v){ setGlobalVariable(FLOW_GLOBAL_VARIABLE_SHIFTER_R,BooleanValue(v)); }


/* =======================================================================
 * CALIBRATION CHECKBOXES
 * ===================================================================== */

bool get_var_wheel_calib(void)        { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_WHEEL_CALIB).getBoolean(); }
void set_var_wheel_calib(bool v)      { setGlobalVariable(FLOW_GLOBAL_VARIABLE_WHEEL_CALIB,      BooleanValue(v)); }

bool get_var_pedals_calib(void)       { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_PEDALS_CALIB).getBoolean(); }
void set_var_pedals_calib(bool v)     { setGlobalVariable(FLOW_GLOBAL_VARIABLE_PEDALS_CALIB,     BooleanValue(v)); }

bool get_var_l_joy_calib(void)        { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_L_JOY_CALIB).getBoolean(); }
void set_var_l_joy_calib(bool v)      { setGlobalVariable(FLOW_GLOBAL_VARIABLE_L_JOY_CALIB,      BooleanValue(v)); }

bool get_var_misko_joy_calib(void)    { return getGlobalVariable(FLOW_GLOBAL_VARIABLE_MISKO_JOY_CALIB).getBoolean(); }
void set_var_misko_joy_calib(bool v)  { setGlobalVariable(FLOW_GLOBAL_VARIABLE_MISKO_JOY_CALIB,  BooleanValue(v)); }


/* =======================================================================
 * CALIBRATION STATUS / AXIS MIN-MAX TEXT
 * ===================================================================== */

void set_var_calibration_status(const char *value) {
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_CALIBRATION_STATUS, StringValue(value));
}
const char *get_var_calibration_status(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_CALIBRATION_STATUS).getString();
}

void set_var_axis_min_max(const char *value) {
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_AXIS_MIN_MAX, StringValue(value));
}
const char *get_var_axis_min_max(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_AXIS_MIN_MAX).getString();
}


/* =======================================================================
 * MAIN SCREEN
 * ===================================================================== */

void set_var_real_samling_frequency_hz(const char *value) {
    /* Not in the FlowGlobalVariables enum — update label directly if needed */
    (void)value;
}
const char *get_var_real_samling_frequency_hz(void) { return ""; }


/* =======================================================================
 * FORCE FEEDBACK STATUS
 * ===================================================================== */

void set_var_force_feedback_status(const char *value) {
    const char *state = (value && strcmp(value, "0") != 0) ? "FFB ON" : "FFB OFF";
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_FORCE_FEEDBACK_STATUS, StringValue(state));
}
const char *get_var_force_feedback_status(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_FORCE_FEEDBACK_STATUS).getString();
}


/* =======================================================================
 * SETTINGS SCREEN
 * ===================================================================== */

const char *get_var_frequencies(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_FREQUENCIES).getString();
}
void set_var_frequencies(const char *value) {
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_FREQUENCIES, StringValue(value));
}

int32_t get_var_selected_frequency_position(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_SELECTED_FREQUENCY_POSITION).getInt32();
}
void set_var_selected_frequency_position(int32_t value) {
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_SELECTED_FREQUENCY_POSITION, IntegerValue(value));
}

int32_t get_var_ffb_state(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_FFB_STATE).getInt32();
}
void set_var_ffb_state(int32_t value) {
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_FFB_STATE, IntegerValue(value));
}

int32_t get_var_brightness(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_BRIGHTNESS).getInt32();
}
void set_var_brightness(int32_t value) {
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BRIGHTNESS, IntegerValue(value));
}

int32_t get_var_deadzone(void) {
    deadzone = getGlobalVariable(FLOW_GLOBAL_VARIABLE_DEADZONE).getInt32();
    return deadzone;
}
void set_var_deadzone(int32_t value) {
    deadzone = value;
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_DEADZONE, IntegerValue(value));
}

const char *get_var_deadzone_char(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_DEADZONE_CHAR).getString();
}
void set_var_deadzone_char(const char *value) {
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_DEADZONE_CHAR, StringValue(value));
}


/* =======================================================================
 * FFB SETTINGS SCREEN
 * ===================================================================== */

const char *get_var_ffb_settings(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_FFB_SETTINGS).getString();
}
void set_var_ffb_settings(const char *value) {
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_FFB_SETTINGS, StringValue(value));
}

/* setting_value is also kept as a plain int so actions.c can do arithmetic on it */
const char *get_var_setting_value(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_SETTING_VALUE).getString();
}
void set_var_setting_value(const char *value) {
    setting_value = (int32_t)atoi(value);
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_SETTING_VALUE, StringValue(value));
}

int32_t get_var_ffb_settings_selected(void) {
    return getGlobalVariable(FLOW_GLOBAL_VARIABLE_FFB_SETTINGS_SELECTED).getInt32();
}
void set_var_ffb_settings_selected(int32_t value) {
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_FFB_SETTINGS_SELECTED, IntegerValue(value));
}
