#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *settings;
    lv_obj_t *sensor_status;
    lv_obj_t *calibration;
    lv_obj_t *calibration_indication;
    lv_obj_t *select_game;
    lv_obj_t *farming_simulator2025;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *wheel_calib_cb;
    lv_obj_t *l_joy_calib_cb;
    lv_obj_t *pedals_calib_cb;
    lv_obj_t *misko_joy_calib_cb;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *calibration_status_main;
    lv_obj_t *force_feedback_status_main;
    lv_obj_t *btn_save_settings;
    lv_obj_t *obj19;
    lv_obj_t *settings_selector;
    lv_obj_t *decrease_btn;
    lv_obj_t *increase_btn;
    lv_obj_t *settings_saved_popup;
    lv_obj_t *obj20;
    lv_obj_t *status_wheel;
    lv_obj_t *status_throttle;
    lv_obj_t *status_brake;
    lv_obj_t *status_clutch;
    lv_obj_t *status_misko_x;
    lv_obj_t *status_misko_y;
    lv_obj_t *status_lh_x;
    lv_obj_t *status_lh_y;
    lv_obj_t *status_lh_slider;
    lv_obj_t *status_ffb_force;
    lv_obj_t *calibration_status_calibration;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
    lv_obj_t *calibration_status_calibration_1;
    lv_obj_t *obj23;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *obj26;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_SETTINGS = 2,
    SCREEN_ID_SENSOR_STATUS = 3,
    SCREEN_ID_CALIBRATION = 4,
    SCREEN_ID_CALIBRATION_INDICATION = 5,
    SCREEN_ID_SELECT_GAME = 6,
    SCREEN_ID_FARMING_SIMULATOR2025 = 7,
};

void create_screen_main();
void tick_screen_main();

void create_screen_settings();
void tick_screen_settings();

void create_screen_sensor_status();
void tick_screen_sensor_status();

void create_screen_calibration();
void tick_screen_calibration();

void create_screen_calibration_indication();
void tick_screen_calibration_indication();

void create_screen_select_game();
void tick_screen_select_game();

void create_screen_farming_simulator2025();
void tick_screen_farming_simulator2025();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/