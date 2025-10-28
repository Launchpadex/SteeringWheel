/**
  ***************************************************************************************************************
  File:       FLASH_PAGE.h
  Modifier:   ControllersTech.com, modified for STM32G4, TLV support, and user-friendly API
  Updated:    03rd October 2025
  ***************************************************************************************************************
  Copyright (C) 2017 ControllersTech.com
  This is a free software under the GNU license, you can redistribute it and/or modify it under the terms
  of the GNU General Public License version 3 as published by the Free Software Foundation.
  This software library is shared with public for educational purposes, without WARRANTY and Author is not liable for any damages caused directly
  or indirectly by this software, read more about this on the GNU General Public License.
  ***************************************************************************************************************
*/

#ifndef FLASH_PAGE_H
#define FLASH_PAGE_H

#include "stm32g4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>
#include "InputCollection.h"

// Fixed start address for the last flash page (STM32G474xx: page 255, Bank 2, 2 KB page)
// Usage: Use this as the default StartAddress for Flash_Write_All_Settings/Flash_Read_All_Settings.
// Capacity: Up to ~2048 bytes (e.g., 169 axes + brightness + frequency). Bounds checking prevents overflow.
#define FLASH_PAGE_ADDRESS 0x0807F800U

// TLV structure definitions
#define TLV_TYPE_AXIS 0x01       // Length 12: uint32_t axis_id, int32_t min, int32_t max
#define TLV_TYPE_BRIGHTNESS 0x02 // Length 4: int32_t brightness
#define TLV_TYPE_FREQUENCY 0x03  // Length 4: int32_t frequency
#define TLV_TYPE_FFB 0x04		 // Length 4: bool FFB

// System settings structure (all data in one place)
typedef struct {
    int32_t axis_min[MAX_AXES];    // Min values for up to 8 axes (index = axis_id - 1)
    int32_t axis_max[MAX_AXES];    // Max values for up to 8 axes (index = axis_id - 1)
    uint8_t num_axes;       // Number of valid axes
    int32_t brightness;     // Display brightness
    int32_t frequency;      // Sampling Frequency
    bool	ffb;			// Forcefeedback on/off
    uint8_t valid;          // Flag: 1 if all settings are valid, 0 if partial/missing
} SystemSettings;

// Function prototypes
uint32_t Flash_Write_All_Settings(uint32_t StartAddress, SystemSettings *settings);
uint32_t Flash_Read_All_Settings(uint32_t StartAddress, SystemSettings *settings);
uint32_t Flash_Write_Data(uint32_t StartAddress, uint64_t *Data, uint16_t numberofdoublewords);
void Flash_Read_Data(uint32_t StartAddress, uint64_t *RxBuf, uint16_t numberofdoublewords);

#endif // FLASH_PAGE_H
