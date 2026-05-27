/**
  ******************************************************************************
  * @file    flash_settings.h
  * @brief   Flash-backed persistent settings storage (TLV format).
  *
  * HOW TO ADD A NEW SETTING:
  *   1. Add  #define TLV_TYPE_XXX  <next hex value>  below
  *   2. Add  int32_t xxx;  field to SystemSettings
  *   3. Add  SETTING(TLV_TYPE_XXX, xxx, default)  row to scalar_settings[] in flash_settings.c
  *   Read, write, and defaults all work automatically.
  ******************************************************************************
*/

#ifndef FLASH_SETTINGS_H
#define FLASH_SETTINGS_H

#include "stm32g4xx_hal.h"
#include <stdint.h>
#include "InputCollection.h"

// Flash address: last 2 KB page of STM32G474xx (page 255, Bank 2)
#define FLASH_PAGE_ADDRESS          0x0807F800U

// TLV type IDs — 0x01 reserved for axis array, scalars start at 0x02
#define TLV_TYPE_AXIS               0x01
#define TLV_TYPE_BRIGHTNESS         0x02
#define TLV_TYPE_FREQUENCY          0x03
#define TLV_TYPE_FFB                0x04
#define TLV_TYPE_DEGREES_OF_ROT     0x05
#define TLV_TYPE_FFB_GAIN           0x06
#define TLV_TYPE_FFB_MAX_CURRENT    0x07
#define TLV_TYPE_FFB_SPD_THRESHOLD  0x08
#define TLV_TYPE_FFB_ACL_THRESHOLD  0x09
#define TLV_TYPE_FFB_FRC_THRESHOLD  0x0A
#define TLV_TYPE_FFB_SPRING_COEF    0x0B
#define TLV_TYPE_FFB_DAMPER_COEF    0x0C
#define TLV_TYPE_FFB_FRICTION_COEF  0x0D
#define TLV_TYPE_FFB_INERTIA_COEF   0x0E
#define TLV_TYPE_AXIS_DEADZONE      0x0F
#define TLV_TYPE_WHEEL_PPR          0x10
#define TLV_TYPE_FFB_CURRENT_THRESHOLD  0x11
// Next free ID: 0x12

// Axis calibration defaults
#define DEFAULT_NUM_AXES            9
#define DEFAULT_AXIS_MIN            0
#define DEFAULT_AXIS_MAX            4096

// All persistent state — every scalar field must be int32_t for table-driven I/O
typedef struct {
    uint16_t axis_min[MAX_AXES];
    uint16_t axis_max[MAX_AXES];
    int32_t  axis_deadzone[MAX_AXES];   /* 0 = use global deadzone */
    uint8_t  num_axes;
    uint8_t  valid;
    // --- scalar settings (must stay int32_t) ---
    int32_t  brightness;
    int32_t  frequency;
    int32_t  degrees_of_rotation;
    int32_t  wheel_ppr;   // already includes ×4 (e.g. 600PPR encoder → enter 2400)
    int32_t  ffb;               // 0 = off, 1 = on
    int32_t  ffb_gain;
    int32_t  ffb_max_current_mA;
    int32_t  ffb_current_threshold;
    int32_t  ffb_spd_threshold;
    int32_t  ffb_acl_threshold;
    int32_t  ffb_frc_threshold;
    int32_t  ffb_spring_coef;
    int32_t  ffb_damper_coef;
    int32_t  ffb_friction_coef;
    int32_t  ffb_inertia_coef;
} SystemSettings;

// Flash API
uint32_t Flash_Write_All_Settings(uint32_t StartAddress, SystemSettings *settings);
uint32_t Flash_Read_All_Settings(uint32_t StartAddress, SystemSettings *settings);
uint32_t Flash_Write_Data(uint32_t StartAddress, uint64_t *Data, uint16_t numberofdoublewords);


#endif // FLASH_SETTINGS_H
