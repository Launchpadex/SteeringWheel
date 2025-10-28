/**
  ***************************************************************************************************************
  File:       FLASH_PAGE.c
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

#include "FLASH_PAGE.h"
#include "SaveUserData.h"
#include "stm32g4xx_hal.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

static void GetPageAndBank(uint32_t Address, uint32_t *Page, uint32_t *Bank)
{
    // STM32G474xx flash base address is 0x08000000
    // Page size is 2 KB (0x800), 512 KB total flash, dual-bank support
    uint32_t offset = Address - 0x08000000;
    *Page = offset / FLASH_PAGE_SIZE;

    // STM32G474xx has dual-bank flash (256 KB per bank)
    if (*Page < 128) {
        *Bank = FLASH_BANK_1; // Pages 0-127
    } else {
        *Bank = FLASH_BANK_2; // Pages 128-255
        *Page -= 128;
    }
}

uint32_t Flash_Write_All_Settings(uint32_t StartAddress, SystemSettings *settings)
{
    // Build TLV buffer using uint32_t for alignment
    uint32_t tlv_buffer[64]; // Sufficient size for multiple TLVs
    uint32_t ptr = 0;

    // Add axes
    for (uint8_t i = 0; i < settings->num_axes; i++) {
        uint32_t axis_id = i + 1;
        tlv_buffer[ptr++] = (TLV_TYPE_AXIS << 16) | 12;
        tlv_buffer[ptr++] = axis_id;
        tlv_buffer[ptr++] = (uint32_t)settings->axis_min[i];
        tlv_buffer[ptr++] = (uint32_t)settings->axis_max[i];
    }

    // Add brightness
    tlv_buffer[ptr++] = (TLV_TYPE_BRIGHTNESS << 16) | 4;
    tlv_buffer[ptr++] = (uint32_t)settings->brightness;

    // Add frequency
    tlv_buffer[ptr++] = (TLV_TYPE_FREQUENCY << 16) | 4;
    tlv_buffer[ptr++] = (uint32_t)settings->frequency;

    // Add force feedback
    tlv_buffer[ptr++] = (TLV_TYPE_FFB << 16) | 4;
    tlv_buffer[ptr++] = (uint32_t)settings->ffb;

    // Pad to even number of uint32_t for uint64_t alignment if necessary
    if (ptr % 2 != 0) {
        tlv_buffer[ptr++] = 0xFFFFFFFF; // Padding with erased value
    }

    // Convert to uint64_t for writing
    uint16_t numberofdoublewords = ptr / 2;
    uint64_t write_buffer[32];
    for (uint32_t i = 0; i < numberofdoublewords; i++) {
        write_buffer[i] = ((uint64_t)tlv_buffer[2 * i + 1] << 32) | tlv_buffer[2 * i];
    }

    // Write to flash
    return Flash_Write_Data(StartAddress, write_buffer, numberofdoublewords);
}

uint32_t Flash_Read_All_Settings(uint32_t StartAddress, SystemSettings *settings)
{
    // Initialize defaults
    memset(settings, 0, sizeof(SystemSettings));
    settings->num_axes = DEFAULT_NUM_AXES;
    settings->brightness = DEFAULT_BRIGHTNESS;
    settings->frequency = DEFAULT_FREQUENCY;
    settings->ffb = false; // Default for FFB
    settings->valid = 1;   // Assume valid until proven otherwise

    uint32_t addr = StartAddress;
    uint8_t axes_found = 0;

    while (1) {
        uint32_t tlvHeader = *(__IO uint32_t *)addr;
        if (tlvHeader == 0xFFFFFFFF) break; // End of TLVs (erased flash)

        uint16_t type = tlvHeader >> 16;
        uint16_t length = tlvHeader & 0xFFFF;
        addr += 4;

        if (length == 0) {
            addr += 4; // Skip invalid
            continue;
        }

        switch (type) {
            case TLV_TYPE_AXIS:
                if (length == 12 && axes_found < MAX_AXES) {
                    uint32_t axis_id = *(__IO uint32_t *)addr;
                    addr += 4;
                    if (axis_id >= 1 && axis_id <= MAX_AXES) {
                        settings->axis_min[axis_id - 1] = *(__IO int32_t *)addr;
                        addr += 4;
                        settings->axis_max[axis_id - 1] = *(__IO int32_t *)addr;
                        addr += 4;
                        axes_found++;
                    } else {
                        addr += 8; // Skip invalid ID
                    }
                } else {
                    addr += length;
                }
                break;

            case TLV_TYPE_BRIGHTNESS:
                if (length == 4) {
                    settings->brightness = *(__IO int32_t *)addr;
                    addr += 4;
                } else {
                    addr += length;
                }
                break;

            case TLV_TYPE_FREQUENCY:
                if (length == 4) {
                    settings->frequency = *(__IO int32_t *)addr;
                    addr += 4;
                } else {
                    addr += length;
                }
                break;

            case TLV_TYPE_FFB:
                if (length == 4) {
                    settings->ffb = (bool)*(__IO int32_t *)addr;
                    addr += 4;
                } else {
                    addr += length;
                }
                break;

            default:
                addr += length; // Skip unknown types
                break;
        }
    }

    settings->num_axes = axes_found;
    if (axes_found == 0) settings->valid = 0; // No axes found

    return (settings->valid == 1) ? 0 : 1;
}

uint32_t Flash_Write_Data(uint32_t StartAddress, uint64_t *Data, uint16_t numberofdoublewords)
{
    static FLASH_EraseInitTypeDef EraseInitStruct;
    uint32_t PAGEError;
    int sofar = 0;
    // Unlock the Flash to enable the flash control register access
    HAL_FLASH_Unlock();

    // Erase the user Flash area
    uint32_t StartPage, StartBank;
    GetPageAndBank(StartAddress, &StartPage, &StartBank);
    uint32_t EndAddress = StartAddress + numberofdoublewords * 8;
    uint32_t EndPage, EndBank;
    GetPageAndBank(EndAddress, &EndPage, &EndBank);

    // Fill EraseInit structure
    EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.Banks = StartBank;
    EraseInitStruct.Page = StartPage;
    EraseInitStruct.NbPages = (EndBank == StartBank) ? (EndPage - StartPage + 1) : (128 - StartPage + EndPage + 1);

    if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)
    {
        HAL_FLASH_Lock();
        return HAL_FLASH_GetError();
    }

    // Program the user Flash area double-word by double-word
    while (sofar < numberofdoublewords)
    {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, StartAddress, Data[sofar]) == HAL_OK)
        {
            StartAddress += 8;
            sofar++;
        }
        else
        {
            HAL_FLASH_Lock();
            return HAL_FLASH_GetError();
        }
    }

    HAL_FLASH_Lock();
    return 0;
}
