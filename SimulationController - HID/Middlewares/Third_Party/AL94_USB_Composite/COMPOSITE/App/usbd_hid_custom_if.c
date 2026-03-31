/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @version        : v1.0_Cube
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usbd_hid_custom_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
uint8_t buffer[0x40];
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
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
    /* USER CODE BEGIN 0 */
    0x05, 0x01,                      // UsagePage(Generic Desktop[0x0001])
    0x09, 0x04,                      // UsageId(Joystick[0x0004])
    0xA1, 0x01,                      // Collection(Application)

    // ===== INPUT REPORT ID 1: Axes + Buttons =====
    0x85, 0x01,                      //     ReportId(1)
    0x09, 0x30,                      //     UsageId(X[0x0030])
    0x09, 0x31,                      //     UsageId(Y[0x0031])
    0x09, 0x32,                      //     UsageId(Z[0x0032])
    0x09, 0x33,                      //     UsageId(Rx[0x0033])
    0x09, 0x34,                      //     UsageId(Ry[0x0034])
    0x09, 0x35,                      //     UsageId(Rz[0x0035])
    0x09, 0x36,                      //     UsageId(Slider[0x0036])
    0x15, 0x00,                      //     LogicalMinimum(0)
    0x27, 0xFE, 0xFF, 0x00, 0x00,    //     LogicalMaximum(65,534)
    0x95, 0x07,                      //     ReportCount(7)
    0x75, 0x10,                      //     ReportSize(16)
    0x81, 0x02,                      //     Input(Data, Variable, Absolute)

    0x05, 0x09,                      //     UsagePage(Button[0x0009])
    0x19, 0x01,                      //     UsageIdMin(Button 1[0x0001])
    0x29, 0x10,                      //     UsageIdMax(Button 16[0x0010])
    0x25, 0x01,                      //     LogicalMaximum(1)
    0x95, 0x10,                      //     ReportCount(16)
    0x75, 0x01,                      //     ReportSize(1)
    0x81, 0x02,                      //     Input(Data, Variable, Absolute)

    // ===== PID REPORTS FOR FORCE FEEDBACK =====
    0x05, 0x0F,                      //     UsagePage(Physical Input Device[0x000F])

    // ----- Report ID 2: PID State Input (Device → Host) -----
    0x09, 0x92,                      //     Usage(PID State Report)
    0xA1, 0x02,                      //     Collection(Logical)
    0x85, 0x02,                      //         ReportId(2)
    0x09, 0x9F,                      //         Usage(Device Paused)
    0x09, 0xA0,                      //         Usage(Actuators Enabled)
    0x09, 0xA4,                      //         Usage(Safety Switch)
    0x09, 0xA5,                      //         Usage(Actuator Override Switch)
    0x09, 0xA6,                      //         Usage(Actuator Power)
    0x15, 0x00,                      //         LogicalMinimum(0)
    0x25, 0x01,                      //         LogicalMaximum(1)
    0x35, 0x00,                      //         PhysicalMinimum(0)
    0x45, 0x01,                      //         PhysicalMaximum(1)
    0x75, 0x01,                      //         ReportSize(1)
    0x95, 0x05,                      //         ReportCount(5)
    0x81, 0x02,                      //         Input(Data, Variable, Absolute)
    0x95, 0x03,                      //         ReportCount(3)
    0x81, 0x03,                      //         Input(Constant, Variable, Absolute) - Padding
    0x09, 0x94,                      //         Usage(Effect Playing)
    0x15, 0x00,                      //         LogicalMinimum(0)
    0x25, 0x01,                      //         LogicalMaximum(1)
    0x35, 0x00,                      //         PhysicalMinimum(0)
    0x45, 0x01,                      //         PhysicalMaximum(1)
    0x75, 0x01,                      //         ReportSize(1)
    0x95, 0x01,                      //         ReportCount(1)
    0x81, 0x02,                      //         Input(Data, Variable, Absolute)
    0x09, 0x22,                      //         Usage(Effect Block Index)
    0x15, 0x01,                      //         LogicalMinimum(1)
    0x25, 0x28,                      //         LogicalMaximum(40)
    0x35, 0x01,                      //         PhysicalMinimum(1)
    0x45, 0x28,                      //         PhysicalMaximum(40)
    0x75, 0x07,                      //         ReportSize(7)
    0x95, 0x01,                      //         ReportCount(1)
    0x81, 0x02,                      //         Input(Data, Variable, Absolute)
    0xC0,                            //     EndCollection

    // ----- Report ID 3: Set Effect Report (Host → Device) -----
    0x09, 0x21,                      //     Usage(Set Effect Report)
    0xA1, 0x02,                      //     Collection(Logical)
    0x85, 0x03,                      //         ReportId(3)
    0x09, 0x22,                      //         Usage(Effect Block Index)
    0x15, 0x01,                      //         LogicalMinimum(1)
    0x25, 0x28,                      //         LogicalMaximum(40)
    0x35, 0x01,                      //         PhysicalMinimum(1)
    0x45, 0x28,                      //         PhysicalMaximum(40)
    0x75, 0x08,                      //         ReportSize(8)
    0x95, 0x01,                      //         ReportCount(1)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0x09, 0x25,                      //         Usage(Effect Type)
    0xA1, 0x02,                      //         Collection(Logical)
    0x09, 0x26,                      //             Usage(ET Constant Force)
    0x09, 0x27,                      //             Usage(ET Ramp)
    0x09, 0x30,                      //             Usage(ET Square)
    0x09, 0x31,                      //             Usage(ET Sine)
    0x09, 0x32,                      //             Usage(ET Triangle)
    0x09, 0x33,                      //             Usage(ET Sawtooth Up)
    0x09, 0x34,                      //             Usage(ET Sawtooth Down)
    0x09, 0x40,                      //             Usage(ET Spring)
    0x09, 0x41,                      //             Usage(ET Damper)
    0x09, 0x42,                      //             Usage(ET Inertia)
    0x09, 0x43,                      //             Usage(ET Friction)
    0x25, 0x0B,                      //             LogicalMaximum(11)
    0x15, 0x01,                      //             LogicalMinimum(1)
    0x35, 0x01,                      //             PhysicalMinimum(1)
    0x45, 0x0B,                      //             PhysicalMaximum(11)
    0x75, 0x08,                      //             ReportSize(8)
    0x95, 0x01,                      //             ReportCount(1)
    0x91, 0x00,                      //             Output(Data, Array, Absolute)
    0xC0,                            //         EndCollection
    0x09, 0x50,                      //         Usage(Duration)
    0x09, 0x54,                      //         Usage(Trigger Repeat Interval)
    0x09, 0x51,                      //         Usage(Sample Period)
    0x15, 0x00,                      //         LogicalMinimum(0)
    0x26, 0xFF, 0x7F,                //         LogicalMaximum(32,767)
    0x35, 0x00,                      //         PhysicalMinimum(0)
    0x46, 0xFF, 0x7F,                //         PhysicalMaximum(32,767)
    0x66, 0x03, 0x10,                //         Unit(Time: English Linear, Seconds)
    0x55, 0xFD,                      //         UnitExponent(-3)
    0x75, 0x10,                      //         ReportSize(16)
    0x95, 0x03,                      //         ReportCount(3)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0x55, 0x00,                      //         UnitExponent(0)
    0x66, 0x00, 0x00,                //         Unit(None)
    0x09, 0x52,                      //         Usage(Gain)
    0x15, 0x00,                      //         LogicalMinimum(0)
    0x26, 0xFF, 0x00,                //         LogicalMaximum(255)
    0x35, 0x00,                      //         PhysicalMinimum(0)
    0x46, 0x10, 0x27,                //         PhysicalMaximum(10,000)
    0x75, 0x08,                      //         ReportSize(8)
    0x95, 0x01,                      //         ReportCount(1)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0x09, 0x53,                      //         Usage(Trigger Button)
    0x15, 0x01,                      //         LogicalMinimum(1)
    0x25, 0x08,                      //         LogicalMaximum(8)
    0x35, 0x01,                      //         PhysicalMinimum(1)
    0x45, 0x08,                      //         PhysicalMaximum(8)
    0x75, 0x08,                      //         ReportSize(8)
    0x95, 0x01,                      //         ReportCount(1)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0x09, 0x55,                      //         Usage(Axes Enable)
    0xA1, 0x02,                      //         Collection(Logical)
    0x05, 0x01,                      //             UsagePage(Generic Desktop)
    0x09, 0x30,                      //             Usage(X)
    0x09, 0x31,                      //             Usage(Y)
    0x15, 0x00,                      //             LogicalMinimum(0)
    0x25, 0x01,                      //             LogicalMaximum(1)
    0x75, 0x01,                      //             ReportSize(1)
    0x95, 0x02,                      //             ReportCount(2)
    0x91, 0x02,                      //             Output(Data, Variable, Absolute)
    0xC0,                            //         EndCollection
    0x05, 0x0F,                      //         UsagePage(Physical Input Device)
    0x09, 0x56,                      //         Usage(Direction Enable)
    0x95, 0x01,                      //         ReportCount(1)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0x95, 0x05,                      //         ReportCount(5)
    0x91, 0x03,                      //         Output(Constant, Variable, Absolute) - Padding
    0x09, 0x57,                      //         Usage(Direction)
    0xA1, 0x02,                      //         Collection(Logical)
    0x0B, 0x01, 0x00, 0x0A, 0x00,    //             Usage(Ordinals: Instance 1)
    0x0B, 0x02, 0x00, 0x0A, 0x00,    //             Usage(Ordinals: Instance 2)
    0x66, 0x14, 0x00,                //             Unit(Rotation: English, Degrees)
    0x55, 0x00,                      //             UnitExponent(0)
    0x15, 0x00,                      //             LogicalMinimum(0)
    0x26, 0xB4, 0x00,                //             LogicalMaximum(180)
    0x35, 0x00,                      //             PhysicalMinimum(0)
    0x47, 0xB4, 0x00, 0x00, 0x00,    //             PhysicalMaximum(180)
    0x66, 0x00, 0x00,                //             Unit(None)
    0x75, 0x08,                      //             ReportSize(8)
    0x95, 0x02,                      //             ReportCount(2)
    0x91, 0x02,                      //             Output(Data, Variable, Absolute)
    0xC0,                            //         EndCollection
    0xC0,                            //     EndCollection

    // ----- Report ID 4: Set Constant Force -----
    0x09, 0x5A,                      //     Usage(Set Constant Force Report)
    0xA1, 0x02,                      //     Collection(Logical)
    0x85, 0x04,                      //         ReportId(4)
    0x09, 0x22,                      //         Usage(Effect Block Index)
    0x15, 0x01,                      //         LogicalMinimum(1)
    0x25, 0x28,                      //         LogicalMaximum(40)
    0x35, 0x01,                      //         PhysicalMinimum(1)
    0x45, 0x28,                      //         PhysicalMaximum(40)
    0x75, 0x08,                      //         ReportSize(8)
    0x95, 0x01,                      //         ReportCount(1)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0x09, 0x70,                      //         Usage(Magnitude)
    0x16, 0xF0, 0xD8,                //         LogicalMinimum(-10,000)
    0x26, 0x10, 0x27,                //         LogicalMaximum(10,000)
    0x36, 0xF0, 0xD8,                //         PhysicalMinimum(-10,000)
    0x46, 0x10, 0x27,                //         PhysicalMaximum(10,000)
    0x75, 0x10,                      //         ReportSize(16)
    0x95, 0x01,                      //         ReportCount(1)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0xC0,                            //     EndCollection

    // ----- Report ID 5: Effect Operation -----
    0x09, 0x5F,                      //     Usage(Effect Operation Report)
    0xA1, 0x02,                      //     Collection(Logical)
    0x85, 0x05,                      //         ReportId(5)
    0x09, 0x22,                      //         Usage(Effect Block Index)
    0x15, 0x01,                      //         LogicalMinimum(1)
    0x25, 0x28,                      //         LogicalMaximum(40)
    0x35, 0x01,                      //         PhysicalMinimum(1)
    0x45, 0x28,                      //         PhysicalMaximum(40)
    0x75, 0x08,                      //         ReportSize(8)
    0x95, 0x01,                      //         ReportCount(1)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0x09, 0x78,                      //         Usage(Effect Operation)
    0xA1, 0x02,                      //         Collection(Logical)
    0x09, 0x79,                      //             Usage(Op Effect Start)
    0x09, 0x7A,                      //             Usage(Op Effect Start Solo)
    0x09, 0x7B,                      //             Usage(Op Effect Stop)
    0x15, 0x01,                      //             LogicalMinimum(1)
    0x25, 0x03,                      //             LogicalMaximum(3)
    0x75, 0x08,                      //             ReportSize(8)
    0x95, 0x01,                      //             ReportCount(1)
    0x91, 0x00,                      //             Output(Data, Array, Absolute)
    0xC0,                            //         EndCollection
    0x09, 0x7C,                      //         Usage(Loop Count)
    0x15, 0x00,                      //         LogicalMinimum(0)
    0x26, 0xFF, 0x00,                //         LogicalMaximum(255)
    0x35, 0x00,                      //         PhysicalMinimum(0)
    0x46, 0xFF, 0x00,                //         PhysicalMaximum(255)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0xC0,                            //     EndCollection

    // ----- Report ID 6: Block Free -----
    0x09, 0x90,                      //     Usage(PID Block Free Report)
    0xA1, 0x02,                      //     Collection(Logical)
    0x85, 0x06,                      //         ReportId(6)
    0x09, 0x22,                      //         Usage(Effect Block Index)
    0x25, 0x28,                      //         LogicalMaximum(40)
    0x15, 0x01,                      //         LogicalMinimum(1)
    0x35, 0x01,                      //         PhysicalMinimum(1)
    0x45, 0x28,                      //         PhysicalMaximum(40)
    0x75, 0x08,                      //         ReportSize(8)
    0x95, 0x01,                      //         ReportCount(1)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0xC0,                            //     EndCollection

    // ----- Report ID 7: Device Control -----
    0x09, 0x96,                      //     Usage(DC Enable Actuators)
    0xA1, 0x02,                      //     Collection(Logical)
    0x85, 0x07,                      //         ReportId(7)
    0x09, 0x97,                      //         Usage(DC Disable Actuators)
    0x09, 0x98,                      //         Usage(DC Stop All Effects)
    0x09, 0x99,                      //         Usage(DC Device Reset)
    0x09, 0x9A,                      //         Usage(DC Device Pause)
    0x09, 0x9B,                      //         Usage(DC Device Continue)
    0x15, 0x01,                      //         LogicalMinimum(1)
    0x25, 0x06,                      //         LogicalMaximum(6)
    0x75, 0x08,                      //         ReportSize(8)
    0x95, 0x01,                      //         ReportCount(1)
    0x91, 0x00,                      //         Output(Data, Array, Absolute)
    0xC0,                            //     EndCollection

    // ----- Report ID 8: Device Gain -----
    0x09, 0x7D,                      //     Usage(Device Gain Report)
    0xA1, 0x02,                      //     Collection(Logical)
    0x85, 0x08,                      //         ReportId(8)
    0x09, 0x7D,                      //         Usage(Device Gain)
    0x15, 0x00,                      //         LogicalMinimum(0)
    0x26, 0xFF, 0x00,                //         LogicalMaximum(255)
    0x35, 0x00,                      //         PhysicalMinimum(0)
    0x46, 0x10, 0x27,                //         PhysicalMaximum(10,000)
    0x75, 0x08,                      //         ReportSize(8)
    0x95, 0x01,                      //         ReportCount(1)
    0x91, 0x02,                      //         Output(Data, Variable, Absolute)
    0xC0,                            //     EndCollection

    // ----- Report ID 9: PID Pool (Feature Report) -----
    0x09, 0x7F,                      //     Usage(PID Pool Report)
    0xA1, 0x02,                      //     Collection(Logical)
    0x85, 0x09,                      //         ReportId(9)
    0x09, 0x80,                      //         Usage(RAM Pool Size)
    0x75, 0x10,                      //         ReportSize(16)
    0x95, 0x01,                      //         ReportCount(1)
    0x15, 0x00,                      //         LogicalMinimum(0)
    0x35, 0x00,                      //         PhysicalMinimum(0)
    0x27, 0xFF, 0xFF, 0x00, 0x00,    //         LogicalMaximum(65,535)
    0x47, 0xFF, 0xFF, 0x00, 0x00,    //         PhysicalMaximum(65,535)
    0xB1, 0x02,                      //         Feature(Data, Variable, Absolute)
    0x09, 0x83,                      //         Usage(Simultaneous Effects Max)
    0x26, 0xFF, 0x00,                //         LogicalMaximum(255)
    0x46, 0xFF, 0x00,                //         PhysicalMaximum(255)
    0x75, 0x08,                      //         ReportSize(8)
    0x95, 0x01,                      //         ReportCount(1)
    0xB1, 0x02,                      //         Feature(Data, Variable, Absolute)
    0x09, 0xA9,                      //         Usage(Device Managed Pool)
    0x09, 0xAA,                      //         Usage(Shared Parameter Blocks)
    0x75, 0x01,                      //         ReportSize(1)
    0x95, 0x02,                      //         ReportCount(2)
    0x15, 0x00,                      //         LogicalMinimum(0)
    0x25, 0x01,                      //         LogicalMaximum(1)
    0x35, 0x00,                      //         PhysicalMinimum(0)
    0x45, 0x01,                      //         PhysicalMaximum(1)
    0xB1, 0x02,                      //         Feature(Data, Variable, Absolute)
    0x75, 0x06,                      //         ReportSize(6)
    0x95, 0x01,                      //         ReportCount(1)
    0xB1, 0x03,                      //         Feature(Constant, Variable, Absolute) - Padding
    0xC0,                            //     EndCollection

    /* USER CODE END 0 */
    0xC0 /*     END_COLLECTION */
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
extern USBD_HandleTypeDef hUsbDevice;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_Init(void);
static int8_t CUSTOM_HID_DeInit(void);
static int8_t CUSTOM_HID_OutEvent(uint8_t event_idx, uint8_t state);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops = {CUSTOM_HID_ReportDesc,
                                                  CUSTOM_HID_Init,
                                                  CUSTOM_HID_DeInit,
                                                  CUSTOM_HID_OutEvent};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init(void)
{
  /* USER CODE BEGIN 4 */
  // Prepare to receive FFB commands
  USBD_CUSTOM_HID_ReceivePacket(&hUsbDevice);
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit(void)
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
static int8_t CUSTOM_HID_OutEvent(uint8_t event_idx, uint8_t state)
{
  /* USER CODE BEGIN 6 */

  // Get the HID handle to access received data
  USBD_CUSTOM_HID_HandleTypeDef *hhid =
      (USBD_CUSTOM_HID_HandleTypeDef *)hUsbDevice.pClassData_HID_Custom;

  if (hhid != NULL)
  {
    uint8_t *data = hhid->Report_buf;
    uint8_t report_id = data[0];

    // Debug: Print received reports
    static uint32_t debug_count = 0;
    if (++debug_count % 100 == 0) {
      printf("FFB Report ID %d received\n", report_id);
    }

    switch(report_id)
    {
      case 3:  // Set Effect Report
        // Effect Block Index = data[1]
        // Effect Type = data[2]
        // Duration = data[3] | (data[4] << 8)
        // ... (usually just acknowledge, don't need to process)
        break;

      case 4:  // Set Constant Force - THE IMPORTANT ONE!
      {
        // Effect Block Index = data[1] (which effect slot)
        // Magnitude = data[2] | (data[3] << 8)
        int16_t force = (int16_t)(data[2] | (data[3] << 8));

        // THIS IS YOUR MOTOR CONTROL!
        // force range: -10,000 to +10,000
        printf("Constant Force: %d\n", force);

        // TODO: Control your motor here
        // SetMotorForce(force);
        break;
      }

      case 5:  // Effect Operation (Start/Stop)
        // Effect Block Index = data[1]
        // Operation = data[2] (1=Start, 2=Start Solo, 3=Stop)
        // Loop Count = data[3]
        if (data[2] == 1 || data[2] == 2) {
          // Start effect
          printf("Start Effect %d\n", data[1]);
        } else if (data[2] == 3) {
          // Stop effect
          printf("Stop Effect %d\n", data[1]);
        }
        break;

      case 6:  // Block Free
        // Effect Block Index = data[1]
        // Free/release this effect slot
        printf("Free Effect %d\n", data[1]);
        break;

      case 7:  // Device Control
        // Operation = data[1]
        // 1=Enable Actuators, 2=Disable, 3=Stop All, 4=Reset, 5=Pause, 6=Continue
        switch(data[1]) {
          case 1: printf("Enable Actuators\n"); break;
          case 2: printf("Disable Actuators\n"); break;
          case 3: printf("Stop All Effects\n"); break;
          case 4: printf("Device Reset\n"); break;
          case 5: printf("Device Pause\n"); break;
          case 6: printf("Device Continue\n"); break;
        }
        break;

      case 8:  // Device Gain (Global force multiplier)
      {
        // Gain = data[1] (0-255, maps to 0-10000)
        uint8_t gain = data[1];
        uint16_t gain_percent = (gain * 100) / 255;
        printf("Device Gain: %d%%\n", gain_percent);

        // TODO: Scale all forces by this gain
        // global_gain = gain;
        break;
      }

      default:
        // Unknown report ID
        printf("Unknown Report ID: %d\n", report_id);
        break;
    }

    // *** CRITICAL: Re-arm the endpoint to receive next packet! ***
    USBD_CUSTOM_HID_ReceivePacket(&hUsbDevice);
  }

  return (USBD_OK);
  /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_SendReport(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDevice, report, len);
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
