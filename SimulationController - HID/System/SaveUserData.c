#include "FLASH_PAGE.h"
#include "SaveUserData.h"

// Declare external global system_settings
extern SystemSettings system_settings;

int8_t SaveAxisData(uint32_t axis_id, int32_t min, int32_t max)
{
    // Validate axis_id (must be 1 to MAX_AXES)
    if (axis_id < 1 || axis_id > MAX_AXES) {
        return 1; // Invalid axis_id
    }

    // Update the global system_settings
    system_settings.axis_min[axis_id - 1] = min;
    system_settings.axis_max[axis_id - 1] = max;
    // Update num_axes if the axis_id is higher than current num_axes
    if (axis_id > system_settings.num_axes) {
        system_settings.num_axes = axis_id;
    }
    system_settings.valid = 1;
    return 0;
}

uint32_t SaveSystemData(uint8_t type, int32_t value)
{
    // Validate type
    if (type != TLV_TYPE_BRIGHTNESS && type != TLV_TYPE_FREQUENCY && type != TLV_TYPE_FFB) {
        return 2; // Invalid setting type
    }

    // Update the global system_settings based on type
    if (type == TLV_TYPE_BRIGHTNESS) {
        system_settings.brightness = value;
    } else if (type == TLV_TYPE_FREQUENCY) {
        system_settings.frequency = value;
    } else if (type == TLV_TYPE_FFB) {
        system_settings.ffb = (bool)value; // Cast to bool for FFB
    }

    system_settings.valid = 1;

    // Write the updated settings to flash
    return Flash_Write_All_Settings(FLASH_PAGE_ADDRESS, &system_settings);
}
