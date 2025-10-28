#include <stdlib.h>
#include <stdio.h>
#include "lvgl.h"
#include "actions.h"
#include "screens.h"
#include "ui.h"
#include "vars.h"
#include "main.h"
#include "stdbool.h"
#include "InputCollection.h"
#include "FLASH_PAGE.h"
#include "SaveUserData.h"
#include "lvgl_lcd.h"


extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim2;
//helloworld
int16_t SelectedScreen = 0;
int slider1_value = 0;
int slider2_value = 0;
int slider3_value = 0;
int slider4_value = 0;
int Screen_Brightness;

int8_t FS25_Button_States[4];
int8_t FS25_Switch_States[4];

extern SystemSettings system_settings;

#pragma region Settings
void Set_Brightness(uint8_t brightness) {
    // brightness: 0-100
    if (brightness > 100) brightness = 100;
    uint32_t ccr1 = (brightness * 999) / 100; // Map 0-100 to 0-999
    __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, ccr1);
}
void action_change_screen_brightness(lv_event_t * e){
    lv_obj_t * slider = lv_event_get_target(e);
    Screen_Brightness = lv_slider_get_value(slider);
    Set_Brightness(Screen_Brightness);
}

// Timer callback function
static void hide_popup_timer_cb(lv_timer_t * timer) {
    lv_obj_add_flag(objects.settings_saved_popup, LV_OBJ_FLAG_HIDDEN);
    lv_timer_del(timer); // Delete timer after execution
}

void action_save_settings(lv_event_t * e) {
    system_settings.frequency = (uint32_t)get_selector_position_to_frequency();
    system_settings.ffb = (bool)lv_obj_get_state(objects.ffb_switch);
    system_settings.brightness = (int32_t)get_var_brightness();
    Flash_Write_All_Settings(FLASH_PAGE_ADDRESS, &system_settings);

    Flash_Read_All_Settings(FLASH_PAGE_ADDRESS, &system_settings);

    Set_Sampling_Frequency(system_settings.frequency);

    lv_obj_clear_flag(objects.settings_saved_popup, LV_OBJ_FLAG_HIDDEN);

    // Create one-shot timer for 1000ms to hide popup and re-enable input
    lv_timer_create(hide_popup_timer_cb, 1000, NULL);

}



void action_ffb_off(lv_event_t * e){
	set_var_force_feedback_status("FFB OFF");
}

void action_ffb_on(lv_event_t * e){
	set_var_force_feedback_status("!FFB ON!");
}

void action_set_wheel_center(lv_event_t * e){
	htim4.Instance->CNT = 32000;
}
#pragma endregion

#pragma region SwitchScreens
void action_switch_to_main_screen(lv_event_t *e) {
	loadScreen(SCREEN_ID_MAIN);
	SelectedScreen = 0;
}

void action_switch_to_sensor_status(lv_event_t *e) {
    loadScreen(SCREEN_ID_SENSOR_STATUS);
    SelectedScreen = 1;
}

void action_switch_to_select_game(lv_event_t *e) {
	loadScreen(SCREEN_ID_SELECT_GAME);
	SelectedScreen = 2;
}

void action_switch_to_farming_simulator25(lv_event_t *e) {
	loadScreen(SCREEN_ID_FARMING_SIMULATOR2025);
	SelectedScreen = 3;
}

void action_switch_to_settings(lv_event_t * e){
    loadScreen(SCREEN_ID_SETTINGS);
    SelectedScreen = 4;
}

void action_switch_to_calibration(lv_event_t * e){
    loadScreen(SCREEN_ID_CALIBRATION);
    SelectedScreen = 5;
}
#pragma endregion

#pragma region Calibration
void action_start_calibration(lv_event_t *e) {
	start_calibration();
}

void action_stop_calibration(lv_event_t *e) {
	//resets checkboxes
	stop_calibration();
	set_var_wheel_calib(false);
	set_var_pedals_calib(false);
	set_var_l_joy_calib(false);
	set_var_misko_joy_calib(false);

	set_var_calibration_status("Calibration stopped");
}

#pragma endregion


#pragma region fs25Screen
void action_fs25_slider1_value(lv_event_t * e) {
    lv_obj_t * slider = lv_event_get_target(e);
    slider1_value = lv_slider_get_value(slider);
}

void action_fs25_slider2_value(lv_event_t * e) {
    lv_obj_t * slider = lv_event_get_target(e);
    slider2_value = lv_slider_get_value(slider);
}

void action_fs25_slider3_value(lv_event_t * e) {
    lv_obj_t * slider = lv_event_get_target(e);
    slider3_value = lv_slider_get_value(slider);
}

void action_fs25_slider4_value(lv_event_t * e) {
    lv_obj_t * slider = lv_event_get_target(e);
    slider4_value = lv_slider_get_value(slider);
}

void action_fs25_button1_clicked(lv_event_t *e) {
    FS25_Button_States[0] = 1;
}
void action_fs25_button2_clicked(lv_event_t *e) {
    FS25_Button_States[1] = 1;
}
void action_fs25_button3_clicked(lv_event_t *e) {
    FS25_Button_States[2] = 1;
}
void action_fs25_button4_clicked(lv_event_t *e) {
    FS25_Button_States[3] = 1;
}

void action_fs25_button1_released(lv_event_t * e){
    FS25_Button_States[0] = 0;
}
void action_fs25_button2_released(lv_event_t * e){
    FS25_Button_States[1] = 0;
}
void action_fs25_button3_released(lv_event_t * e){
    FS25_Button_States[2] = 0;
}
void action_fs25_button4_released(lv_event_t * e){
    FS25_Button_States[3] = 0;
}

void action_fs25_switch1_checked(lv_event_t * e){
	FS25_Switch_States[0] = 1;
}
void action_fs25_switch2_checked(lv_event_t * e){
	FS25_Switch_States[1] = 1;
}
void action_fs25_switch3_checked(lv_event_t * e){
	FS25_Switch_States[2] = 1;
}
void action_fs25_switch4_checked(lv_event_t * e){
	FS25_Switch_States[3] = 1;
}

void action_fs25_switch1_unchecked(lv_event_t * e){
	FS25_Switch_States[0] = 0;
}
void action_fs25_switch2_unchecked(lv_event_t * e){
	FS25_Switch_States[1] = 0;
}
void action_fs25_switch3_unchecked(lv_event_t * e){
	FS25_Switch_States[2] = 0;
}
void action_fs25_switch4_unchecked(lv_event_t * e){
	FS25_Switch_States[3] = 0;
}
#pragma endregion

