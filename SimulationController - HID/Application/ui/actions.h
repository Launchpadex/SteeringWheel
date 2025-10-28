#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int16_t SelectedScreen;
extern int slider1_value;
extern int slider2_value;
extern int slider3_value;
extern int slider4_value;

extern int8_t FS25_Button_States[4];
extern int8_t FS25_Switch_States[4];
extern int Screen_Brightness;

extern void Set_Brightness(uint8_t brightness);

extern void action_switch_to_sensor_status(lv_event_t * e);
extern void action_switch_to_main_screen(lv_event_t * e);
extern void action_switch_to_select_game(lv_event_t * e);
extern void action_switch_to_settings(lv_event_t * e);
extern void action_switch_to_calibration(lv_event_t * e);
extern void action_switch_to_farming_simulator25(lv_event_t * e);
extern void action_fs25_slider1_value(lv_event_t * e);
extern void action_fs25_slider2_value(lv_event_t * e);
extern void action_fs25_slider3_value(lv_event_t * e);
extern void action_fs25_slider4_value(lv_event_t * e);
extern void action_fs25_button1_clicked(lv_event_t * e);
extern void action_fs25_button2_clicked(lv_event_t * e);
extern void action_fs25_button3_clicked(lv_event_t * e);
extern void action_fs25_button4_clicked(lv_event_t * e);
extern void action_fs25_switch1_checked(lv_event_t * e);
extern void action_fs25_switch2_checked(lv_event_t * e);
extern void action_fs25_switch3_checked(lv_event_t * e);
extern void action_fs25_switch4_checked(lv_event_t * e);
extern void action_fs25_button1_released(lv_event_t * e);
extern void action_fs25_button2_released(lv_event_t * e);
extern void action_fs25_button3_released(lv_event_t * e);
extern void action_fs25_button4_released(lv_event_t * e);
extern void action_fs25_switch1_unchecked(lv_event_t * e);
extern void action_fs25_switch2_unchecked(lv_event_t * e);
extern void action_fs25_switch3_unchecked(lv_event_t * e);
extern void action_fs25_switch4_unchecked(lv_event_t * e);
extern void action_refresh_latency_changed(lv_event_t * e);
extern void action_start_calibration(lv_event_t * e);
extern void action_stop_calibration(lv_event_t * e);
extern void action_change_screen_brightness(lv_event_t * e);
extern void action_save_settings(lv_event_t * e);
extern void action_ffb_off(lv_event_t * e);
extern void action_ffb_on(lv_event_t * e);
extern void action_set_wheel_center(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/