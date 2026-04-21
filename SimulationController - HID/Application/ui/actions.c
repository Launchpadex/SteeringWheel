#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "lvgl.h"
#include "actions.h"
#include "screens.h"
#include "ui.h"
#include "vars.h"
#include "main.h"
#include "stdbool.h"
#include "InputCollection.h"
#include "flash_settings.h"
#include "lvgl_lcd.h"
#include "tim.h"

enum ScreensEnum SelectedScreen = SCREEN_ID_MAIN;
int slider1_value = 0;
int slider2_value = 0;
int slider3_value = 0;
int slider4_value = 0;
int Screen_Brightness;

int8_t FS25_Button_States[4];
int8_t FS25_Switch_States[4];

extern SystemSettings system_settings;

/*=====================================================================*/
/* Hardware control                                                    */
/*=====================================================================*/

void Set_Brightness(uint8_t brightness) {
    if (brightness > 100) brightness = 100;
    __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, (brightness * 999) / 100);
}

void Set_Sampling_Frequency(int32_t frequency_hz) {
    if (frequency_hz < 10)   frequency_hz = 10;
    if (frequency_hz > 1000) frequency_hz = 1000;
    __HAL_TIM_SET_AUTORELOAD(&htim2, (100000 / frequency_hz) - 1);
}

void action_change_screen_brightness(lv_event_t *e) {
    Screen_Brightness = lv_slider_get_value(lv_event_get_target(e));
    Set_Brightness((uint8_t)Screen_Brightness);
}

/*=====================================================================*/
/* Settings descriptor table                                           */
/*=====================================================================*/

typedef struct {
    const char *name;
    size_t      offset;
    int32_t     min_val;
    int32_t     max_val;
} SettingDef;

static const SettingDef g_settings[] = {
    { "Brightness",       offsetof(SystemSettings, brightness),         0,   100   },
    { "Sampling Freq",    offsetof(SystemSettings, frequency),           10,  1000  },
    { "FFB Enable",       offsetof(SystemSettings, ffb),                0,   1     },
    { "FFB Gain %",       offsetof(SystemSettings, ffb_gain),           0,   200   },
    { "Max Current mA",   offsetof(SystemSettings, ffb_max_current_mA), 0,   30000 },
    { "Speed Threshold",  offsetof(SystemSettings, ffb_spd_threshold),  0,   1000  },
    { "Accel Threshold",  offsetof(SystemSettings, ffb_acl_threshold),  0,   1000  },
    { "Friction Thresh",  offsetof(SystemSettings, ffb_frc_threshold),  0,   1000  },
    { "Spring Coef",      offsetof(SystemSettings, ffb_spring_coef),    0,   500   },
    { "Damper Coef",      offsetof(SystemSettings, ffb_damper_coef),    0,   500   },
    { "Friction Coef",    offsetof(SystemSettings, ffb_friction_coef),  0,   500   },
    { "Inertia Coef",     offsetof(SystemSettings, ffb_inertia_coef),   0,   500   },
    { "Dz: Wheel",        offsetof(SystemSettings, axis_deadzone) + 0*sizeof(int32_t), 0, 32767 },
    { "Dz: Throttle",     offsetof(SystemSettings, axis_deadzone) + 1*sizeof(int32_t), 0, 32767 },
    { "Dz: Brake",        offsetof(SystemSettings, axis_deadzone) + 2*sizeof(int32_t), 0, 32767 },
    { "Dz: Clutch",       offsetof(SystemSettings, axis_deadzone) + 3*sizeof(int32_t), 0, 32767 },
    { "Dz: LH X",         offsetof(SystemSettings, axis_deadzone) + 4*sizeof(int32_t), 0, 32767 },
    { "Dz: LH Y",         offsetof(SystemSettings, axis_deadzone) + 5*sizeof(int32_t), 0, 32767 },
    { "Dz: LH Slider",    offsetof(SystemSettings, axis_deadzone) + 6*sizeof(int32_t), 0, 32767 },
    { "Dz: Misko X",      offsetof(SystemSettings, axis_deadzone) + 7*sizeof(int32_t), 0, 32767 },
    { "Dz: Misko Y",      offsetof(SystemSettings, axis_deadzone) + 8*sizeof(int32_t), 0, 32767 },
};
#define NUM_SETTINGS (sizeof(g_settings) / sizeof(g_settings[0]))

static int32_t settings_get(uint32_t idx) {
    if (idx >= NUM_SETTINGS) return 0;
    return *(int32_t *)((uint8_t *)&system_settings + g_settings[idx].offset);
}

static void settings_set(uint32_t idx, int32_t val) {
    if (idx >= NUM_SETTINGS) return;
    if (val < g_settings[idx].min_val) val = g_settings[idx].min_val;
    if (val > g_settings[idx].max_val) val = g_settings[idx].max_val;
    *(int32_t *)((uint8_t *)&system_settings + g_settings[idx].offset) = val;
}

void settings_init_display(void) {
    static char opts[300];
    opts[0] = '\0';
    for (size_t i = 0; i < NUM_SETTINGS; i++) {
        if (i > 0) strncat(opts, "\n", sizeof(opts) - strlen(opts) - 1);
        strncat(opts, g_settings[i].name, sizeof(opts) - strlen(opts) - 1);
    }
    set_var_settings(opts);
    set_var_settings_selected(0);
    update_var_setting_value(settings_get(0));
}

/*=====================================================================*/
/* Save / popup                                                        */
/*=====================================================================*/

static void hide_popup_timer_cb(lv_timer_t *timer) {
    lv_obj_add_flag(objects.settings_saved_popup, LV_OBJ_FLAG_HIDDEN);
    lv_timer_del(timer);
}

void action_save_settings(lv_event_t *e) {
    Flash_Write_All_Settings(FLASH_PAGE_ADDRESS, &system_settings);
    Set_Brightness((uint8_t)system_settings.brightness);
    Set_Sampling_Frequency(system_settings.frequency);
    lv_obj_clear_flag(objects.settings_saved_popup, LV_OBJ_FLAG_HIDDEN);
    lv_timer_create(hide_popup_timer_cb, 1000, NULL);
}

void action_set_wheel_center(lv_event_t *e) {
    htim4.Instance->CNT = 32000;
}

/*=====================================================================*/
/* Screen navigation                                                   */
/*=====================================================================*/

void action_switch_to_main_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_MAIN);
    SelectedScreen = SCREEN_ID_MAIN;
}

void action_switch_to_sensor_status(lv_event_t *e) {
    loadScreen(SCREEN_ID_SENSOR_STATUS);
    SelectedScreen = SCREEN_ID_SENSOR_STATUS;
}

void action_switch_to_select_game(lv_event_t *e) {
    loadScreen(SCREEN_ID_SELECT_GAME);
    SelectedScreen = SCREEN_ID_SELECT_GAME;
}

void action_switch_to_farming_simulator25(lv_event_t *e) {
    loadScreen(SCREEN_ID_FARMING_SIMULATOR2025);
    SelectedScreen = SCREEN_ID_FARMING_SIMULATOR2025;
}

static void on_settings_selector_changed(lv_event_t *e) {
    if (lv_event_get_code(e) != LV_EVENT_VALUE_CHANGED) return;
    uint32_t idx = (uint32_t)lv_dropdown_get_selected(objects.settings_selector);
    update_var_setting_value(settings_get(idx));
}

void action_switch_to_settings(lv_event_t *e) {
    loadScreen(SCREEN_ID_SETTINGS);
    SelectedScreen = SCREEN_ID_SETTINGS;
    /* loadScreen recreates the screen, so re-register the change handler */
    lv_obj_add_event_cb(objects.settings_selector, on_settings_selector_changed, LV_EVENT_VALUE_CHANGED, NULL);
    update_var_setting_value(settings_get((uint32_t)lv_dropdown_get_selected(objects.settings_selector)));
}

void action_switch_to_calibration(lv_event_t *e) {
    loadScreen(SCREEN_ID_CALIBRATION);
    SelectedScreen = SCREEN_ID_CALIBRATION;
}

/*=====================================================================*/
/* Calibration                                                         */
/*=====================================================================*/

void action_start_calibration(lv_event_t *e) {
    Inputs_StartCalibration();
    loadScreen(SCREEN_ID_CALIBRATION_INDICATION);
    SelectedScreen = SCREEN_ID_CALIBRATION_INDICATION;
}

void action_stop_calibration(lv_event_t *e) {
    Inputs_StopCalibration();
    set_var_wheel_calib(false);
    set_var_pedals_calib(false);
    set_var_l_joy_calib(false);
    set_var_misko_joy_calib(false);
    loadScreen(SCREEN_ID_CALIBRATION);
    SelectedScreen = SCREEN_ID_CALIBRATION;
    set_var_calibration_status("Calibration stopped");
}

void action_reset_calibration_values(lv_event_t *e) {
    for (size_t i = 0; i < MAX_AXES; i++) {
        system_settings.axis_min[i] = DEFAULT_AXIS_MAX;
        system_settings.axis_max[i] = DEFAULT_AXIS_MIN;
    }
}

/*=====================================================================*/
/* FFB toggle                                                          */
/*=====================================================================*/

void action_ffb_off(lv_event_t *e) { set_var_force_feedback_status("FFB OFF"); }
void action_ffb_on(lv_event_t *e)  { set_var_force_feedback_status("!FFB ON!"); }

/*=====================================================================*/
/* Settings increase / decrease with acceleration                      */
/*=====================================================================*/

void action_increase_decrease_setting_value(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_RELEASED) return;
    if (code != LV_EVENT_CLICKED &&
        code != LV_EVENT_LONG_PRESSED &&
        code != LV_EVENT_LONG_PRESSED_REPEAT) return;

    static uint32_t repeat_count = 0;
    bool increase = (lv_event_get_target(e) == objects.increase_btn);

    int32_t step;
    if (code == LV_EVENT_LONG_PRESSED_REPEAT) {
        ++repeat_count;
        step = (repeat_count < 10) ? 1 : (repeat_count < 30) ? 10 : 100;
    } else {
        repeat_count = 0;
        step = 1;
    }
    if (!increase) step = -step;

    uint32_t idx = (uint32_t)lv_dropdown_get_selected(objects.settings_selector);
    settings_set(idx, settings_get(idx) + step);
    update_var_setting_value(settings_get(idx));
}

/*=====================================================================*/
/* FS25 screen                                                         */
/*=====================================================================*/

void action_fs25_slider1_value(lv_event_t *e) { slider1_value = lv_slider_get_value(lv_event_get_target(e)); }
void action_fs25_slider2_value(lv_event_t *e) { slider2_value = lv_slider_get_value(lv_event_get_target(e)); }
void action_fs25_slider3_value(lv_event_t *e) { slider3_value = lv_slider_get_value(lv_event_get_target(e)); }
void action_fs25_slider4_value(lv_event_t *e) { slider4_value = lv_slider_get_value(lv_event_get_target(e)); }

void action_fs25_button1_clicked(lv_event_t *e)  { FS25_Button_States[0] = 1; }
void action_fs25_button2_clicked(lv_event_t *e)  { FS25_Button_States[1] = 1; }
void action_fs25_button3_clicked(lv_event_t *e)  { FS25_Button_States[2] = 1; }
void action_fs25_button4_clicked(lv_event_t *e)  { FS25_Button_States[3] = 1; }
void action_fs25_button1_released(lv_event_t *e) { FS25_Button_States[0] = 0; }
void action_fs25_button2_released(lv_event_t *e) { FS25_Button_States[1] = 0; }
void action_fs25_button3_released(lv_event_t *e) { FS25_Button_States[2] = 0; }
void action_fs25_button4_released(lv_event_t *e) { FS25_Button_States[3] = 0; }

void action_fs25_switch1_checked(lv_event_t *e)   { FS25_Switch_States[0] = 1; }
void action_fs25_switch2_checked(lv_event_t *e)   { FS25_Switch_States[1] = 1; }
void action_fs25_switch3_checked(lv_event_t *e)   { FS25_Switch_States[2] = 1; }
void action_fs25_switch4_checked(lv_event_t *e)   { FS25_Switch_States[3] = 1; }
void action_fs25_switch1_unchecked(lv_event_t *e) { FS25_Switch_States[0] = 0; }
void action_fs25_switch2_unchecked(lv_event_t *e) { FS25_Switch_States[1] = 0; }
void action_fs25_switch3_unchecked(lv_event_t *e) { FS25_Switch_States[2] = 0; }
void action_fs25_switch4_unchecked(lv_event_t *e) { FS25_Switch_States[3] = 0; }
