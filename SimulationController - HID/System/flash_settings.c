/**
  ******************************************************************************
  * @file    flash_settings.c
  * @brief   Flash-backed persistent settings — table-driven TLV read/write.
  *
  * To add a new setting, see the instructions in flash_settings.h.
  * Only touch this file to add a row to scalar_settings[].
  ******************************************************************************
*/

#include "flash_settings.h"
#include "stm32g4xx_hal.h"
#include <string.h>
#include <stddef.h>

/* ---------------------------------------------------------------------------
 * Setting descriptor table
 *
 * Each row describes one scalar int32_t field in SystemSettings:
 *   SETTING(tlv_type, field_name, default_value)
 * --------------------------------------------------------------------------- */
typedef struct {
    uint16_t type;
    uint16_t offset;      // offsetof(SystemSettings, field)
    int32_t  default_val;
} SettingEntry;

#define SETTING(tlv, field, def) \
    { (tlv), (uint16_t)offsetof(SystemSettings, field), (def) }

static const SettingEntry scalar_settings[] = {
    SETTING(TLV_TYPE_BRIGHTNESS,        brightness,          50),
    SETTING(TLV_TYPE_FREQUENCY,         frequency,           1000),
	SETTING(TLV_TYPE_DEGREES_OF_ROT,    degrees_of_rotation, 900),
    SETTING(TLV_TYPE_WHEEL_PPR,         wheel_ppr,           6000),
    SETTING(TLV_TYPE_FFB,               ffb,                 0),
    SETTING(TLV_TYPE_FFB_GAIN,          ffb_gain,            100),
    SETTING(TLV_TYPE_FFB_MAX_CURRENT,   ffb_max_current_mA,  15000),
    SETTING(TLV_TYPE_FFB_CURRENT_THRESHOLD, ffb_current_threshold, 50),
    SETTING(TLV_TYPE_FFB_SPD_THRESHOLD, ffb_spd_threshold,   10),
    SETTING(TLV_TYPE_FFB_ACL_THRESHOLD, ffb_acl_threshold,   5),
    SETTING(TLV_TYPE_FFB_FRC_THRESHOLD, ffb_frc_threshold,   20),
    SETTING(TLV_TYPE_FFB_SPRING_COEF,   ffb_spring_coef,     50),
    SETTING(TLV_TYPE_FFB_DAMPER_COEF,   ffb_damper_coef,     30),
    SETTING(TLV_TYPE_FFB_FRICTION_COEF, ffb_friction_coef,   25),
    SETTING(TLV_TYPE_FFB_INERTIA_COEF,  ffb_inertia_coef,    40),
};

#define NUM_SCALAR_SETTINGS (sizeof(scalar_settings) / sizeof(scalar_settings[0]))

/* Typed field access via byte offset into the struct */
#define FIELD(s, entry) (*(int32_t *)((uint8_t *)(s) + (entry).offset))

/* ---------------------------------------------------------------------------
 * Internal helpers
 * --------------------------------------------------------------------------- */
static void GetPageAndBank(uint32_t Address, uint32_t *Page, uint32_t *Bank)
{
    uint32_t offset = Address - 0x08000000;
    *Page = offset / FLASH_PAGE_SIZE;

    if (*Page < 128) {
        *Bank = FLASH_BANK_1;
    } else {
        *Bank = FLASH_BANK_2;
        *Page -= 128;
    }
}

/* ---------------------------------------------------------------------------
 * Low-level flash write
 * --------------------------------------------------------------------------- */
uint32_t Flash_Write_Data(uint32_t StartAddress, uint64_t *Data, uint16_t numberofdoublewords)
{
    static FLASH_EraseInitTypeDef EraseInitStruct;
    uint32_t PAGEError;
    int sofar = 0;

    HAL_FLASH_Unlock();

    uint32_t StartPage, StartBank, EndPage, EndBank;
    GetPageAndBank(StartAddress, &StartPage, &StartBank);
    GetPageAndBank(StartAddress + numberofdoublewords * 8, &EndPage, &EndBank);

    EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.Banks     = StartBank;
    EraseInitStruct.Page      = StartPage;
    EraseInitStruct.NbPages   = (EndBank == StartBank)
                                ? (EndPage - StartPage + 1)
                                : (128 - StartPage + EndPage + 1);

    if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK) {
        HAL_FLASH_Lock();
        return HAL_FLASH_GetError();
    }

    while (sofar < numberofdoublewords) {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, StartAddress, Data[sofar]) == HAL_OK) {
            StartAddress += 8;
            sofar++;
        } else {
            HAL_FLASH_Lock();
            return HAL_FLASH_GetError();
        }
    }

    HAL_FLASH_Lock();
    return 0;
}

/* ---------------------------------------------------------------------------
 * Serialise settings → flash
 * --------------------------------------------------------------------------- */
uint32_t Flash_Write_All_Settings(uint32_t StartAddress, SystemSettings *settings)
{
    // Buffer: axes use 4 words each, axis deadzones use 3 words each, scalars use 2 words each
    uint32_t tlv_buf[MAX_AXES * 7 + NUM_SCALAR_SETTINGS * 2 + 4];
    uint32_t ptr = 0;

    // Axis array (special multi-word TLV)
    for (uint8_t i = 0; i < settings->num_axes; i++) {
        tlv_buf[ptr++] = (TLV_TYPE_AXIS << 16) | 12;
        tlv_buf[ptr++] = (uint32_t)(i + 1);
        tlv_buf[ptr++] = (uint32_t)settings->axis_min[i];
        tlv_buf[ptr++] = (uint32_t)settings->axis_max[i];
    }

    // Per-axis deadzone array
    for (uint8_t i = 0; i < MAX_AXES; i++) {
        tlv_buf[ptr++] = (TLV_TYPE_AXIS_DEADZONE << 16) | 8;
        tlv_buf[ptr++] = (uint32_t)(i + 1);
        tlv_buf[ptr++] = (uint32_t)settings->axis_deadzone[i];
    }

    // All scalar settings from table
    for (size_t i = 0; i < NUM_SCALAR_SETTINGS; i++) {
        tlv_buf[ptr++] = ((uint32_t)scalar_settings[i].type << 16) | 4;
        tlv_buf[ptr++] = (uint32_t)FIELD(settings, scalar_settings[i]);
    }

    // Pack pairs of uint32_t into uint64_t doublewords for flash programming
    uint16_t ndw = ptr / 2;
    uint64_t write_buf[sizeof(tlv_buf) / sizeof(uint64_t)];
    for (uint16_t i = 0; i < ndw; i++)
        write_buf[i] = ((uint64_t)tlv_buf[2*i+1] << 32) | tlv_buf[2*i];

    return Flash_Write_Data(StartAddress, write_buf, ndw);
}

/* ---------------------------------------------------------------------------
 * Deserialise settings ← flash
 * --------------------------------------------------------------------------- */
uint32_t Flash_Read_All_Settings(uint32_t StartAddress, SystemSettings *settings)
{
    memset(settings, 0, sizeof(SystemSettings));
    settings->num_axes = MAX_AXES;
    settings->valid    = 1;

    // Apply defaults from table
    for (size_t i = 0; i < NUM_SCALAR_SETTINGS; i++)
        FIELD(settings, scalar_settings[i]) = scalar_settings[i].default_val;

    // Axis defaults
    for (uint8_t i = 0; i < MAX_AXES; i++) {
        settings->axis_min[i] = DEFAULT_AXIS_MIN;
        settings->axis_max[i] = DEFAULT_AXIS_MAX;
    }

    // Parse TLV stream
    uint32_t addr = StartAddress;
    while (1) {
        uint32_t hdr = *(__IO uint32_t *)addr;
        if (hdr == 0xFFFFFFFF) break;  // end of written flash

        uint16_t type   = hdr >> 16;
        uint16_t length = hdr & 0xFFFF;
        addr += 4;

        if (length == 0) { addr += 4; continue; }

        if (type == TLV_TYPE_AXIS) {
            if (length == 12) {
                uint32_t id = *(__IO uint32_t *)addr; addr += 4;
                if (id >= 1 && id <= MAX_AXES) {
                    settings->axis_min[id-1] = *(__IO int32_t *)addr; addr += 4;
                    settings->axis_max[id-1] = *(__IO int32_t *)addr; addr += 4;
                } else { addr += 8; }
            } else { addr += length; }
            continue;
        }

        if (type == TLV_TYPE_AXIS_DEADZONE) {
            if (length == 8) {
                uint32_t id = *(__IO uint32_t *)addr; addr += 4;
                if (id >= 1 && id <= MAX_AXES)
                    settings->axis_deadzone[id-1] = *(__IO int32_t *)addr;
                addr += 4;
            } else { addr += length; }
            continue;
        }

        // Look up type in scalar table
        const SettingEntry *entry = NULL;
        for (size_t i = 0; i < NUM_SCALAR_SETTINGS; i++) {
            if (scalar_settings[i].type == type) { entry = &scalar_settings[i]; break; }
        }

        if (entry && length == 4) {
            FIELD(settings, *entry) = *(__IO int32_t *)addr;
            addr += 4;
        } else {
            addr += length;  // skip unknown or malformed
        }
    }

    settings->num_axes = MAX_AXES;
    return 0;
}

