/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : misko_touch.h
  * @brief          : Header for misko_touch.c file.
  *                   This file contains the touch controller defines.
  ******************************************************************************
  * @notice
  * Copyright (c) 2024 by Robolab, ULFE (Peter Kmecl)
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MISKO_TOUCH_H
#define __MISKO_TOUCH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx.h"
#include <stddef.h>

/* Defines -------------------------------------------------------------------*/
#define TOUCH_X_CHANNEL_SELECT 0b001
#define TOUCH_Y_CHANNEL_SELECT 0b101
#define TOUCH_Z1_CHANNEL_SELECT 0b011
#define TOUCH_Z2_CHANNEL_SELECT 0b100
#define TOUCH_CHANNEL_DIFFERENTIAL_MEAS 0b0
#define TOUCH_CHANNEL_SINGLEENDED_MEAS 0b1
#define TOUCH_8BIT_MODE 0b1
#define TOUCH_12BIT_MODE 0b0
#define TOUCH_FULL_PD_IRQ 0b00
#define TOUCH_REFERENCE_PD_NO_IRQ 0b01
#define TOUCH_ADC_PD_IRQ 0b10
#define TOUCH_NO_PD_NO_IRQ 0b11

#define TOUCH_LCD_RESOLUTION_X 320
#define TOUCH_LCD_RESOLUTION_Y 240
#define TOUCH_X_LIM_HI 3700//4054 //3904
#define TOUCH_X_LIM_LO 201
#define TOUCH_Y_LIM_HI 3774
#define TOUCH_Y_LIM_LO 220 //10



void touchIOInit();
void touchSPIInit();
void touchInit();

uint8_t SPI1_TransmitReceive(uint8_t dataToTransmit);

void touchCSSelect();
void touchCSDeselect();

uint8_t touchCheckPressed();

uint16_t touchReadChannel(uint8_t channel, uint8_t conversionModeSD, uint8_t conversionDataSize, uint8_t PDmode);
uint16_t touchReadRawXPos();
uint16_t touchReadRawYPos();

void touchReadRawXYPos(uint16_t * xPos, uint16_t * yPos);
void touchReadRawXYPosAvg(uint16_t * xPosAvg, uint16_t * yPosAvg, uint8_t numAvg);

uint16_t touchScaleValue(uint16_t value, uint16_t max, uint16_t min, uint16_t range);
void touchReadXY(uint16_t * xPos, uint16_t * yPos);




#ifdef __cplusplus
}
#endif

#endif /* __MISKO_TOUCH_H */
