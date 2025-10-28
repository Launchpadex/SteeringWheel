#ifndef INPUT_COLLECTION_H
#define INPUT_COLLECTION_H

#include "main.h"
#include "vars.h"
#include "lvgl.h"

// Define number of buttons
#define NUMBER_OF_BUTTONS 15
#define ADC1_BUFFERSIZE 3
#define ADC2_BUFFERSIZE 3
#define ADC4_BUFFERSIZE 2

#define MAX_AXES 9

typedef struct {
    uint32_t axes_to_calibrate[MAX_AXES];
    size_t num_axes;
    size_t current_axis_index;
    bool is_calibrating;
    lv_timer_t *timer;
} CalibrationState;

// Extern variable declarations
extern int16_t Button_States[NUMBER_OF_BUTTONS];
extern uint16_t Encoder_Value;
extern uint16_t adc1_values[ADC1_BUFFERSIZE]; // Throttle, Brake, Clutch
extern uint16_t adc2_values[ADC2_BUFFERSIZE]; // Left-Hand X, Y
extern uint16_t adc4_values[ADC4_BUFFERSIZE]; // Misko X, Y

extern char sampling_frequency_str[32];

// Function prototypes
void InitADC(void);
void CollectButton_StatesMisko(int16_t states[]);
void CollectEncoderValue(uint16_t *encoder_value);
void CollectAllInputs(void);
void Set_Sampling_Frequency(int32_t frequency_hz);
void Read_Actual_Sampling_Frequency(uint32_t cycle_count_delta, char* output_str, size_t str_size);
void CalibrateAxis(const uint32_t* axis_ids, size_t num_axes);
void start_calibration(void);
void stop_calibration(void);

#endif /* INPUT_COLLECTION_H */
