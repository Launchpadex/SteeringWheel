#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_WHEEL = 0,
    FLOW_GLOBAL_VARIABLE_THROTTLE = 1,
    FLOW_GLOBAL_VARIABLE_BRAKE = 2,
    FLOW_GLOBAL_VARIABLE_CLUTCH = 3,
    FLOW_GLOBAL_VARIABLE_JOY_X = 4,
    FLOW_GLOBAL_VARIABLE_JOY_Y = 5,
    FLOW_GLOBAL_VARIABLE_LH_X = 6,
    FLOW_GLOBAL_VARIABLE_LH_Y = 7,
    FLOW_GLOBAL_VARIABLE_LH_R = 8,
    FLOW_GLOBAL_VARIABLE_FS25_CLICK1 = 9,
    FLOW_GLOBAL_VARIABLE_FS25_CLICK2 = 10,
    FLOW_GLOBAL_VARIABLE_FS25_CLICK3 = 11,
    FLOW_GLOBAL_VARIABLE_FS25_CLICK4 = 12,
    FLOW_GLOBAL_VARIABLE_FS25_SWITCH1 = 13,
    FLOW_GLOBAL_VARIABLE_FS25_SWITCH2 = 14,
    FLOW_GLOBAL_VARIABLE_FS25_SWITCH3 = 15,
    FLOW_GLOBAL_VARIABLE_FS25_SWITCH4 = 16,
    FLOW_GLOBAL_VARIABLE_FS25_SLIDER1 = 17,
    FLOW_GLOBAL_VARIABLE_FS25_SLIDER2 = 18,
    FLOW_GLOBAL_VARIABLE_FS25_SLIDER3 = 19,
    FLOW_GLOBAL_VARIABLE_FS25_SLIDER4 = 20,
    FLOW_GLOBAL_VARIABLE_FS25_CLICK_BACK = 21,
    FLOW_GLOBAL_VARIABLE_CALIBRATION_STATUS = 22,
    FLOW_GLOBAL_VARIABLE_CALIBRATION_VALUES = 23,
    FLOW_GLOBAL_VARIABLE_BTN_JOY = 24,
    FLOW_GLOBAL_VARIABLE_BTN_ESC = 25,
    FLOW_GLOBAL_VARIABLE_BTN_OK = 26,
    FLOW_GLOBAL_VARIABLE_BTN_UP = 27,
    FLOW_GLOBAL_VARIABLE_BTN_LEFT = 28,
    FLOW_GLOBAL_VARIABLE_BTN_RIGHT = 29,
    FLOW_GLOBAL_VARIABLE_BTN_DOWN = 30,
    FLOW_GLOBAL_VARIABLE_LH_BTN1 = 31,
    FLOW_GLOBAL_VARIABLE_LH_BTN2 = 32,
    FLOW_GLOBAL_VARIABLE_BASE_BTN1 = 33,
    FLOW_GLOBAL_VARIABLE_BASE_BTN2 = 34,
    FLOW_GLOBAL_VARIABLE_BASE_BTN3 = 35,
    FLOW_GLOBAL_VARIABLE_BASE_BTN4 = 36,
    FLOW_GLOBAL_VARIABLE_SHIFTER_L = 37,
    FLOW_GLOBAL_VARIABLE_SHIFTER_R = 38,
    FLOW_GLOBAL_VARIABLE_FORCE_FEEDBACK_STATUS = 39,
    FLOW_GLOBAL_VARIABLE_WHEEL_CALIB = 40,
    FLOW_GLOBAL_VARIABLE_PEDALS_CALIB = 41,
    FLOW_GLOBAL_VARIABLE_L_JOY_CALIB = 42,
    FLOW_GLOBAL_VARIABLE_MISKO_JOY_CALIB = 43,
    FLOW_GLOBAL_VARIABLE_REAL_SAMLING_FREQUENCY_HZ = 44,
    FLOW_GLOBAL_VARIABLE_FREQUENCIES = 45,
    FLOW_GLOBAL_VARIABLE_SELECTED_FREQUENCY_POSITION = 46,
    FLOW_GLOBAL_VARIABLE_FFB_STATE = 47,
    FLOW_GLOBAL_VARIABLE_BRIGHTNESS = 48
};

// Native global variables

extern int32_t get_var_wheel();
extern void set_var_wheel(int32_t value);
extern int32_t get_var_throttle();
extern void set_var_throttle(int32_t value);
extern int32_t get_var_brake();
extern void set_var_brake(int32_t value);
extern int32_t get_var_clutch();
extern void set_var_clutch(int32_t value);
extern int32_t get_var_joy_x();
extern void set_var_joy_x(int32_t value);
extern int32_t get_var_joy_y();
extern void set_var_joy_y(int32_t value);
extern int32_t get_var_lh_x();
extern void set_var_lh_x(int32_t value);
extern int32_t get_var_lh_y();
extern void set_var_lh_y(int32_t value);
extern int32_t get_var_lh_r();
extern void set_var_lh_r(int32_t value);
extern bool get_var_fs25_click1();
extern void set_var_fs25_click1(bool value);
extern bool get_var_fs25_click2();
extern void set_var_fs25_click2(bool value);
extern bool get_var_fs25_click3();
extern void set_var_fs25_click3(bool value);
extern bool get_var_fs25_click4();
extern void set_var_fs25_click4(bool value);
extern bool get_var_fs25_switch1();
extern void set_var_fs25_switch1(bool value);
extern bool get_var_fs25_switch2();
extern void set_var_fs25_switch2(bool value);
extern bool get_var_fs25_switch3();
extern void set_var_fs25_switch3(bool value);
extern bool get_var_fs25_switch4();
extern void set_var_fs25_switch4(bool value);
extern int32_t get_var_fs25_slider1();
extern void set_var_fs25_slider1(int32_t value);
extern int32_t get_var_fs25_slider2();
extern void set_var_fs25_slider2(int32_t value);
extern int32_t get_var_fs25_slider3();
extern void set_var_fs25_slider3(int32_t value);
extern int32_t get_var_fs25_slider4();
extern void set_var_fs25_slider4(int32_t value);
extern bool get_var_fs25_click_back();
extern void set_var_fs25_click_back(bool value);
extern const char *get_var_calibration_status();
extern void set_var_calibration_status(const char *value);
extern const char *get_var_calibration_values();
extern void set_var_calibration_values(const char *value);
extern bool get_var_btn_joy();
extern void set_var_btn_joy(bool value);
extern bool get_var_btn_esc();
extern void set_var_btn_esc(bool value);
extern bool get_var_btn_ok();
extern void set_var_btn_ok(bool value);
extern bool get_var_btn_up();
extern void set_var_btn_up(bool value);
extern bool get_var_btn_left();
extern void set_var_btn_left(bool value);
extern bool get_var_btn_right();
extern void set_var_btn_right(bool value);
extern bool get_var_btn_down();
extern void set_var_btn_down(bool value);
extern bool get_var_lh_btn1();
extern void set_var_lh_btn1(bool value);
extern bool get_var_lh_btn2();
extern void set_var_lh_btn2(bool value);
extern bool get_var_base_btn1();
extern void set_var_base_btn1(bool value);
extern bool get_var_base_btn2();
extern void set_var_base_btn2(bool value);
extern bool get_var_base_btn3();
extern void set_var_base_btn3(bool value);
extern bool get_var_base_btn4();
extern void set_var_base_btn4(bool value);
extern bool get_var_shifter_l();
extern void set_var_shifter_l(bool value);
extern bool get_var_shifter_r();
extern void set_var_shifter_r(bool value);
extern const char *get_var_force_feedback_status();
extern void set_var_force_feedback_status(const char *value);
extern bool get_var_wheel_calib();
extern void set_var_wheel_calib(bool value);
extern bool get_var_pedals_calib();
extern void set_var_pedals_calib(bool value);
extern bool get_var_l_joy_calib();
extern void set_var_l_joy_calib(bool value);
extern bool get_var_misko_joy_calib();
extern void set_var_misko_joy_calib(bool value);
extern const char *get_var_real_samling_frequency_hz();
extern void set_var_real_samling_frequency_hz(const char *value);
extern const char *get_var_frequencies();
extern void set_var_frequencies(const char *value);
extern int32_t get_var_selected_frequency_position();
extern void set_var_selected_frequency_position(int32_t value);
extern bool get_var_ffb_state();
extern void set_var_ffb_state(bool value);
extern int32_t get_var_brightness();
extern void set_var_brightness(int32_t value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/