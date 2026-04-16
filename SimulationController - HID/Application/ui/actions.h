#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "screens.h"
extern enum ScreensEnum SelectedScreen;
extern int slider1_value;
extern int slider2_value;
extern int slider3_value;
extern int slider4_value;

extern int8_t FS25_Button_States[4];
extern int8_t FS25_Switch_States[4];
extern int Screen_Brightness;
extern int deadzone;

extern void Set_Brightness(uint8_t brightness);
void Set_Sampling_Frequency(int32_t frequency_hz);
extern void update_sensor_flow_vars(void);
extern void action_btn_increase_decrease_handler(lv_event_t * e);
extern void action_ffb_setting_selected(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/