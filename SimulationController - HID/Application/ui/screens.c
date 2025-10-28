#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"
#include "InputCollection.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_settings_brigthness_slider(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            set_var_brightness(value);
        }
    }
}

static void event_handler_unchecked_cb_settings_ffb_switch(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_ffb_off(e);
    }
}

static void event_handler_checked_cb_settings_ffb_switch(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_ffb_on(e);
    }
}

static void event_handler_cb_settings_ffb_switch(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_ffb_state(value);
        }
    }
}

static void event_handler_cb_settings_sampling_freq_selector(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_selected_frequency_position(value);
        }
    }
}

static void event_handler_cb_calibration_wheel_calib_cb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_wheel_calib(value);
        }
    }
}

static void event_handler_cb_calibration_l_joy_calib_cb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_l_joy_calib(value);
        }
    }
}

static void event_handler_cb_calibration_pedals_calib_cb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_pedals_calib(value);
        }
    }
}

static void event_handler_cb_calibration_misko_joy_calib_cb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_misko_joy_calib(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
}

static void event_handler_cb_sensor_status_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
}

static void event_handler_cb_sensor_status_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
}

static void event_handler_cb_sensor_status_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
}

static void event_handler_cb_sensor_status_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
}

static void event_handler_cb_sensor_status_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
}

static void event_handler_cb_sensor_status_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
}

static void event_handler_cb_sensor_status_obj7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
}

static void event_handler_cb_sensor_status_obj8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
}

static void event_handler_cb_sensor_status_obj9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_btn_esc(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_btn_ok(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_btn_left(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_btn_right(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_btn_down(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_btn_up(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_lh_btn1(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_lh_btn2(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj17(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_base_btn1(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj18(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_base_btn2(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_base_btn3(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj20(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_base_btn4(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj21(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_btn_joy(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj22(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_shifter_l(value);
        }
    }
}

static void event_handler_cb_sensor_status_obj23(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_shifter_r(value);
        }
    }
}

static void event_handler_unchecked_cb_farming_simulator2025_obj24(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fs25_switch1_unchecked(e);
    }
}

static void event_handler_checked_cb_farming_simulator2025_obj24(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fs25_switch1_checked(e);
    }
}

static void event_handler_unchecked_cb_farming_simulator2025_obj25(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fs25_switch2_unchecked(e);
    }
}

static void event_handler_checked_cb_farming_simulator2025_obj25(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fs25_switch2_checked(e);
    }
}

static void event_handler_unchecked_cb_farming_simulator2025_obj26(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fs25_switch3_unchecked(e);
    }
}

static void event_handler_checked_cb_farming_simulator2025_obj26(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fs25_switch3_checked(e);
    }
}

static void event_handler_unchecked_cb_farming_simulator2025_obj27(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fs25_switch4_unchecked(e);
    }
}

static void event_handler_checked_cb_farming_simulator2025_obj27(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fs25_switch4_checked(e);
    }
}

void create_screen_settings() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 257, 0);
            lv_obj_set_size(obj, 63, 36);
            lv_obj_add_event_cb(obj, action_switch_to_main_screen, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 103, 0);
            lv_obj_set_size(obj, 115, 36);
            lv_obj_add_event_cb(obj, action_switch_to_calibration, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Calibaration");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // brigthness_slider
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.brigthness_slider = obj;
            lv_obj_set_pos(obj, 136, 89);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 10, 100);
            lv_obj_add_event_cb(obj, action_change_screen_brightness, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_brigthness_slider, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 27, 86);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Brightness");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, -1, 204);
            lv_obj_set_size(obj, 116, 36);
            lv_obj_add_event_cb(obj, action_save_settings, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save Settings");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FFB_Switch
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.ffb_switch = obj;
            lv_obj_set_pos(obj, 136, 52);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_settings_ffb_switch, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_settings_ffb_switch, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_ffb_switch, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 56);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ForceFeedback");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 205, 204);
            lv_obj_set_size(obj, 115, 36);
            lv_obj_add_event_cb(obj, action_set_wheel_center, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff006d1a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 115, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Wheel center");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 29, 115);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Sampling\nfrequency");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Sampling_freq_selector
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.sampling_freq_selector = obj;
            lv_obj_set_pos(obj, 136, 113);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "");
            lv_obj_add_event_cb(obj, event_handler_cb_settings_sampling_freq_selector, LV_EVENT_ALL, 0);
        }
        {
            // SettingsSavedPopup
            lv_obj_t *obj = lv_msgbox_create(parent_obj);
            objects.settings_saved_popup = obj;
            lv_obj_set_pos(obj, 67, 85);
            lv_obj_set_size(obj, 186, 70);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE|LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 34, 23);
                    lv_obj_set_size(obj, 114, 20);
                    lv_label_set_text(obj, "Settings saved");
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_FLOATING);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_settings() {
    {
        int32_t new_val = get_var_brightness();
        int32_t cur_val = lv_slider_get_value(objects.brigthness_slider);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.brigthness_slider;
            lv_slider_set_value(objects.brigthness_slider, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_ffb_state();
        bool cur_val = lv_obj_has_state(objects.ffb_switch, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.ffb_switch;
            if (new_val) lv_obj_add_state(objects.ffb_switch, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.ffb_switch, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_frequencies();
        const char *cur_val = lv_dropdown_get_options(objects.sampling_freq_selector);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.sampling_freq_selector;
            lv_dropdown_set_options(objects.sampling_freq_selector, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.sampling_freq_selector) & LV_STATE_EDITED)) {
            int32_t new_val = get_var_selected_frequency_position();
            int32_t cur_val = lv_dropdown_get_selected(objects.sampling_freq_selector);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.sampling_freq_selector;
                lv_dropdown_set_selected(objects.sampling_freq_selector, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 94, 9);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "SteeringWheel\nPowered By Misko");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 177, 109);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_switch_to_sensor_status, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "SensorStatus");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 42, 109);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_switch_to_select_game, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "SelectGame");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 255, 210);
            lv_obj_set_size(obj, 65, 30);
            lv_obj_add_event_cb(obj, action_switch_to_settings, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Settings");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Calibration_Status_Main
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.calibration_status_main = obj;
            lv_obj_set_pos(obj, 91, 202);
            lv_obj_set_size(obj, 138, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // ForceFeedback_Status_Main
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.force_feedback_status_main = obj;
            lv_obj_set_pos(obj, 92, 53);
            lv_obj_set_size(obj, 135, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // actual_sampling_frequency
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.actual_sampling_frequency = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
        }
    }
}

void tick_screen_main() {
    {
        const char *new_val = get_var_calibration_status();
        const char *cur_val = lv_label_get_text(objects.calibration_status_main);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.calibration_status_main;
            lv_label_set_text(objects.calibration_status_main, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_force_feedback_status();
        const char *cur_val = lv_label_get_text(objects.force_feedback_status_main);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.force_feedback_status_main;
            lv_label_set_text(objects.force_feedback_status_main, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_real_samling_frequency_hz();
        const char *cur_val = lv_label_get_text(objects.actual_sampling_frequency);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.actual_sampling_frequency;
            lv_label_set_text(objects.actual_sampling_frequency, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_calibration() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.calibration = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 0, 204);
            lv_obj_set_size(obj, 63, 36);
            lv_obj_add_event_cb(obj, action_switch_to_settings, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 126, 36);
            lv_obj_add_event_cb(obj, action_start_calibration, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Start Calibration");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Calibration_Status_Calibration
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.calibration_status_calibration = obj;
            lv_obj_set_pos(obj, 60, 214);
            lv_obj_set_size(obj, 200, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 194, 0);
            lv_obj_set_size(obj, 126, 36);
            lv_obj_add_event_cb(obj, action_stop_calibration, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff6262), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Stop Calibration");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // WHEEL_CALIB_CB
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.wheel_calib_cb = obj;
            lv_obj_set_pos(obj, 13, 41);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Wheel");
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_wheel_calib_cb, LV_EVENT_ALL, 0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // L_JOY_CALIB_CB
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.l_joy_calib_cb = obj;
            lv_obj_set_pos(obj, 13, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Left JOY");
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_l_joy_calib_cb, LV_EVENT_ALL, 0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // PEDALS_CALIB_CB
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.pedals_calib_cb = obj;
            lv_obj_set_pos(obj, 13, 80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Pedals");
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_pedals_calib_cb, LV_EVENT_ALL, 0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // MISKO_JOY_CALIB_CB
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.misko_joy_calib_cb = obj;
            lv_obj_set_pos(obj, 13, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Misko JOY");
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_misko_joy_calib_cb, LV_EVENT_ALL, 0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_calibration() {
    {
        const char *new_val = get_var_calibration_status();
        const char *cur_val = lv_label_get_text(objects.calibration_status_calibration);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.calibration_status_calibration;
            lv_label_set_text(objects.calibration_status_calibration, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_wheel_calib();
        bool cur_val = lv_obj_has_state(objects.wheel_calib_cb, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.wheel_calib_cb;
            if (new_val) lv_obj_add_state(objects.wheel_calib_cb, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.wheel_calib_cb, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_l_joy_calib();
        bool cur_val = lv_obj_has_state(objects.l_joy_calib_cb, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.l_joy_calib_cb;
            if (new_val) lv_obj_add_state(objects.l_joy_calib_cb, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.l_joy_calib_cb, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_pedals_calib();
        bool cur_val = lv_obj_has_state(objects.pedals_calib_cb, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.pedals_calib_cb;
            if (new_val) lv_obj_add_state(objects.pedals_calib_cb, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.pedals_calib_cb, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_misko_joy_calib();
        bool cur_val = lv_obj_has_state(objects.misko_joy_calib_cb, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.misko_joy_calib_cb;
            if (new_val) lv_obj_add_state(objects.misko_joy_calib_cb, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.misko_joy_calib_cb, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_sensor_status() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.sensor_status = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 257, 0);
            lv_obj_set_size(obj, 63, 36);
            lv_obj_add_event_cb(obj, action_switch_to_main_screen, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 50, 6);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 4000);
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj0, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 7, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Wheel");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 50, 18);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 2815, 3455);
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj1, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 4, 18);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Throttle");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 9, 30);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Brake");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 50, 30);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 1455, 1990);
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj2, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 7, 42);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Clutch");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 50, 42);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 2350, 2960);
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj3, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 54);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Joy_x");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 50, 54);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 3200);
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj4, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 66);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Joy_y");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 50, 66);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 3200);
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj5, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 78);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "LH_X");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 89);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "LH_Y");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 50, 78);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 200, 1000);
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj6, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 50, 90);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 2950, 3800);
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj7, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 101);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "LH_R");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 50, 102);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 10, 4095);
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj8, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 13, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_ESC");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj9, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 13, 148);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_OK");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj10, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 13, 176);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_LEFT");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj11, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 13, 190);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_RIGHT");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj12, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 13, 204);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_DOWN");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj13, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 13, 162);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_UP");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj14, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 101, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "LH_BTN1");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj15, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 101, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "LH_BTN2");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj16, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 187, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BASE_BTN1");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj17, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 187, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BASE_BTN2");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj18, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 187, 148);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BASE_BTN3");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj19, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 187, 162);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BASE_BTN4");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj20, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj21 = obj;
            lv_obj_set_pos(obj, 13, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_JOY");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj21, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 101, 162);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "SHIFTER_L");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj22, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 101, 176);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "SHIFTER_R");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj23, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_sensor_status() {
    {
        int32_t new_val = get_var_wheel();
        int32_t cur_val = lv_bar_get_value(objects.obj0);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj0;
            lv_bar_set_value(objects.obj0, new_val, LV_ANIM_ON);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_throttle();
        int32_t cur_val = lv_bar_get_value(objects.obj1);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj1;
            lv_bar_set_value(objects.obj1, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_brake();
        int32_t cur_val = lv_bar_get_value(objects.obj2);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj2;
            lv_bar_set_value(objects.obj2, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_clutch();
        int32_t cur_val = lv_bar_get_value(objects.obj3);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj3;
            lv_bar_set_value(objects.obj3, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_joy_x();
        int32_t cur_val = lv_bar_get_value(objects.obj4);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj4;
            lv_bar_set_value(objects.obj4, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_joy_y();
        int32_t cur_val = lv_bar_get_value(objects.obj5);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj5;
            lv_bar_set_value(objects.obj5, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_lh_x();
        int32_t cur_val = lv_bar_get_value(objects.obj6);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj6;
            lv_bar_set_value(objects.obj6, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_lh_y();
        int32_t cur_val = lv_bar_get_value(objects.obj7);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj7;
            lv_bar_set_value(objects.obj7, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_lh_r();
        int32_t cur_val = lv_bar_get_value(objects.obj8);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj8;
            lv_bar_set_value(objects.obj8, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_btn_esc();
        bool cur_val = lv_obj_has_state(objects.obj9, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj9;
            if (new_val) lv_obj_add_state(objects.obj9, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj9, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_btn_ok();
        bool cur_val = lv_obj_has_state(objects.obj10, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj10;
            if (new_val) lv_obj_add_state(objects.obj10, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj10, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_btn_left();
        bool cur_val = lv_obj_has_state(objects.obj11, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj11;
            if (new_val) lv_obj_add_state(objects.obj11, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj11, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_btn_right();
        bool cur_val = lv_obj_has_state(objects.obj12, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj12;
            if (new_val) lv_obj_add_state(objects.obj12, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj12, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_btn_down();
        bool cur_val = lv_obj_has_state(objects.obj13, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj13;
            if (new_val) lv_obj_add_state(objects.obj13, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj13, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_btn_up();
        bool cur_val = lv_obj_has_state(objects.obj14, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj14;
            if (new_val) lv_obj_add_state(objects.obj14, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj14, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_lh_btn1();
        bool cur_val = lv_obj_has_state(objects.obj15, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj15;
            if (new_val) lv_obj_add_state(objects.obj15, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj15, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_lh_btn2();
        bool cur_val = lv_obj_has_state(objects.obj16, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj16;
            if (new_val) lv_obj_add_state(objects.obj16, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj16, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_base_btn1();
        bool cur_val = lv_obj_has_state(objects.obj17, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj17;
            if (new_val) lv_obj_add_state(objects.obj17, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj17, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_base_btn2();
        bool cur_val = lv_obj_has_state(objects.obj18, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj18;
            if (new_val) lv_obj_add_state(objects.obj18, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj18, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_base_btn3();
        bool cur_val = lv_obj_has_state(objects.obj19, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj19;
            if (new_val) lv_obj_add_state(objects.obj19, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj19, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_base_btn4();
        bool cur_val = lv_obj_has_state(objects.obj20, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj20;
            if (new_val) lv_obj_add_state(objects.obj20, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj20, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_btn_joy();
        bool cur_val = lv_obj_has_state(objects.obj21, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj21;
            if (new_val) lv_obj_add_state(objects.obj21, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj21, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_shifter_l();
        bool cur_val = lv_obj_has_state(objects.obj22, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj22;
            if (new_val) lv_obj_add_state(objects.obj22, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj22, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_shifter_r();
        bool cur_val = lv_obj_has_state(objects.obj23, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj23;
            if (new_val) lv_obj_add_state(objects.obj23, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj23, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_select_game() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.select_game = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 258, 0);
            lv_obj_set_size(obj, 63, 36);
            lv_obj_add_event_cb(obj, action_switch_to_main_screen, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj30 = obj;
            lv_obj_set_pos(obj, 16, 18);
            lv_obj_set_size(obj, 144, 50);
            lv_obj_add_event_cb(obj, action_switch_to_farming_simulator25, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff009244), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(0));
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Farming Simulator\n2025");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 16, 78);
            lv_obj_set_size(obj, 144, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff005792), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "EuroTruck\nSimulator 2");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 16, 137);
            lv_obj_set_size(obj, 144, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff354e5f), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Other Game");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_select_game() {
}

void create_screen_farming_simulator2025() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.farming_simulator2025 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_event_cb(obj, action_fs25_slider1_value, LV_EVENT_VALUE_CHANGED, (void *)0);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 72, 37);
            lv_obj_add_event_cb(obj, action_fs25_button1_released, LV_EVENT_RELEASED, (void *)0);
            lv_obj_add_event_cb(obj, action_fs25_button1_clicked, LV_EVENT_PRESSING, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Button 1");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 82, 0);
            lv_obj_set_size(obj, 72, 37);
            lv_obj_add_event_cb(obj, action_fs25_button2_released, LV_EVENT_RELEASED, (void *)0);
            lv_obj_add_event_cb(obj, action_fs25_button2_clicked, LV_EVENT_PRESSING, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Button 2");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 165, 0);
            lv_obj_set_size(obj, 72, 37);
            lv_obj_add_event_cb(obj, action_fs25_button3_released, LV_EVENT_RELEASED, (void *)0);
            lv_obj_add_event_cb(obj, action_fs25_button3_clicked, LV_EVENT_PRESSING, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Button 3");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 248, 0);
            lv_obj_set_size(obj, 72, 37);
            lv_obj_add_event_cb(obj, action_fs25_button4_released, LV_EVENT_RELEASED, (void *)0);
            lv_obj_add_event_cb(obj, action_fs25_button4_clicked, LV_EVENT_PRESSING, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Button 4");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            lv_obj_set_pos(obj, 85, 110);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 0, 4095);
            lv_obj_add_event_cb(obj, action_fs25_slider1_value, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            lv_obj_set_pos(obj, 85, 142);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 0, 4095);
            lv_obj_add_event_cb(obj, action_fs25_slider2_value, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            lv_obj_set_pos(obj, 85, 174);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 0, 4095);
            lv_obj_add_event_cb(obj, action_fs25_slider3_value, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            lv_obj_set_pos(obj, 85, 205);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 0, 4095);
            lv_obj_add_event_cb(obj, action_fs25_slider4_value, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 249, 204);
            lv_obj_set_size(obj, 72, 37);
            lv_obj_add_event_cb(obj, action_switch_to_main_screen, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 12, 56);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_farming_simulator2025_obj24, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_farming_simulator2025_obj24, LV_EVENT_VALUE_CHANGED, (void *)0);
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, 93, 57);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_farming_simulator2025_obj25, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_farming_simulator2025_obj25, LV_EVENT_VALUE_CHANGED, (void *)0);
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 176, 57);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_farming_simulator2025_obj26, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_farming_simulator2025_obj26, LV_EVENT_VALUE_CHANGED, (void *)0);
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 260, 57);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_farming_simulator2025_obj27, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_farming_simulator2025_obj27, LV_EVENT_VALUE_CHANGED, (void *)0);
        }
    }
}

void tick_screen_farming_simulator2025() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_settings();
    create_screen_main();
    create_screen_calibration();
    create_screen_sensor_status();
    create_screen_select_game();
    create_screen_farming_simulator2025();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_settings,
    tick_screen_main,
    tick_screen_calibration,
    tick_screen_sensor_status,
    tick_screen_select_game,
    tick_screen_farming_simulator2025,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
