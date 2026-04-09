/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @version        : v3.0_Cube
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device.
  * @{
  */

/** @addtogroup USBD_CUSTOM_HID
  * @{
  */

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions USBD_CUSTOM_HID_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Defines USBD_CUSTOM_HID_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Macros USBD_CUSTOM_HID_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Variables USBD_CUSTOM_HID_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
  /* USER CODE BEGIN 0 */
		  0x05, 0x01,        // USAGE_PAGE (Generic Desktop)
		  0x09, 0x04,        // USAGE (Joystick)
		  0xA1, 0x01,        // COLLECTION (Application)
		  0x85, 0x04,        //   REPORT_ID (04)
		  0x05, 0x01,        //   USAGE_PAGE (Generic Desktop)
		  0x09, 0x01,        //   USAGE (Pointer)
		  0xA1, 0x00,        //   COLLECTION (Physical)
		  0x09, 0x30,        //     USAGE (X)      — steering
		  0x09, 0x31,        //     USAGE (Y)      — throttle
		  0x09, 0x32,        //     USAGE (Z)      — brake
		  0x09, 0x33,        //     USAGE (Rx)     — clutch
		  0x09, 0x34,        //     USAGE (Ry)     — x_axis
		  0x09, 0x35,        //     USAGE (Rz)     — y_axis
		  0x09, 0x36,        //     USAGE (Slider) — slider
		  0x15, 0x00,        //     LOGICAL_MINIMUM (0)
		  0x15, 0x00,                      //     LogicalMinimum(0)
		  0x27, 0xFE, 0xFF, 0x00, 0x00,    //     LogicalMaximum(65,534)
		  0x75, 0x10,        //     REPORT_SIZE (16)
		  0x95, 0x07,        //     REPORT_COUNT (7)
		  0x81, 0x02,        //     INPUT (Data,Var,Abs)
		  0xC0,              //   END_COLLECTION (Physical)
		  0x05, 0x09,        //   USAGE_PAGE (Button)
		  0x15, 0x00,        //   LOGICAL_MINIMUM (0)
		  0x25, 0x01,        //   LOGICAL_MAXIMUM (1)
		  0x19, 0x01,        //   USAGE_MINIMUM (Button 1)
		  0x29, 0x10,        //   USAGE_MAXIMUM (Button 16)
		  0x75, 0x01,        //   REPORT_SIZE (1)
		  0x95, 0x10,        //   REPORT_COUNT (16)
		  0x81, 0x02,        //   INPUT (Data,Var,Abs)

		  // =========================================================
		  // FFB / PID section — still inside the Application Collection
		  // =========================================================

		  // --- PID State Report (INPUT, ID 02) ---
		  0x05, 0x0F,  //   USAGE_PAGE (Physical Interface)
		  0x09, 0x92,  //   USAGE (PID State Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x02,  //     REPORT_ID (02)
		  0x09, 0x9F,  //     USAGE (Device Paused)
		  0x09, 0xA0,  //     USAGE (Actuators Enabled)
		  0x09, 0xA4,  //     USAGE (Safety Switch)
		  0x09, 0xA5,  //     USAGE (Actuator Override Switch)
		  0x09, 0xA6,  //     USAGE (Actuator Power)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x25, 0x01,  //     LOGICAL_MAXIMUM (1)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x45, 0x01,  //     PHYSICAL_MAXIMUM (1)
		  0x75, 0x01,  //     REPORT_SIZE (1)
		  0x95, 0x05,  //     REPORT_COUNT (5)
		  0x81, 0x02,  //     INPUT (Data,Var,Abs)
		  0x95, 0x03,  //     REPORT_COUNT (3) — padding
		  0x81, 0x03,  //     INPUT (Cnst,Var,Abs)
		  0x09, 0x94,  //     USAGE (Effect Playing)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x25, 0x01,  //     LOGICAL_MAXIMUM (1)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x45, 0x01,  //     PHYSICAL_MAXIMUM (1)
		  0x75, 0x01,  //     REPORT_SIZE (1)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x81, 0x02,  //     INPUT (Data,Var,Abs)
		  0x09, 0x22,  //     USAGE (Effect Block Index)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x28,  //     LOGICAL_MAXIMUM (40)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x28,  //     PHYSICAL_MAXIMUM (40)
		  0x75, 0x07,  //     REPORT_SIZE (7)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x81, 0x02,  //     INPUT (Data,Var,Abs)
		  0xC0,        //   END_COLLECTION

		  // --- Set Effect (OUTPUT, ID 01) ---
		  0x09, 0x21,  //   USAGE (Set Effect Output Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x01,  //     REPORT_ID (01)
		  0x09, 0x22,  //     USAGE (Effect Block Index)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x28,  //     LOGICAL_MAXIMUM (40)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x28,  //     PHYSICAL_MAXIMUM (40)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x25,  //     USAGE (Effect Type)
		  0xA1, 0x02,  //     COLLECTION (Logical)
		  0x09, 0x26,  //       USAGE (ET Constant Force)
		  0x09, 0x27,  //       USAGE (ET Ramp)
		  0x09, 0x30,  //       USAGE (ET Square)
		  0x09, 0x31,  //       USAGE (ET Sine)
		  0x09, 0x32,  //       USAGE (ET Triangle)
		  0x09, 0x33,  //       USAGE (ET Sawtooth Up)
		  0x09, 0x34,  //       USAGE (ET Sawtooth Down)
		  0x09, 0x40,  //       USAGE (ET Spring)
		  0x09, 0x41,  //       USAGE (ET Damper)
		  0x09, 0x42,  //       USAGE (ET Inertia)
		  0x09, 0x43,  //       USAGE (ET Friction)
		  0x25, 0x0B,  //       LOGICAL_MAXIMUM (11)
		  0x15, 0x01,  //       LOGICAL_MINIMUM (1)
		  0x35, 0x01,  //       PHYSICAL_MINIMUM (1)
		  0x45, 0x0B,  //       PHYSICAL_MAXIMUM (11)
		  0x75, 0x08,  //       REPORT_SIZE (8)
		  0x95, 0x01,  //       REPORT_COUNT (1)
		  0x91, 0x00,  //       OUTPUT (Data)
		  0xC0,        //     END_COLLECTION
		  0x09, 0x50,  //     USAGE (Duration)
		  0x09, 0x54,  //     USAGE (Trigger Repeat Interval)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x27, 0xFF, 0xFF, 0x00, 0x00,  //     LOGICAL_MAXIMUM (65535)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x47, 0xFF, 0xFF, 0x00, 0x00,  //     PHYSICAL_MAXIMUM (65535)
		  0x66, 0x01, 0x10,  //     UNIT (SI Lin:Time)
		  0x55, 0xFD,  //     UNIT_EXPONENT (-3)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x02,  //     REPORT_COUNT (2)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x55, 0x00,  //     UNIT_EXPONENT (0)
		  0x66, 0x00, 0x00,  //     UNIT (None)
		  0x09, 0x52,  //     USAGE (Gain)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x26, 0xFF, 0x7F,  //     LOGICAL_MAXIMUM (32767)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x53,  //     USAGE (Trigger Button)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x08,  //     LOGICAL_MAXIMUM (8)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x08,  //     PHYSICAL_MAXIMUM (8)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x55,  //     USAGE (Axes Enable)
		  0xA1, 0x02,  //     COLLECTION (Logical)
		  0x05, 0x01,  //       USAGE_PAGE (Generic Desktop)
		  0x09, 0x30,  //       USAGE (X)
		  // If you want 2 FFB axes add: 0x09, 0x31, // USAGE (Y)
		  0x15, 0x00,  //       LOGICAL_MINIMUM (0)
		  0x25, 0x01,  //       LOGICAL_MAXIMUM (1)
		  0x75, 0x01,  //       REPORT_SIZE (1)
		  0x95, 0x01,  //       REPORT_COUNT (1)  — 1 FFB axis
		  0x91, 0x02,  //       OUTPUT (Data,Var,Abs)
		  0xC0,        //     END_COLLECTION
		  0x05, 0x0F,  //     USAGE_PAGE (Physical Interface)
		  0x09, 0x56,  //     USAGE (Direction Enable)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x95, 0x06,  //     REPORT_COUNT (6) — padding bits (7 - NB_FF_AXIS)
		  0x91, 0x03,  //     OUTPUT (Cnst,Var,Abs)
		  0x09, 0x57,  //     USAGE (Direction)
		  0xA1, 0x02,  //     COLLECTION (Logical)
		  0x0B, 0x01, 0x00, 0x0A, 0x00,  //       USAGE (Ordinals:Instance 1)
		  0x0B, 0x02, 0x00, 0x0A, 0x00,  //       USAGE (Ordinals:Instance 2)
		  0x66, 0x14, 0x00,  //       UNIT (Eng Rot:Angular Pos)
		  0x55, 0xFE,  //       UNIT_EXPONENT (-2)
		  0x15, 0x00,  //       LOGICAL_MINIMUM (0)
		  0x26, 0xFF, 0x7F,  //       LOGICAL_MAXIMUM (32767)
		  0x35, 0x00,  //       PHYSICAL_MINIMUM (0)
		  0x47, 0x9F, 0x8C, 0x00, 0x00,  //       PHYSICAL_MAXIMUM (35999)
		  0x75, 0x10,  //       REPORT_SIZE (16)
		  0x95, 0x01,  //       REPORT_COUNT (1)
		  0x91, 0x02,  //       OUTPUT (Data,Var,Abs)
		  0x55, 0x00,  //       UNIT_EXPONENT (0)
		  0x66, 0x00, 0x00,  //       UNIT (None)
		  0xC0,        //     END_COLLECTION
		  0x05, 0x0F,  //     USAGE_PAGE (Physical Interface)
		  0x09, 0xA7,  //     USAGE (Start Delay)
		  0x66, 0x01, 0x10,  //     UNIT (SI Lin:Time)
		  0x55, 0xFD,  //     UNIT_EXPONENT (-3)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x27, 0xFF, 0xFF, 0x00, 0x00,  //     LOGICAL_MAXIMUM (65535)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x47, 0xFF, 0xFF, 0x00, 0x00,  //     PHYSICAL_MAXIMUM (65535)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x66, 0x00, 0x00,  //     UNIT (None)
		  0x55, 0x00,  //     UNIT_EXPONENT (0)
		  0xC0,        //   END_COLLECTION

		  // --- Set Envelope (OUTPUT, ID 02) ---
		  0x05, 0x0F,  //   USAGE_PAGE (Physical Interface)
		  0x09, 0x5A,  //   USAGE (Set Envelope Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x02,  //     REPORT_ID (02)
		  0x09, 0x22,  //     USAGE (Effect Block Index)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x28,  //     LOGICAL_MAXIMUM (40)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x28,  //     PHYSICAL_MAXIMUM (40)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x5B,  //     USAGE (Attack Level)
		  0x09, 0x5D,  //     USAGE (Fade Level)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x26, 0xFF, 0x00,  //     LOGICAL_MAXIMUM (255)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x02,  //     REPORT_COUNT (2)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x5C,  //     USAGE (Attack Time)
		  0x09, 0x5E,  //     USAGE (Fade Time)
		  0x66, 0x01, 0x10,  //     UNIT (SI Lin:Time)
		  0x55, 0xFD,  //     UNIT_EXPONENT (-3)
		  0x26, 0xFF, 0x7F,  //     LOGICAL_MAXIMUM (32767)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x02,  //     REPORT_COUNT (2)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x66, 0x00, 0x00,  //     UNIT (None)
		  0x55, 0x00,  //     UNIT_EXPONENT (0)
		  0xC0,        //   END_COLLECTION

		  // --- Set Condition (OUTPUT, ID 03) ---
		  0x09, 0x5F,  //   USAGE (Set Condition Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x03,  //     REPORT_ID (03)
		  0x09, 0x22,  //     USAGE (Effect Block Index)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x28,  //     LOGICAL_MAXIMUM (40)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x28,  //     PHYSICAL_MAXIMUM (40)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x23,  //     USAGE (Parameter Block Offset)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x25, 0x01,  //     LOGICAL_MAXIMUM (1)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x45, 0x01,  //     PHYSICAL_MAXIMUM (1)
		  0x75, 0x04,  //     REPORT_SIZE (4)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x58,  //     USAGE (Type Specific Block Offset)
		  0xA1, 0x02,  //     COLLECTION (Logical)
		  0x0B, 0x01, 0x00, 0x0A, 0x00,  //       USAGE (Instance 1)
		  0x0B, 0x02, 0x00, 0x0A, 0x00,  //       USAGE (Instance 2)
		  0x75, 0x02,  //       REPORT_SIZE (2)
		  0x95, 0x02,  //       REPORT_COUNT (2)
		  0x91, 0x02,  //       OUTPUT (Data,Var,Abs)
		  0xC0,        //     END_COLLECTION
		  0x09, 0x60,  //     USAGE (CP Offset)
		  0x16, 0x00, 0x80,  //     LOGICAL_MINIMUM (-32768)
		  0x26, 0xFF, 0x7F,  //     LOGICAL_MAXIMUM (32767)
		  0x36, 0x00, 0x80,  //     PHYSICAL_MINIMUM (-32768)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x61,  //     USAGE (Positive Coefficient)
		  0x36, 0x00, 0x80,  //     PHYSICAL_MINIMUM (-32768)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x26, 0xFF, 0x7F,  //     LOGICAL_MAXIMUM (32767)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x09, 0x63,  //     USAGE (Positive Saturation)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x65,  //     USAGE (Dead Band)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x26, 0xFF, 0x00,  //     LOGICAL_MAXIMUM (255)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0xC0,        //   END_COLLECTION

		  // --- Set Periodic (OUTPUT, ID 04) ---
		  0x09, 0x6E,  //   USAGE (Set Periodic Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x04,  //     REPORT_ID (04)
		  0x09, 0x22,  //     USAGE (Effect Block Index)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x28,  //     LOGICAL_MAXIMUM (40)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x28,  //     PHYSICAL_MAXIMUM (40)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x70,  //     USAGE (Magnitude)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x26, 0xFF, 0x7F,  //     LOGICAL_MAXIMUM (32767)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x6F,  //     USAGE (Offset)
		  0x16, 0x00, 0x80,  //     LOGICAL_MINIMUM (-32768)
		  0x26, 0xFF, 0x7F,  //     LOGICAL_MAXIMUM (32767)
		  0x36, 0x00, 0x80,  //     PHYSICAL_MINIMUM (-32768)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x71,  //     USAGE (Phase)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x26, 0xFF, 0x00,  //     LOGICAL_MAXIMUM (255)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x46, 0x67, 0x01,  //     PHYSICAL_MAXIMUM (359)
		  0x66, 0x14, 0x00,  //     UNIT (Eng Rot:Angular Pos)
		  0x55, 0x00,  //     UNIT_EXPONENT (0)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x72,  //     USAGE (Period)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x27, 0xFF, 0xFF, 0x00, 0x00,  //     LOGICAL_MAXIMUM (65535)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x47, 0xFF, 0xFF, 0x00, 0x00,  //     PHYSICAL_MAXIMUM (65535)
		  0x66, 0x01, 0x10,  //     UNIT (SI Lin:Time)
		  0x55, 0xFD,  //     UNIT_EXPONENT (-3)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x66, 0x00, 0x00,  //     UNIT (None)
		  0x55, 0x00,  //     UNIT_EXPONENT (0)
		  0xC0,        //   END_COLLECTION

		  // --- Set Constant Force (OUTPUT, ID 05) ---
		  0x09, 0x73,  //   USAGE (Set Constant Force Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x05,  //     REPORT_ID (05)
		  0x09, 0x22,  //     USAGE (Effect Block Index)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x28,  //     LOGICAL_MAXIMUM (40)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x28,  //     PHYSICAL_MAXIMUM (40)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x70,  //     USAGE (Magnitude)
		  0x16, 0x01, 0x80,  //     LOGICAL_MINIMUM (-32767)
		  0x26, 0xFF, 0x7F,  //     LOGICAL_MAXIMUM (32767)
		  0x36, 0x01, 0x80,  //     PHYSICAL_MINIMUM (-32767)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0xC0,        //   END_COLLECTION

		  // --- Set Ramp Force (OUTPUT, ID 06) ---
		  0x09, 0x74,  //   USAGE (Set Ramp Force Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x06,  //     REPORT_ID (06)
		  0x09, 0x22,  //     USAGE (Effect Block Index)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x28,  //     LOGICAL_MAXIMUM (40)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x28,  //     PHYSICAL_MAXIMUM (40)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x75,  //     USAGE (Ramp Start)
		  0x09, 0x76,  //     USAGE (Ramp End)
		  0x15, 0x81,  //     LOGICAL_MINIMUM (-127)
		  0x25, 0x7F,  //     LOGICAL_MAXIMUM (127)
		  0x36, 0x01, 0x80,  //     PHYSICAL_MINIMUM (-32767)
		  0x46, 0xFF, 0x7F,  //     PHYSICAL_MAXIMUM (32767)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x02,  //     REPORT_COUNT (2)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0xC0,        //   END_COLLECTION

		  // --- Effect Operation (OUTPUT, ID 0A) ---
		  0x05, 0x0F,  //   USAGE_PAGE (Physical Interface)
		  0x09, 0x77,  //   USAGE (Effect Operation Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x0A,  //     REPORT_ID (10)
		  0x09, 0x22,  //     USAGE (Effect Block Index)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x28,  //     LOGICAL_MAXIMUM (40)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x28,  //     PHYSICAL_MAXIMUM (40)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0x09, 0x78,  //     USAGE (Operation)
		  0xA1, 0x02,  //     COLLECTION (Logical)
		  0x09, 0x79,  //       USAGE (Op Effect Start)
		  0x09, 0x7A,  //       USAGE (Op Effect Start Solo)
		  0x09, 0x7B,  //       USAGE (Op Effect Stop)
		  0x15, 0x01,  //       LOGICAL_MINIMUM (1)
		  0x25, 0x03,  //       LOGICAL_MAXIMUM (3)
		  0x75, 0x08,  //       REPORT_SIZE (8)
		  0x95, 0x01,  //       REPORT_COUNT (1)
		  0x91, 0x00,  //       OUTPUT (Data)
		  0xC0,        //     END_COLLECTION
		  0x09, 0x7C,  //     USAGE (Loop Count)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x26, 0xFF, 0x00,  //     LOGICAL_MAXIMUM (255)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x46, 0xFF, 0x00,  //     PHYSICAL_MAXIMUM (255)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0xC0,        //   END_COLLECTION

		  // --- Block Free (OUTPUT, ID 0B) ---
		  0x09, 0x90,  //   USAGE (PID Block Free Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x0B,  //     REPORT_ID (11)
		  0x09, 0x22,  //     USAGE (Effect Block Index)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x28,  //     LOGICAL_MAXIMUM (40)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x28,  //     PHYSICAL_MAXIMUM (40)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0xC0,        //   END_COLLECTION

		  // --- Device Control (OUTPUT, ID 0C) ---
		  0x09, 0x96,  //   USAGE (PID Device Control)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x0C,  //     REPORT_ID (12)
		  0x09, 0x97,  //     USAGE (DC Enable Actuators)
		  0x09, 0x98,  //     USAGE (DC Disable Actuators)
		  0x09, 0x99,  //     USAGE (DC Stop All Effects)
		  0x09, 0x9A,  //     USAGE (DC Device Reset)
		  0x09, 0x9B,  //     USAGE (DC Device Pause)
		  0x09, 0x9C,  //     USAGE (DC Device Continue)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x06,  //     LOGICAL_MAXIMUM (6)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x00,  //     OUTPUT (Data)
		  0xC0,        //   END_COLLECTION

		  // --- Device Gain (OUTPUT, ID 0D) ---
		  0x09, 0x7D,  //   USAGE (Device Gain Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x0D,  //     REPORT_ID (13)
		  0x09, 0x7E,  //     USAGE (Device Gain)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x26, 0xFF, 0x00,  //     LOGICAL_MAXIMUM (255)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x46, 0x10, 0x27,  //     PHYSICAL_MAXIMUM (10000)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x91, 0x02,  //     OUTPUT (Data,Var,Abs)
		  0xC0,        //   END_COLLECTION

		  // --- Create New Effect (FEATURE, ID 05) ---
		  0x09, 0xAB,  //   USAGE (Create New Effect Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x05,  //     REPORT_ID (05)
		  0x09, 0x25,  //     USAGE (Effect Type)
		  0xA1, 0x02,  //     COLLECTION (Logical)
		  0x09, 0x26,  //       USAGE (ET Constant Force)
		  0x09, 0x27,  //       USAGE (ET Ramp)
		  0x09, 0x30,  //       USAGE (ET Square)
		  0x09, 0x31,  //       USAGE (ET Sine)
		  0x09, 0x32,  //       USAGE (ET Triangle)
		  0x09, 0x33,  //       USAGE (ET Sawtooth Up)
		  0x09, 0x34,  //       USAGE (ET Sawtooth Down)
		  0x09, 0x40,  //       USAGE (ET Spring)
		  0x09, 0x41,  //       USAGE (ET Damper)
		  0x09, 0x42,  //       USAGE (ET Inertia)
		  0x09, 0x43,  //       USAGE (ET Friction)
		  0x15, 0x01,  //       LOGICAL_MINIMUM (1)
		  0x25, 0x0B,  //       LOGICAL_MAXIMUM (11)
		  0x35, 0x01,  //       PHYSICAL_MINIMUM (1)
		  0x45, 0x0B,  //       PHYSICAL_MAXIMUM (11)
		  0x75, 0x08,  //       REPORT_SIZE (8)
		  0x95, 0x01,  //       REPORT_COUNT (1)
		  0xB1, 0x00,  //       FEATURE (Data)
		  0xC0,        //     END_COLLECTION
		  0x05, 0x01,  //     USAGE_PAGE (Generic Desktop)
		  0x09, 0x3B,  //     USAGE (Byte Count)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x26, 0xFF, 0x01,  //     LOGICAL_MAXIMUM (511)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x46, 0xFF, 0x01,  //     PHYSICAL_MAXIMUM (511)
		  0x75, 0x0A,  //     REPORT_SIZE (10)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0xB1, 0x02,  //     FEATURE (Data,Var,Abs)
		  0x75, 0x06,  //     REPORT_SIZE (6) — padding
		  0xB1, 0x01,  //     FEATURE (Cnst,Ary,Abs)
		  0xC0,        //   END_COLLECTION

		  // --- PID Block Load (FEATURE, ID 06) ---
		  0x05, 0x0F,  //   USAGE_PAGE (Physical Interface)
		  0x09, 0x89,  //   USAGE (PID Block Load Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x06,  //     REPORT_ID (06)
		  0x09, 0x22,  //     USAGE (Effect Block Index)
		  0x15, 0x01,  //     LOGICAL_MINIMUM (1)
		  0x25, 0x28,  //     LOGICAL_MAXIMUM (40)
		  0x35, 0x01,  //     PHYSICAL_MINIMUM (1)
		  0x45, 0x28,  //     PHYSICAL_MAXIMUM (40)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0xB1, 0x02,  //     FEATURE (Data,Var,Abs)
		  0x09, 0x8B,  //     USAGE (Block Load Status)
		  0xA1, 0x02,  //     COLLECTION (Logical)
		  0x09, 0x8C,  //       USAGE (Block Load Success)
		  0x09, 0x8D,  //       USAGE (Block Load Full)
		  0x09, 0x8E,  //       USAGE (Block Load Error)
		  0x15, 0x01,  //       LOGICAL_MINIMUM (1)
		  0x25, 0x03,  //       LOGICAL_MAXIMUM (3)
		  0x35, 0x01,  //       PHYSICAL_MINIMUM (1)
		  0x45, 0x03,  //       PHYSICAL_MAXIMUM (3)
		  0x75, 0x08,  //       REPORT_SIZE (8)
		  0x95, 0x01,  //       REPORT_COUNT (1)
		  0xB1, 0x00,  //       FEATURE (Data)
		  0xC0,        //     END_COLLECTION
		  0x09, 0xAC,  //     USAGE (RAM Pool Available)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x27, 0xFF, 0xFF, 0x00, 0x00,  //     LOGICAL_MAXIMUM (65535)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x47, 0xFF, 0xFF, 0x00, 0x00,  //     PHYSICAL_MAXIMUM (65535)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0xB1, 0x00,  //     FEATURE (Data)
		  0xC0,        //   END_COLLECTION

		  // --- PID Pool (FEATURE, ID 07) ---
		  0x09, 0x7F,  //   USAGE (PID Pool Report)
		  0xA1, 0x02,  //   COLLECTION (Logical)
		  0x85, 0x07,  //     REPORT_ID (07)
		  0x09, 0x80,  //     USAGE (RAM Pool Size)
		  0x75, 0x10,  //     REPORT_SIZE (16)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x27, 0xFF, 0xFF, 0x00, 0x00,  //     LOGICAL_MAXIMUM (65535)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x47, 0xFF, 0xFF, 0x00, 0x00,  //     PHYSICAL_MAXIMUM (65535)
		  0xB1, 0x02,  //     FEATURE (Data,Var,Abs)
		  0x09, 0x83,  //     USAGE (Simultaneous Effects Max)
		  0x26, 0xFF, 0x00,  //     LOGICAL_MAXIMUM (255)
		  0x46, 0xFF, 0x00,  //     PHYSICAL_MAXIMUM (255)
		  0x75, 0x08,  //     REPORT_SIZE (8)
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0xB1, 0x02,  //     FEATURE (Data,Var,Abs)
		  0x09, 0xA9,  //     USAGE (Device Managed Pool)
		  0x09, 0xAA,  //     USAGE (Shared Parameter Blocks)
		  0x75, 0x01,  //     REPORT_SIZE (1)
		  0x95, 0x02,  //     REPORT_COUNT (2)
		  0x15, 0x00,  //     LOGICAL_MINIMUM (0)
		  0x25, 0x01,  //     LOGICAL_MAXIMUM (1)
		  0x35, 0x00,  //     PHYSICAL_MINIMUM (0)
		  0x45, 0x01,  //     PHYSICAL_MAXIMUM (1)
		  0xB1, 0x02,  //     FEATURE (Data,Var,Abs)
		  0x75, 0x06,  //     REPORT_SIZE (6) — padding
		  0x95, 0x01,  //     REPORT_COUNT (1)
		  0xB1, 0x03,  //     FEATURE (Cnst,Var,Abs)
		  0xC0,        //   END_COLLECTION
  /* USER CODE END 0 */
  0xC0    /*     END_COLLECTION	             */
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_Init_FS(void);
static int8_t CUSTOM_HID_DeInit_FS(void);
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS =
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{
  FFB_Init();
  return (USBD_OK);
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */
  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Manage the CUSTOM HID class events
  * @param  event_idx: Event index
  * @param  state: Event state
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state)
{
  UNUSED(event_idx);
  UNUSED(state);

  /* Access full report buffer through class handle */
  USBD_CUSTOM_HID_HandleTypeDef *hhid =
      (USBD_CUSTOM_HID_HandleTypeDef *)hUsbDeviceFS.pClassData;

  if (hhid != NULL)
  {
    FFB_ProcessOutputReport(hhid->Report_buf, USBD_CUSTOMHID_OUTREPORT_BUF_SIZE);
  }

  USBD_CUSTOM_HID_ReceivePacket(&hUsbDeviceFS);
  return (USBD_OK);
}


/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
}
*/
/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

