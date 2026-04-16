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

static void event_handler_cb_main_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_main_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_main_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_settings_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_settings_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_settings_brigthness_slider(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 5, 3, value, "Failed to assign Value in Slider widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_settings_btn_save_settings(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_settings_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 8, e);
    }
}

static void event_handler_cb_settings_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_settings_sampling_freq_selector(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            assignIntegerProperty(flowState, 12, 4, value, "Failed to assign Selected in Dropdown widget");
        }
    }
}

static void event_handler_cb_settings_obj7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_ffb_settings_obj8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_ffb_settings_ffb_switch(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 3, 3, value, "Failed to assign Checked state");
        }
    }
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 9, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 10, e);
    }
}

static void event_handler_cb_ffb_settings_ffb_settings_selector(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            assignIntegerProperty(flowState, 5, 4, value, "Failed to assign Selected in Dropdown widget");
        }
    }
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        action_ffb_setting_selected(e);
    }
}

static void event_handler_cb_ffb_settings_obj9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 12, e);
    }
}

static void event_handler_cb_ffb_settings_decrease_btn(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_btn_increase_decrease_handler(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        e->user_data = (void *)0;
        action_btn_increase_decrease_handler(e);
    }
    if (event == LV_EVENT_LONG_PRESSED_REPEAT) {
        e->user_data = (void *)0;
        action_btn_increase_decrease_handler(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_btn_increase_decrease_handler(e);
    }
}

static void event_handler_cb_ffb_settings_increase_btn(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_btn_increase_decrease_handler(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        e->user_data = (void *)0;
        action_btn_increase_decrease_handler(e);
    }
    if (event == LV_EVENT_LONG_PRESSED_REPEAT) {
        e->user_data = (void *)0;
        action_btn_increase_decrease_handler(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_btn_increase_decrease_handler(e);
    }
}

static void event_handler_cb_calibration_obj10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_calibration_obj11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 14, e);
    }
}

static void event_handler_cb_calibration_wheel_calib_cb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 6, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_calibration_l_joy_calib_cb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 7, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_calibration_pedals_calib_cb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 8, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_calibration_misko_joy_calib_cb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 9, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_calibration_obj12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 15, e);
    }
}

static void event_handler_cb_calibration_indication_obj13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 16, e);
    }
}

static void event_handler_cb_sensor_status_obj14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_sensor_status_obj15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 21, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 22, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj17(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 23, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj18(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 24, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 25, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj20(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 26, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj21(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 27, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj22(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 28, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj23(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 29, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj24(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 30, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj25(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 31, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj26(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 32, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj27(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 33, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj28(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 34, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_sensor_status_obj29(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 35, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_select_game_obj30(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_select_game_obj31(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_farming_simulator2025_farming_simulator2025(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 19, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj32(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 17, e);
    }
    if (event == LV_EVENT_PRESSING) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 18, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj33(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 20, e);
    }
    if (event == LV_EVENT_PRESSING) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 21, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj34(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 22, e);
    }
    if (event == LV_EVENT_PRESSING) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 23, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj35(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 24, e);
    }
    if (event == LV_EVENT_PRESSING) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 25, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj36(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 19, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj37(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 26, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj38(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 27, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj39(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 28, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj40(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj41(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 29, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 30, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj42(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 31, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 32, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj43(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 33, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 34, e);
    }
}

static void event_handler_cb_farming_simulator2025_obj44(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 35, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 36, e);
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
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
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SteeringWheel\nPowered By Misko");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 177, 109);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj0, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "SensorStatus");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 42, 109);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj1, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "SelectGame");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 255, 210);
            lv_obj_set_size(obj, 65, 30);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj2, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Settings");
                }
            }
        }
        {
            // Calibration_Status_Main
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.calibration_status_main = obj;
            lv_obj_set_pos(obj, 91, 202);
            lv_obj_set_size(obj, 138, LV_SIZE_CONTENT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // ForceFeedback_Status_Main
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.force_feedback_status_main = obj;
            lv_obj_set_pos(obj, 92, 53);
            lv_obj_set_size(obj, 135, LV_SIZE_CONTENT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_test);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 85, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_test1);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.calibration_status_main);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.calibration_status_main;
            lv_label_set_text(objects.calibration_status_main, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.force_feedback_status_main);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.force_feedback_status_main;
            lv_label_set_text(objects.force_feedback_status_main, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_settings() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 257, 0);
            lv_obj_set_size(obj, 63, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_obj3, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 103, 0);
            lv_obj_set_size(obj, 115, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_obj4, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Calibaration");
                }
            }
        }
        {
            // brigthness_slider
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.brigthness_slider = obj;
            lv_obj_set_pos(obj, 143, 156);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 10, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_brigthness_slider, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 29, 153);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Brightness");
        }
        {
            // BTN_SaveSettings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.btn_save_settings = obj;
            lv_obj_set_pos(obj, -1, 204);
            lv_obj_set_size(obj, 116, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_btn_save_settings, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Save Settings");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 205, 204);
            lv_obj_set_size(obj, 115, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_obj5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff006d1a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 115, LV_SIZE_CONTENT);
                    lv_obj_add_event_cb(obj, event_handler_cb_settings_obj6, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Set Wheel center");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 31, 70);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Sampling\nfrequency");
        }
        {
            // Sampling_freq_selector
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.sampling_freq_selector = obj;
            lv_obj_set_pos(obj, 138, 68);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "");
            lv_obj_add_event_cb(obj, event_handler_cb_settings_sampling_freq_selector, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 63, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_obj7, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "FFB");
                }
            }
        }
    }
    
    tick_screen_settings();
}

void tick_screen_settings() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    {
        int32_t new_val = evalIntegerProperty(flowState, 5, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.brigthness_slider);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.brigthness_slider;
            lv_slider_set_value(objects.brigthness_slider, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 12, 3, "Failed to evaluate Options in Dropdown widget", "\n");
        const char *cur_val = lv_dropdown_get_options(objects.sampling_freq_selector);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.sampling_freq_selector;
            lv_dropdown_set_options(objects.sampling_freq_selector, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.sampling_freq_selector) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 12, 4, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.sampling_freq_selector);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.sampling_freq_selector;
                lv_dropdown_set_selected(objects.sampling_freq_selector, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void create_screen_ffb_settings() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.ffb_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 257, 0);
            lv_obj_set_size(obj, 63, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_ffb_settings_obj8, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            // FFB_Switch
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.ffb_switch = obj;
            lv_obj_set_pos(obj, 157, 6);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_ffb_settings_ffb_switch, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 10, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ForceFeedback");
        }
        {
            // ffb_settings_selector
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.ffb_settings_selector = obj;
            lv_obj_set_pos(obj, 125, 45);
            lv_obj_set_size(obj, 187, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "");
            lv_obj_add_event_cb(obj, event_handler_cb_ffb_settings_ffb_settings_selector, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 17, 55);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Select Option");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj45 = obj;
            lv_obj_set_pos(obj, 102, 99);
            lv_obj_set_size(obj, 115, 16);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 104, 204);
            lv_obj_set_size(obj, 112, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_ffb_settings_obj9, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Save");
                }
            }
        }
        {
            // Decrease_btn
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.decrease_btn = obj;
            lv_obj_set_pos(obj, 37, 137);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_ffb_settings_decrease_btn, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Decrease");
                }
            }
        }
        {
            // Increase_btn
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.increase_btn = obj;
            lv_obj_set_pos(obj, 188, 137);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_ffb_settings_increase_btn, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Increase");
                }
            }
        }
    }
    
    tick_screen_ffb_settings();
}

void tick_screen_ffb_settings() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    {
        bool new_val = evalBooleanProperty(flowState, 3, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.ffb_switch, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.ffb_switch;
            if (new_val) lv_obj_add_state(objects.ffb_switch, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.ffb_switch, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 5, 3, "Failed to evaluate Options in Dropdown widget", "\n");
        const char *cur_val = lv_dropdown_get_options(objects.ffb_settings_selector);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.ffb_settings_selector;
            lv_dropdown_set_options(objects.ffb_settings_selector, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.ffb_settings_selector) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 5, 4, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.ffb_settings_selector);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.ffb_settings_selector;
                lv_dropdown_set_selected(objects.ffb_settings_selector, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj45);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj45;
            lv_label_set_text(objects.obj45, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_calibration() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.calibration = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN_HOR);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 0, 204);
            lv_obj_set_size(obj, 63, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_obj10, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 126, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_obj11, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Start Calibration");
                }
            }
        }
        {
            // Calibration_Status_Calibration
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.calibration_status_calibration = obj;
            lv_obj_set_pos(obj, 60, 214);
            lv_obj_set_size(obj, 200, LV_SIZE_CONTENT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // WHEEL_CALIB_CB
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.wheel_calib_cb = obj;
            lv_obj_set_pos(obj, 13, 41);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Wheel");
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_wheel_calib_cb, LV_EVENT_ALL, flowState);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // L_JOY_CALIB_CB
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.l_joy_calib_cb = obj;
            lv_obj_set_pos(obj, 13, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Left JOY");
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_l_joy_calib_cb, LV_EVENT_ALL, flowState);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // PEDALS_CALIB_CB
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.pedals_calib_cb = obj;
            lv_obj_set_pos(obj, 13, 80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Pedals");
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_pedals_calib_cb, LV_EVENT_ALL, flowState);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // MISKO_JOY_CALIB_CB
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.misko_joy_calib_cb = obj;
            lv_obj_set_pos(obj, 13, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Misko JOY");
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_misko_joy_calib_cb, LV_EVENT_ALL, flowState);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 194, 0);
            lv_obj_set_size(obj, 126, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_obj12, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffc4d4d), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Reset Calibration");
                }
            }
        }
    }
    
    tick_screen_calibration();
}

void tick_screen_calibration() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.calibration_status_calibration);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.calibration_status_calibration;
            lv_label_set_text(objects.calibration_status_calibration, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 6, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.wheel_calib_cb, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.wheel_calib_cb;
            if (new_val) lv_obj_add_state(objects.wheel_calib_cb, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.wheel_calib_cb, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 7, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.l_joy_calib_cb, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.l_joy_calib_cb;
            if (new_val) lv_obj_add_state(objects.l_joy_calib_cb, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.l_joy_calib_cb, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 8, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.pedals_calib_cb, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.pedals_calib_cb;
            if (new_val) lv_obj_add_state(objects.pedals_calib_cb, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.pedals_calib_cb, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.misko_joy_calib_cb, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.misko_joy_calib_cb;
            if (new_val) lv_obj_add_state(objects.misko_joy_calib_cb, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.misko_joy_calib_cb, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_calibration_indication() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.calibration_indication = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 230, 0);
            lv_obj_set_size(obj, 90, 41);
            lv_obj_add_event_cb(obj, event_handler_cb_calibration_indication_obj13, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff6262), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Stop\nCalibration");
                }
            }
        }
        {
            // Calibration_Status_Calibration_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.calibration_status_calibration_1 = obj;
            lv_obj_set_pos(obj, 0, 224);
            lv_obj_set_size(obj, 320, LV_SIZE_CONTENT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj46 = obj;
            lv_obj_set_pos(obj, 15, 47);
            lv_obj_set_size(obj, 291, 177);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_calibration_indication();
}

void tick_screen_calibration_indication() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 3, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.calibration_status_calibration_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.calibration_status_calibration_1;
            lv_label_set_text(objects.calibration_status_calibration_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 4, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj46);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj46;
            lv_label_set_text(objects.obj46, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_sensor_status() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.sensor_status = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 257, 0);
            lv_obj_set_size(obj, 63, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj14, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            // status_wheel
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.status_wheel = obj;
            lv_obj_set_pos(obj, 50, 6);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 65535);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 7, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Wheel");
        }
        {
            // status_throttle
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.status_throttle = obj;
            lv_obj_set_pos(obj, 50, 18);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 65535);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 4, 18);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Throttle");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 9, 30);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Brake");
        }
        {
            // status_brake
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.status_brake = obj;
            lv_obj_set_pos(obj, 50, 30);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 65535);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 7, 42);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Clutch");
        }
        {
            // status_clutch
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.status_clutch = obj;
            lv_obj_set_pos(obj, 50, 42);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 65535);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 54);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Joy_x");
        }
        {
            // status_misko_x
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.status_misko_x = obj;
            lv_obj_set_pos(obj, 50, 54);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 65535);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 66);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Joy_y");
        }
        {
            // status_misko_y
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.status_misko_y = obj;
            lv_obj_set_pos(obj, 50, 66);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 65535);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 78);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LH_X");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 89);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LH_Y");
        }
        {
            // status_lh_x
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.status_lh_x = obj;
            lv_obj_set_pos(obj, 50, 78);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 65535);
        }
        {
            // status_lh_y
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.status_lh_y = obj;
            lv_obj_set_pos(obj, 50, 90);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 65535);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 101);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LH_R");
        }
        {
            // status_lh_slider
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.status_lh_slider = obj;
            lv_obj_set_pos(obj, 50, 102);
            lv_obj_set_size(obj, 110, 11);
            lv_bar_set_range(obj, 0, 65535);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 13, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_ESC");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj15, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 13, 148);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_OK");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj16, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 13, 176);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_LEFT");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj17, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 13, 190);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_RIGHT");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj18, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 13, 204);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_DOWN");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj19, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 13, 162);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_UP");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj20, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj21 = obj;
            lv_obj_set_pos(obj, 101, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "LH_BTN1");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj21, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 101, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "LH_BTN2");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj22, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 187, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BASE_BTN1");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj23, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 187, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BASE_BTN2");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj24, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, 187, 148);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BASE_BTN3");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj25, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 187, 162);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BASE_BTN4");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj26, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 13, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "BTN_JOY");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj27, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 101, 162);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "SHIFTER_L");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj28, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 101, 176);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "SHIFTER_R");
            lv_obj_add_event_cb(obj, event_handler_cb_sensor_status_obj29, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_sensor_status();
}

void tick_screen_sensor_status() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    {
        int32_t new_val = evalIntegerProperty(flowState, 3, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.status_wheel);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.status_wheel;
            lv_bar_set_value(objects.status_wheel, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 5, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.status_throttle);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.status_throttle;
            lv_bar_set_value(objects.status_throttle, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 8, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.status_brake);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.status_brake;
            lv_bar_set_value(objects.status_brake, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 10, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.status_clutch);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.status_clutch;
            lv_bar_set_value(objects.status_clutch, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 12, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.status_misko_x);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.status_misko_x;
            lv_bar_set_value(objects.status_misko_x, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 14, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.status_misko_y);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.status_misko_y;
            lv_bar_set_value(objects.status_misko_y, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 17, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.status_lh_x);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.status_lh_x;
            lv_bar_set_value(objects.status_lh_x, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 18, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.status_lh_y);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.status_lh_y;
            lv_bar_set_value(objects.status_lh_y, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 20, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.status_lh_slider);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.status_lh_slider;
            lv_bar_set_value(objects.status_lh_slider, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 21, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj15, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj15;
            if (new_val) lv_obj_add_state(objects.obj15, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj15, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 22, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj16, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj16;
            if (new_val) lv_obj_add_state(objects.obj16, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj16, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 23, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj17, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj17;
            if (new_val) lv_obj_add_state(objects.obj17, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj17, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 24, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj18, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj18;
            if (new_val) lv_obj_add_state(objects.obj18, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj18, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 25, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj19, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj19;
            if (new_val) lv_obj_add_state(objects.obj19, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj19, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 26, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj20, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj20;
            if (new_val) lv_obj_add_state(objects.obj20, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj20, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 27, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj21, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj21;
            if (new_val) lv_obj_add_state(objects.obj21, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj21, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 28, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj22, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj22;
            if (new_val) lv_obj_add_state(objects.obj22, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj22, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 29, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj23, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj23;
            if (new_val) lv_obj_add_state(objects.obj23, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj23, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 30, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj24, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj24;
            if (new_val) lv_obj_add_state(objects.obj24, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj24, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 31, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj25, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj25;
            if (new_val) lv_obj_add_state(objects.obj25, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj25, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 32, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj26, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj26;
            if (new_val) lv_obj_add_state(objects.obj26, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj26, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 33, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj27, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj27;
            if (new_val) lv_obj_add_state(objects.obj27, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj27, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 34, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj28, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj28;
            if (new_val) lv_obj_add_state(objects.obj28, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj28, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 35, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj29, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj29;
            if (new_val) lv_obj_add_state(objects.obj29, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj29, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_select_game() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.select_game = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj30 = obj;
            lv_obj_set_pos(obj, 258, 0);
            lv_obj_set_size(obj, 62, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_select_game_obj30, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 16, 18);
            lv_obj_set_size(obj, 144, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_select_game_obj31, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff009244), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(0));
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Farming Simulator\n2025");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj47 = obj;
            lv_obj_set_pos(obj, 16, 78);
            lv_obj_set_size(obj, 144, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff005792), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "EuroTruck\nSimulator 2");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj48 = obj;
            lv_obj_set_pos(obj, 16, 137);
            lv_obj_set_size(obj, 144, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff354e5f), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Other Game");
                }
            }
        }
    }
    
    tick_screen_select_game();
}

void tick_screen_select_game() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
}

void create_screen_farming_simulator2025() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.farming_simulator2025 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_farming_simulator2025, LV_EVENT_ALL, flowState);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 72, 37);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj32, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Button 1");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj33 = obj;
            lv_obj_set_pos(obj, 82, 0);
            lv_obj_set_size(obj, 72, 37);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj33, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Button 2");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj34 = obj;
            lv_obj_set_pos(obj, 165, 0);
            lv_obj_set_size(obj, 72, 37);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj34, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Button 3");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj35 = obj;
            lv_obj_set_pos(obj, 248, 0);
            lv_obj_set_size(obj, 72, 37);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj35, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Button 4");
                }
            }
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.obj36 = obj;
            lv_obj_set_pos(obj, 85, 110);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 0, 4095);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj36, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.obj37 = obj;
            lv_obj_set_pos(obj, 85, 142);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 0, 4095);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj37, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.obj38 = obj;
            lv_obj_set_pos(obj, 85, 174);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 0, 4095);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj38, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.obj39 = obj;
            lv_obj_set_pos(obj, 85, 205);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 0, 4095);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj39, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj40 = obj;
            lv_obj_set_pos(obj, 249, 204);
            lv_obj_set_size(obj, 72, 37);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj40, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj41 = obj;
            lv_obj_set_pos(obj, 12, 56);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj41, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj42 = obj;
            lv_obj_set_pos(obj, 93, 57);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj42, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj43 = obj;
            lv_obj_set_pos(obj, 176, 57);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj43, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj44 = obj;
            lv_obj_set_pos(obj, 260, 57);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_farming_simulator2025_obj44, LV_EVENT_ALL, flowState);
        }
    }
    
    tick_screen_farming_simulator2025();
}

void tick_screen_farming_simulator2025() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
}


static const char *screen_names[] = { "Main", "Settings", "FFBSettings", "Calibration", "CalibrationIndication", "SensorStatus", "SelectGame", "FarmingSimulator2025" };
static const char *object_names[] = { "main", "settings", "ffb_settings", "calibration", "calibration_indication", "sensor_status", "select_game", "farming_simulator2025", "obj0", "obj1", "obj2", "obj3", "obj4", "brigthness_slider", "btn_save_settings", "obj5", "obj6", "obj7", "obj8", "ffb_switch", "ffb_settings_selector", "obj9", "decrease_btn", "increase_btn", "obj10", "obj11", "wheel_calib_cb", "l_joy_calib_cb", "pedals_calib_cb", "misko_joy_calib_cb", "obj12", "obj13", "obj14", "obj15", "obj16", "obj17", "obj18", "obj19", "obj20", "obj21", "obj22", "obj23", "obj24", "obj25", "obj26", "obj27", "obj28", "obj29", "obj30", "obj31", "obj32", "obj33", "obj34", "obj35", "obj36", "obj37", "obj38", "obj39", "obj40", "obj41", "obj42", "obj43", "obj44", "calibration_status_main", "force_feedback_status_main", "sampling_freq_selector", "obj45", "calibration_status_calibration", "calibration_status_calibration_1", "obj46", "status_wheel", "status_throttle", "status_brake", "status_clutch", "status_misko_x", "status_misko_y", "status_lh_x", "status_lh_y", "status_lh_slider", "obj47", "obj48" };


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_settings,
    tick_screen_ffb_settings,
    tick_screen_calibration,
    tick_screen_calibration_indication,
    tick_screen_sensor_status,
    tick_screen_select_game,
    tick_screen_farming_simulator2025,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_settings();
    create_screen_ffb_settings();
    create_screen_calibration();
    create_screen_calibration_indication();
    create_screen_sensor_status();
    create_screen_select_game();
    create_screen_farming_simulator2025();
}
