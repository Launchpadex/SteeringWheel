/*
 * sensor_flow_update.cpp
 *
 * Pushes live sensor data into EEZ Flow global variables so that
 * the EEZ-generated tick_screen_sensor_status() can display them.
 *
 * Axes use mapped values (0-65535). Bar widgets should have range 0-65535.
 * Call update_sensor_flow_vars() from the main loop (before lv_timer_handler).
 */

#include "eez-flow.h"
#include "vars.h"           // FlowGlobalVariables enum
#include "InputCollection.h" // MappedAxes, RawInputs, getters

using namespace eez;
using namespace eez::flow;

extern "C" void update_sensor_flow_vars(void)
{
    const MappedAxes *mapped = Inputs_GetLatestMappedAxes();
    const RawInputs  *raw    = Inputs_GetLatestSnapshot();

    /* Analog axes — mapped values 0-65535 */
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_WHEEL,    IntegerValue((int32_t)mapped->values[AXIS_WHEEL]));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_THROTTLE, IntegerValue((int32_t)mapped->values[AXIS_THROTTLE]));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BRAKE,    IntegerValue((int32_t)mapped->values[AXIS_BRAKE]));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_CLUTCH,   IntegerValue((int32_t)mapped->values[AXIS_CLUTCH]));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_LH_X,     IntegerValue((int32_t)mapped->values[AXIS_LH_X]));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_LH_Y,     IntegerValue((int32_t)mapped->values[AXIS_LH_Y]));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_LH_R,     IntegerValue((int32_t)mapped->values[AXIS_LH_SLIDER]));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_JOY_X,    IntegerValue((int32_t)mapped->values[AXIS_MISKO_X]));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_JOY_Y,    IntegerValue((int32_t)mapped->values[AXIS_MISKO_Y]));

    /* Digital buttons — 15 buttons packed in raw->buttons, LSB = btn 0 */
    uint16_t b = raw->buttons;
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_JOY,   BooleanValue((bool)((b >>  0) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_ESC,   BooleanValue((bool)((b >>  1) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_OK,    BooleanValue((bool)((b >>  2) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_UP,    BooleanValue((bool)((b >>  3) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_LEFT,  BooleanValue((bool)((b >>  4) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_RIGHT, BooleanValue((bool)((b >>  5) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BTN_DOWN,  BooleanValue((bool)((b >>  6) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_LH_BTN1,   BooleanValue((bool)((b >>  7) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_LH_BTN2,   BooleanValue((bool)((b >>  8) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BASE_BTN1, BooleanValue((bool)((b >>  9) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BASE_BTN2, BooleanValue((bool)((b >> 10) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BASE_BTN3, BooleanValue((bool)((b >> 11) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_BASE_BTN4, BooleanValue((bool)((b >> 12) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_SHIFTER_L, BooleanValue((bool)((b >> 13) & 1U)));
    setGlobalVariable(FLOW_GLOBAL_VARIABLE_SHIFTER_R, BooleanValue((bool)((b >> 14) & 1U)));
}
