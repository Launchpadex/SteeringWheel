/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MiskoJOY_BTN_Pin GPIO_PIN_13
#define MiskoJOY_BTN_GPIO_Port GPIOC
#define BTN_ESC_Pin GPIO_PIN_14
#define BTN_ESC_GPIO_Port GPIOC
#define BTN_OK_Pin GPIO_PIN_15
#define BTN_OK_GPIO_Port GPIOC
#define LEFT_HAND_JOY_BTN1_Pin GPIO_PIN_7
#define LEFT_HAND_JOY_BTN1_GPIO_Port GPIOF
#define LEFT_HAND_JOY_BTN2_Pin GPIO_PIN_8
#define LEFT_HAND_JOY_BTN2_GPIO_Port GPIOF
#define BASE_BTN1_Pin GPIO_PIN_9
#define BASE_BTN1_GPIO_Port GPIOF
#define BASE_BTN2_Pin GPIO_PIN_10
#define BASE_BTN2_GPIO_Port GPIOF
#define LEFT_HAND_JOY_Y_Pin GPIO_PIN_1
#define LEFT_HAND_JOY_Y_GPIO_Port GPIOF
#define THROTTLE_Pin GPIO_PIN_0
#define THROTTLE_GPIO_Port GPIOA
#define BRAKE_Pin GPIO_PIN_1
#define BRAKE_GPIO_Port GPIOA
#define CLUTCH_Pin GPIO_PIN_2
#define CLUTCH_GPIO_Port GPIOA
#define LEFT_HAND_JOY_X_Pin GPIO_PIN_4
#define LEFT_HAND_JOY_X_GPIO_Port GPIOC
#define LEFT_HAND_JOY_KNOB_Pin GPIO_PIN_5
#define LEFT_HAND_JOY_KNOB_GPIO_Port GPIOC
#define BASE_BTN3_Pin GPIO_PIN_12
#define BASE_BTN3_GPIO_Port GPIOF
#define BASE_BTN4_Pin GPIO_PIN_13
#define BASE_BTN4_GPIO_Port GPIOF
#define MiskoJOY_X_Pin GPIO_PIN_14
#define MiskoJOY_X_GPIO_Port GPIOB
#define MiskoJOY_Y_Pin GPIO_PIN_15
#define MiskoJOY_Y_GPIO_Port GPIOB
#define ENCODER_1_Pin GPIO_PIN_12
#define ENCODER_1_GPIO_Port GPIOD
#define ENCODER_2_Pin GPIO_PIN_13
#define ENCODER_2_GPIO_Port GPIOD
#define WHEEL_GEAR_L_Pin GPIO_PIN_6
#define WHEEL_GEAR_L_GPIO_Port GPIOC
#define WHEEL_GEAR_R_Pin GPIO_PIN_7
#define WHEEL_GEAR_R_GPIO_Port GPIOC
#define BTN_UP_Pin GPIO_PIN_0
#define BTN_UP_GPIO_Port GPIOG
#define BTN_DOWN_Pin GPIO_PIN_1
#define BTN_DOWN_GPIO_Port GPIOG
#define BTN_LEFT_Pin GPIO_PIN_6
#define BTN_LEFT_GPIO_Port GPIOG
#define BTN_RIGHT_Pin GPIO_PIN_8
#define BTN_RIGHT_GPIO_Port GPIOG
#define LCD_RST_Pin GPIO_PIN_3
#define LCD_RST_GPIO_Port GPIOD
#define SPI1_IRQ_Pin GPIO_PIN_6
#define SPI1_IRQ_GPIO_Port GPIOD
#define LCD_BKLT_Pin GPIO_PIN_6
#define LCD_BKLT_GPIO_Port GPIOB
#define SPI1_CS_Pin GPIO_PIN_1
#define SPI1_CS_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
