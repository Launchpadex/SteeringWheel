#ifndef SAVE_USER_DATA_H
#define SAVE_USER_DATA_H

#include "FLASH_PAGE.h"

// Default values
#define DEFAULT_NUM_AXES     8
#define DEFAULT_AXIS_MIN     0
#define DEFAULT_AXIS_MAX     4096
#define DEFAULT_BRIGHTNESS   50
#define DEFAULT_FREQUENCY    1000

// Function prototype to save a single axis
int8_t SaveAxisData(uint32_t axis_id, int32_t min, int32_t max);
uint32_t SaveSystemData(uint8_t type, int32_t value);


#endif // SAVE_USER_DATA_H
