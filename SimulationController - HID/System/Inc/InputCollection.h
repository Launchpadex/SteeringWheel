#ifndef INPUT_COLLECTION_H
#define INPUT_COLLECTION_H

#include "main.h"
#include "lvgl.h"
#include "vars.h"
#include <stdbool.h>

#define NUMBER_OF_BUTTONS   15
#define ADC1_BUFFERSIZE     3
#define ADC2_BUFFERSIZE     3
#define ADC4_BUFFERSIZE     2
#define MAX_AXES            9



typedef enum {
    AXIS_WHEEL = 0,
    AXIS_THROTTLE,
    AXIS_BRAKE,
    AXIS_CLUTCH,
    AXIS_LH_X,
    AXIS_LH_Y,
    AXIS_LH_SLIDER,
    AXIS_MISKO_X,
    AXIS_MISKO_Y
} AxisId;

typedef struct {
    uint16_t buttons;
    uint16_t wheel;
    uint16_t throttle, brake, clutch;
    uint16_t lh_x, lh_y, lh_slider;
    uint16_t misko_x, misko_y;
} RawInputs;

typedef struct {
    uint16_t values[MAX_AXES];
} MappedAxes;

// 17-byte report (Report ID = 1)
typedef struct __attribute__((packed)) {
    uint8_t  report_id;        // 0x01


    uint16_t steering;   // AXIS_WHEEL
    uint16_t throttle;   // AXIS_THROTTLE
    uint16_t brake;      // AXIS_BRAKE
    uint16_t clutch;     // AXIS_CLUTCH
    uint16_t x_axis;     // AXIS_LH_X
    uint16_t y_axis;     // AXIS_LH_Y
    uint16_t slider;     // AXIS_LH_SLIDER (or Rz)

    // 16 buttons packed into lower 16 bits (only 15 used + 1 padding)
    uint16_t buttons;     // btn1 = bit0, btn15 = bit14

} racing_report_1_t;
extern racing_report_1_t rep1;

typedef struct __attribute__((packed)) {
    uint8_t  report_id;        // 0x04
    uint16_t misko_x;
    uint16_t misko_y;
} racing_report_2_t;

// Matches FLASH_PAGE.h exactly
typedef struct {
    uint32_t axes_to_calibrate[MAX_AXES];
    size_t   num_axes;
    size_t   current_axis_index;
    bool     is_calibrating;
    lv_timer_t *timer;
} CalibrationState;

// === Public API ===
void     Inputs_Init(void);
void     Inputs_CollectAll(RawInputs* out);
void     Inputs_MapAxes(const RawInputs* raw, MappedAxes* mapped);
void Inputs_BuildAndSendReport(const MappedAxes *mapped, uint16_t button_mask_16bit);

const RawInputs* Inputs_GetLatestSnapshot(void);

void     Inputs_StartCalibration(void);
void     Inputs_StopCalibration(void);
bool     Inputs_IsCalibrating(void);

#endif
