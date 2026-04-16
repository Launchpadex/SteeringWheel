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
#include "flash_settings.h"
#include "lvgl_lcd.h"


extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim2;

enum ScreensEnum SelectedScreen = SCREEN_ID_MAIN;
int slider1_value = 0;
int slider2_value = 0;
int slider3_value = 0;
int slider4_value = 0;
int Screen_Brightness;

int8_t FS25_Button_States[4];
int8_t FS25_Switch_States[4];

extern SystemSettings system_settings;
extern int32_t setting_value;

static bool is_holding = false;
static uint32_t time_pressed_start = 0;

#pragma region Settings
void Set_Brightness(uint8_t brightness) {
    // brightness: 0-100
    if (brightness > 100) brightness = 100;
    uint32_t ccr1 = (brightness * 999) / 100; // Map 0-100 to 0-999
    __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, ccr1);
}

void Set_Sampling_Frequency(int32_t frequency_hz) {
    if (frequency_hz < 10)  frequency_hz = 10;
    if (frequency_hz > 1000) frequency_hz = 1000;

    uint32_t arr = (100000 / frequency_hz) - 1;
    __HAL_TIM_SET_AUTORELOAD(&htim2, arr);
}
void action_change_screen_brightness(lv_event_t * e){
    lv_obj_t * slider = lv_event_get_target(e);
    Screen_Brightness = lv_slider_get_value(slider);
    Set_Brightness(Screen_Brightness);
}

// Timer callback function
static void hide_popup_timer_cb(lv_timer_t * timer) {
    //lv_obj_add_flag(objects.settings_saved_popup, LV_OBJ_FLAG_HIDDEN);
    lv_timer_del(timer); // Delete timer after execution
}

void action_save_settings(lv_event_t * e) {
    system_settings.frequency = (uint32_t)get_selector_position_to_frequency();
    //system_settings.brightness = (int32_t)get_var_brightness();
    //system_settings.deadzone = (int32_t)get_var_deadzone();
    Flash_Write_All_Settings(FLASH_PAGE_ADDRESS, &system_settings);

    Flash_Read_All_Settings(FLASH_PAGE_ADDRESS, &system_settings);

    Set_Sampling_Frequency(system_settings.frequency);
    Set_Brightness(system_settings.brightness);

    //lv_obj_clear_flag(objects.settings_saved_popup, LV_OBJ_FLAG_HIDDEN);

    // Create one-shot timer for 1000ms to hide popup and re-enable input
    lv_timer_create(hide_popup_timer_cb, 1000, NULL);

}





void action_set_wheel_center(lv_event_t * e){
	htim4.Instance->CNT = 32000;
}

void action_change_deadzone(lv_event_t * e){
	deadzone = get_var_deadzone();
	char temp[16];
	snprintf(temp, sizeof(temp), "%d", deadzone);
	//set_var_deadzone_char(temp);
}

#pragma endregion


#pragma region Calibration
void action_start_calibration(lv_event_t *e) {
	Inputs_StartCalibration();
	loadScreen(SCREEN_ID_CALIBRATION_INDICATION);
	SelectedScreen = SCREEN_ID_CALIBRATION_INDICATION;
}

void action_stop_calibration(lv_event_t *e) {
	//resets checkboxes
	Inputs_StopCalibration();
	Flash_Write_All_Settings(FLASH_PAGE_ADDRESS, &system_settings);
	set_var_wheel_calib(false);
	set_var_pedals_calib(false);
	set_var_l_joy_calib(false);
	set_var_misko_joy_calib(false);

	loadScreen(SCREEN_ID_CALIBRATION);
	SelectedScreen = SCREEN_ID_CALIBRATION;

	set_var_calibration_status("Calibration stopped");
}

void action_reset_calibration_values(lv_event_t * e){
	for (size_t i = 0; i < MAX_AXES; i++){
		system_settings.axis_min[i] = DEFAULT_AXIS_MAX;
		system_settings.axis_max[i] = DEFAULT_AXIS_MIN;
	}
}

#pragma endregion

void action_ffb_off(lv_event_t * e){
	set_var_force_feedback_status("FFB OFF");
}

void action_ffb_on(lv_event_t * e){
	set_var_force_feedback_status("!FFB ON!");
}

#pragma region FFBSettings
/* Helper: Get current value based on selected setting */
static int32_t ffb_get_current_value(void) {
    int32_t selected = lv_dropdown_get_selected(objects.ffb_settings_selector);
    switch (selected) {
        case 0: return system_settings.ffb_gain;
        case 1: return system_settings.ffb_max_current_mA;
        case 2: return system_settings.ffb_spd_threshold;
        case 3: return system_settings.ffb_acl_threshold;
        case 4: return system_settings.ffb_frc_threshold;
        case 5: return system_settings.ffb_spring_coef;
        case 6: return system_settings.ffb_damper_coef;
        case 7: return system_settings.ffb_friction_coef;
        case 8: return system_settings.ffb_inertia_coef;
        default: return 0;
    }
}

/* Helper: Set value based on selected setting */
static void ffb_set_current_value(int32_t value) {
    if (value < 0) value = 0;
    int32_t selected = lv_dropdown_get_selected(objects.ffb_settings_selector);
    switch (selected) {
        case 0: system_settings.ffb_gain = value; break;
        case 1: system_settings.ffb_max_current_mA = value; break;
        case 2: system_settings.ffb_spd_threshold = value; break;
        case 3: system_settings.ffb_acl_threshold = value; break;
        case 4: system_settings.ffb_frc_threshold = value; break;
        case 5: system_settings.ffb_spring_coef = value; break;
        case 6: system_settings.ffb_damper_coef = value; break;
        case 7: system_settings.ffb_friction_coef = value; break;
        case 8: system_settings.ffb_inertia_coef = value; break;
    }
    update_var_setting_value(value);
}


/* OK button - save FFB settings and return to main */
void action_ffb_settings_ok(lv_event_t * e) {
	system_settings.ffb = (bool)lv_obj_get_state(objects.ffb_switch);
    /* Write settings to flash */
    Flash_Write_All_Settings(FLASH_PAGE_ADDRESS, &system_settings);
    /* Read back to verify */
    Flash_Read_All_Settings(FLASH_PAGE_ADDRESS, &system_settings);
    /* Update formatted settings string */
    set_var_ffb_settings(format_ffb_settings_string());
}

void action_ffb_setting_selected(lv_event_t * e){
    setting_value = ffb_get_current_value();
    update_var_setting_value(setting_value);
}

void action_btn_increase_decrease_handler(lv_event_t * e){
	lv_event_code_t event_type = lv_event_get_code(e);
	lv_obj_t * btn = lv_event_get_target(e);
	int8_t direction = 0;
	uint32_t time_pressed = 0;
	int32_t step = 1;

	if (btn == objects.increase_btn){
		direction = 1;
	} else if (btn == objects.decrease_btn){
		direction = -1;
	} else {
		return;
	}

	if (event_type == LV_EVENT_CLICKED){
		setting_value += direction;
		ffb_set_current_value(setting_value);
	} else if (event_type == LV_EVENT_LONG_PRESSED){
		time_pressed_start = lv_tick_get();
		is_holding = true;
	} else if(event_type == LV_EVENT_LONG_PRESSED_REPEAT){
		if(!is_holding) return;

		time_pressed = lv_tick_elaps(time_pressed_start);

		// Acceleration based on hold duration
		if      (time_pressed > 2500) step = 50;
		else if (time_pressed > 1600) step = 20;
		else if (time_pressed > 1000) step = 10;
		else if (time_pressed > 600)  step = 5;
		else if (time_pressed > 300)  step = 2;

		setting_value += step * direction;
		ffb_set_current_value(setting_value);
	} else if (event_type == LV_EVENT_RELEASED) {
		is_holding = false;
	}
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

