/**
  ******************************************************************************
  * @file    usbd_customHID2.c
  * @author  MCD Application Team
  * @brief   This file provides the CUSTOM_HID2 core functions.
  *
  * @verbatim
  *
  *          ===================================================================
  *                                CUSTOM_HID2 Class  Description
  *          ===================================================================
  *           This module manages the CUSTOM_HID2 class V1.11 following the "Device Class Definition
  *           for Human Interface Devices (CUSTOM_HID2) Version 1.11 Jun 27, 2001".
  *           This driver implements the following aspects of the specification:
  *             - The Boot Interface Subclass
  *             - Usage Page : Generic Desktop
  *             - Usage : Vendor
  *             - Collection : Application
  *
  * @note     In HS mode and when the DMA is used, all variables and data structures
  *           dealing with the DMA during the transaction process should be 32-bit aligned.
  *
  *
  *  @endverbatim
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                      www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* BSPDependencies
- "stm32xxxxx_{eval}{discovery}{nucleo_144}.c"
- "stm32xxxxx_{eval}{discovery}_io.c"
EndBSPDependencies */

/* Includes ------------------------------------------------------------------*/
#include "usbd_HID_custom2.h"
#include "usbd_ctlreq.h"

#define _CUSTOM_HID2_IN_EP 0x82U
#define _CUSTOM_HID2_OUT_EP 0x02U
#define _CUSTOM_HID2_ITF_NBR 0x01U
#define _CUSTOM_HID2_STR_DESC_IDX 0x05U

uint8_t CUSTOM_HID2_IN_EP = _CUSTOM_HID2_IN_EP;
uint8_t CUSTOM_HID2_OUT_EP = _CUSTOM_HID2_OUT_EP;
uint8_t CUSTOM_HID2_ITF_NBR = _CUSTOM_HID2_ITF_NBR;
uint8_t CUSTOM_HID2_STR_DESC_IDX = _CUSTOM_HID2_STR_DESC_IDX;

/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */

/** @defgroup USBD_CUSTOM_HID2
  * @brief usbd core module
  * @{
  */

/** @defgroup USBD_CUSTOM_HID2_Private_TypesDefinitions
  * @{
  */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID2_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID2_Private_Macros
  * @{
  */
/**
  * @}
  */
/** @defgroup USBD_CUSTOM_HID2_Private_FunctionPrototypes
  * @{
  */

static uint8_t USBD_CUSTOM_HID2_Init(USBD_HandleTypeDef *pdev, uint8_t cfgidx);
static uint8_t USBD_CUSTOM_HID2_DeInit(USBD_HandleTypeDef *pdev, uint8_t cfgidx);
static uint8_t USBD_CUSTOM_HID2_Setup(USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef *req);

static uint8_t USBD_CUSTOM_HID2_DataIn(USBD_HandleTypeDef *pdev, uint8_t epnum);
static uint8_t USBD_CUSTOM_HID2_DataOut(USBD_HandleTypeDef *pdev, uint8_t epnum);
static uint8_t USBD_CUSTOM_HID2_EP0_RxReady(USBD_HandleTypeDef *pdev);

static uint8_t *USBD_CUSTOM_HID2_GetFSCfgDesc(uint16_t *length);
static uint8_t *USBD_CUSTOM_HID2_GetHSCfgDesc(uint16_t *length);
static uint8_t *USBD_CUSTOM_HID2_GetOtherSpeedCfgDesc(uint16_t *length);
static uint8_t *USBD_CUSTOM_HID2_GetDeviceQualifierDesc(uint16_t *length);

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID2_Private_Variables
  * @{
  */

static USBD_CUSTOM_HID2_HandleTypeDef CUSTOM_HID2_Instance;

USBD_ClassTypeDef USBD_HID2_CUSTOM =
    {
        USBD_CUSTOM_HID2_Init,
        USBD_CUSTOM_HID2_DeInit,
        USBD_CUSTOM_HID2_Setup,
        NULL, /*EP0_TxSent*/
        USBD_CUSTOM_HID2_EP0_RxReady,
        /*EP0_RxReady*/         /* STATUS STAGE IN */
        USBD_CUSTOM_HID2_DataIn, /*DataIn*/
        USBD_CUSTOM_HID2_DataOut,
        NULL, /*SOF */
        NULL,
        NULL,
        USBD_CUSTOM_HID2_GetHSCfgDesc,
        USBD_CUSTOM_HID2_GetFSCfgDesc,
        USBD_CUSTOM_HID2_GetOtherSpeedCfgDesc,
        USBD_CUSTOM_HID2_GetDeviceQualifierDesc,
};

/* USB CUSTOM_HID2 device FS Configuration Descriptor */
__ALIGN_BEGIN static uint8_t USBD_CUSTOM_HID2_CfgFSDesc[USB_CUSTOM_HID2_CONFIG_DESC_SIZ] __ALIGN_END =
    {
        0x09,                           /* bLength: Configuration Descriptor size */
        USB_DESC_TYPE_CONFIGURATION,    /* bDescriptorType: Configuration */
        USB_CUSTOM_HID2_CONFIG_DESC_SIZ, /* wTotalLength: Bytes returned */
        0x00,
        0x01, /* bNumInterfaces: 1 interface */
        0x01, /* bConfigurationValue: Configuration value */
        0x00, /* iConfiguration: Index of string descriptor describing the configuration */
#if (USBD_SELF_POWERED == 1U)
        0xC0, /* bmAttributes: Bus Powered according to user configuration */
#else
        0x80, /* bmAttributes: Bus Powered according to user configuration */
#endif
        USBD_MAX_POWER, /* MaxPower 100 mA: this current is used for detecting Vbus */

        /************** Descriptor of CUSTOM HID2 interface ****************/
        /* 09 */
        0x09,                     /* bLength: Interface Descriptor size*/
        USB_DESC_TYPE_INTERFACE,  /* bDescriptorType: Interface descriptor type */
        _CUSTOM_HID2_ITF_NBR,      /* bInterfaceNumber: Number of Interface */
        0x00,                     /* bAlternateSetting: Alternate setting */
        0x02,                     /* bNumEndpoints*/
        0x03,                     /* bInterfaceClass: CUSTOM_HID2 */
        0x00,                     /* bInterfaceSubClass : 1=BOOT, 0=no boot */
        0x00,                     /* nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse */
        _CUSTOM_HID2_STR_DESC_IDX, /* iInterface: Index of string descriptor */
        /******************** Descriptor of CUSTOM_HID2 *************************/
        /* 18 */
        0x09,                       /* bLength: CUSTOM_HID2 Descriptor size */
        CUSTOM_HID2_DESCRIPTOR_TYPE, /* bDescriptorType: CUSTOM_HID2 */
        0x11,                       /* bCUSTOM_HID2USTOM_HID2: CUSTOM_HID2 Class Spec release number */
        0x01,
        0x00,                             /* bCountryCode: Hardware target country */
        0x01,                             /* bNumDescriptors: Number of CUSTOM_HID2 class descriptors to follow */
        0x22,                             /* bDescriptorType */
        USBD_CUSTOM_HID2_REPORT_DESC_SIZE, /* wItemLength: Total length of Report descriptor */
        0x00,
        /******************** Descriptor of Custom HID2 endpoints ********************/
        /* 27 */
        0x07,                   /* bLength: Endpoint Descriptor size */
        USB_DESC_TYPE_ENDPOINT, /* bDescriptorType: */
        _CUSTOM_HID2_IN_EP,      /* bEndpointAddress: Endpoint Address (IN) */
        0x03,                   /* bmAttributes: Interrupt endpoint */
        CUSTOM_HID2_EPIN_SIZE,   /* wMaxPacketSize: 2 Byte max */
        0x00,
        CUSTOM_HID2_FS_BINTERVAL, /* bInterval: Polling Interval */
        /* 34 */

        0x07,                   /* bLength: Endpoint Descriptor size */
        USB_DESC_TYPE_ENDPOINT, /* bDescriptorType: */
        _CUSTOM_HID2_OUT_EP,     /* bEndpointAddress: Endpoint Address (OUT) */
        0x03,                   /* bmAttributes: Interrupt endpoint */
        CUSTOM_HID2_EPOUT_SIZE,  /* wMaxPacketSize: 2 Bytes max  */
        0x00,
        CUSTOM_HID2_FS_BINTERVAL, /* bInterval: Polling Interval */
                                 /* 41 */
};

/* USB CUSTOM_HID2 device HS Configuration Descriptor */
__ALIGN_BEGIN static uint8_t USBD_CUSTOM_HID2_CfgHSDesc[USB_CUSTOM_HID2_CONFIG_DESC_SIZ] __ALIGN_END =
    {
        0x09,                           /* bLength: Configuration Descriptor size */
        USB_DESC_TYPE_CONFIGURATION,    /* bDescriptorType: Configuration */
        USB_CUSTOM_HID2_CONFIG_DESC_SIZ, /* wTotalLength: Bytes returned */
        0x00,
        0x01, /* bNumInterfaces: 1 interface */
        0x01, /* bConfigurationValue: Configuration value */
        0x00, /* iConfiguration: Index of string descriptor describing the configuration */
#if (USBD_SELF_POWERED == 1U)
        0xC0, /* bmAttributes: Bus Powered according to user configuration */
#else
        0x80, /* bmAttributes: Bus Powered according to user configuration */
#endif
        USBD_MAX_POWER, /* MaxPower 100 mA: this current is used for detecting Vbus */

        /************** Descriptor of CUSTOM HID2 interface ****************/
        /* 09 */
        0x09,                     /* bLength: Interface Descriptor size */
        USB_DESC_TYPE_INTERFACE,  /* bDescriptorType: Interface descriptor type */
        _CUSTOM_HID2_ITF_NBR,      /* bInterfaceNumber: Number of Interface */
        0x00,                     /* bAlternateSetting: Alternate setting */
        0x02,                     /* bNumEndpoints */
        0x03,                     /* bInterfaceClass: CUSTOM_HID2 */
        0x00,                     /* bInterfaceSubClass : 1=BOOT, 0=no boot */
        0x00,                     /* nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse */
        _CUSTOM_HID2_STR_DESC_IDX, /* iInterface: Index of string descriptor */
        /******************** Descriptor of CUSTOM_HID2 *************************/
        /* 18 */
        0x09,                       /* bLength: CUSTOM_HID2 Descriptor size */
        CUSTOM_HID2_DESCRIPTOR_TYPE, /* bDescriptorType: CUSTOM_HID2 */
        0x11,                       /* bCUSTOM_HID2USTOM_HID2: CUSTOM_HID2 Class Spec release number */
        0x01,
        0x00,                             /* bCountryCode: Hardware target country */
        0x01,                             /* bNumDescriptors: Number of CUSTOM_HID2 class descriptors to follow */
        0x22,                             /* bDescriptorType */
        USBD_CUSTOM_HID2_REPORT_DESC_SIZE, /* wItemLength: Total length of Report descriptor */
        0x00,
        /******************** Descriptor of Custom HID2 endpoints ********************/
        /* 27 */
        0x07,                   /* bLength: Endpoint Descriptor size */
        USB_DESC_TYPE_ENDPOINT, /* bDescriptorType: */
        _CUSTOM_HID2_IN_EP,      /* bEndpointAddress: Endpoint Address (IN) */
        0x03,                   /* bmAttributes: Interrupt endpoint */
        CUSTOM_HID2_EPIN_SIZE,   /* wMaxPacketSize: 2 Byte max */
        0x00,
        CUSTOM_HID2_HS_BINTERVAL, /* bInterval: Polling Interval */
        /* 34 */

        0x07,                   /* bLength: Endpoint Descriptor size */
        USB_DESC_TYPE_ENDPOINT, /* bDescriptorType: */
        _CUSTOM_HID2_OUT_EP,     /* bEndpointAddress: Endpoint Address (OUT) */
        0x03,                   /* bmAttributes: Interrupt endpoint */
        CUSTOM_HID2_EPOUT_SIZE,  /* wMaxPacketSize: 2 Bytes max  */
        0x00,
        CUSTOM_HID2_HS_BINTERVAL, /* bInterval: Polling Interval */
                                 /* 41 */
};

/* USB CUSTOM_HID2 device Other Speed Configuration Descriptor */
__ALIGN_BEGIN static uint8_t USBD_CUSTOM_HID2_OtherSpeedCfgDesc[USB_CUSTOM_HID2_CONFIG_DESC_SIZ] __ALIGN_END =
    {
        0x09,                           /* bLength: Configuration Descriptor size */
        USB_DESC_TYPE_CONFIGURATION,    /* bDescriptorType: Configuration */
        USB_CUSTOM_HID2_CONFIG_DESC_SIZ, /* wTotalLength: Bytes returned */
        0x00,
        0x01, /* bNumInterfaces: 1 interface */
        0x01, /* bConfigurationValue: Configuration value */
        0x00, /* iConfiguration: Index of string descriptor describing the configuration */
#if (USBD_SELF_POWERED == 1U)
        0xC0, /* bmAttributes: Bus Powered according to user configuration */
#else
        0x80, /* bmAttributes: Bus Powered according to user configuration */
#endif
        USBD_MAX_POWER, /* MaxPower 100 mA: this current is used for detecting Vbus */

        /************** Descriptor of CUSTOM HID2 interface ****************/
        /* 09 */
        0x09,                     /* bLength: Interface Descriptor size */
        USB_DESC_TYPE_INTERFACE,  /* bDescriptorType: Interface descriptor type */
        _CUSTOM_HID2_ITF_NBR,      /* bInterfaceNumber: Number of Interface */
        0x00,                     /* bAlternateSetting: Alternate setting */
        0x02,                     /* bNumEndpoints */
        0x03,                     /* bInterfaceClass: CUSTOM_HID2 */
        0x00,                     /* bInterfaceSubClass : 1=BOOT, 0=no boot */
        0x00,                     /* nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse */
        _CUSTOM_HID2_STR_DESC_IDX, /* iInterface: Index of string descriptor */
        /******************** Descriptor of CUSTOM_HID2 *************************/
        /* 18 */
        0x09,                       /* bLength: CUSTOM_HID2 Descriptor size */
        CUSTOM_HID2_DESCRIPTOR_TYPE, /* bDescriptorType: CUSTOM_HID2 */
        0x11,                       /* bCUSTOM_HID2USTOM_HID2: CUSTOM_HID2 Class Spec release number */
        0x01,
        0x00,                             /* bCountryCode: Hardware target country */
        0x01,                             /* bNumDescriptors: Number of CUSTOM_HID2 class descriptors to follow */
        0x22,                             /* bDescriptorType */
        USBD_CUSTOM_HID2_REPORT_DESC_SIZE, /* wItemLength: Total length of Report descriptor */
        0x00,
        /******************** Descriptor of Custom HID2 endpoints ********************/
        /* 27 */
        0x07,                   /* bLength: Endpoint Descriptor size */
        USB_DESC_TYPE_ENDPOINT, /* bDescriptorType: */
        _CUSTOM_HID2_IN_EP,      /* bEndpointAddress: Endpoint Address (IN) */
        0x03,                   /* bmAttributes: Interrupt endpoint */
        CUSTOM_HID2_EPIN_SIZE,   /* wMaxPacketSize: 2 Bytes max */
        0x00,
        CUSTOM_HID2_FS_BINTERVAL, /* bInterval: Polling Interval */
        /* 34 */

        0x07,                   /* bLength: Endpoint Descriptor size */
        USB_DESC_TYPE_ENDPOINT, /* bDescriptorType: */
        _CUSTOM_HID2_OUT_EP,     /* bEndpointAddress: Endpoint Address (OUT) */
        0x03,                   /* bmAttributes: Interrupt endpoint */
        CUSTOM_HID2_EPOUT_SIZE,  /* wMaxPacketSize: 2 Bytes max */
        0x00,
        CUSTOM_HID2_FS_BINTERVAL, /* bInterval: Polling Interval */
                                 /* 41 */
};

/* USB CUSTOM_HID2 device Configuration Descriptor */
__ALIGN_BEGIN static uint8_t USBD_CUSTOM_HID2_Desc[USB_CUSTOM_HID2_DESC_SIZ] __ALIGN_END =
    {
        /* 18 */
        0x09,                       /* bLength: CUSTOM_HID2 Descriptor size */
        CUSTOM_HID2_DESCRIPTOR_TYPE, /* bDescriptorType: CUSTOM_HID2 */
        0x11,                       /* bCUSTOM_HID2USTOM_HID2: CUSTOM_HID2 Class Spec release number */
        0x01,
        0x00,                             /* bCountryCode: Hardware target country */
        0x01,                             /* bNumDescriptors: Number of CUSTOM_HID2 class descriptors to follow */
        0x22,                             /* bDescriptorType */
        USBD_CUSTOM_HID2_REPORT_DESC_SIZE, /* wItemLength: Total length of Report descriptor */
        0x00,
};

/* USB Standard Device Descriptor */
__ALIGN_BEGIN static uint8_t USBD_CUSTOM_HID2_DeviceQualifierDesc[USB_LEN_DEV_QUALIFIER_DESC] __ALIGN_END =
    {
        USB_LEN_DEV_QUALIFIER_DESC,
        USB_DESC_TYPE_DEVICE_QUALIFIER,
        0x00,
        0x02,
        0x00,
        0x00,
        0x00,
        0x40,
        0x01,
        0x00,
};

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID2_Private_Functions
  * @{
  */

/**
  * @brief  USBD_CUSTOM_HID2_Init
  *         Initialize the CUSTOM_HID2 interface
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
static uint8_t USBD_CUSTOM_HID2_Init(USBD_HandleTypeDef *pdev, uint8_t cfgidx)
{
  UNUSED(cfgidx);
  USBD_CUSTOM_HID2_HandleTypeDef *hhid2;

  hhid2 = &CUSTOM_HID2_Instance;

  if (hhid2 == NULL)
  {
    pdev->pClassData_HID2_Custom = NULL;
    return (uint8_t)USBD_EMEM;
  }

  pdev->pClassData_HID2_Custom = (void *)hhid2;

  if (pdev->dev_speed == USBD_SPEED_HIGH)
  {
    pdev->ep_in[CUSTOM_HID2_IN_EP & 0xFU].bInterval = CUSTOM_HID2_HS_BINTERVAL;
    pdev->ep_out[CUSTOM_HID2_OUT_EP & 0xFU].bInterval = CUSTOM_HID2_HS_BINTERVAL;
  }
  else /* LOW and FULL-speed endpoints */
  {
    pdev->ep_in[CUSTOM_HID2_IN_EP & 0xFU].bInterval = CUSTOM_HID2_FS_BINTERVAL;
    pdev->ep_out[CUSTOM_HID2_OUT_EP & 0xFU].bInterval = CUSTOM_HID2_FS_BINTERVAL;
  }

  /* Open EP IN */
  (void)USBD_LL_OpenEP(pdev, CUSTOM_HID2_IN_EP, USBD_EP_TYPE_INTR,
                       CUSTOM_HID2_EPIN_SIZE);

  pdev->ep_in[CUSTOM_HID2_IN_EP & 0xFU].is_used = 1U;

  /* Open EP OUT */
  (void)USBD_LL_OpenEP(pdev, CUSTOM_HID2_OUT_EP, USBD_EP_TYPE_INTR,
                       CUSTOM_HID2_EPOUT_SIZE);

  pdev->ep_out[CUSTOM_HID2_OUT_EP & 0xFU].is_used = 1U;

  hhid2->state = CUSTOM_HID2_IDLE;

  ((USBD_CUSTOM_HID2_ItfTypeDef *)pdev->pUserData_HID2_Custom)->Init();

  /* Prepare Out endpoint to receive 1st packet */
  (void)USBD_LL_PrepareReceive(pdev, CUSTOM_HID2_OUT_EP, hhid2->Report_buf,
                               USBD_CUSTOMHID2_OUTREPORT_BUF_SIZE);

  return (uint8_t)USBD_OK;
}

/**
  * @brief  USBD_CUSTOM_HID2_Init
  *         DeInitialize the CUSTOM_HID2 layer
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
static uint8_t USBD_CUSTOM_HID2_DeInit(USBD_HandleTypeDef *pdev, uint8_t cfgidx)
{
  UNUSED(cfgidx);

  /* Close CUSTOM_HID2 EP IN */
  (void)USBD_LL_CloseEP(pdev, CUSTOM_HID2_IN_EP);
  pdev->ep_in[CUSTOM_HID2_IN_EP & 0xFU].is_used = 0U;
  pdev->ep_in[CUSTOM_HID2_IN_EP & 0xFU].bInterval = 0U;

  /* Close CUSTOM_HID2 EP OUT */
  (void)USBD_LL_CloseEP(pdev, CUSTOM_HID2_OUT_EP);
  pdev->ep_out[CUSTOM_HID2_OUT_EP & 0xFU].is_used = 0U;
  pdev->ep_out[CUSTOM_HID2_OUT_EP & 0xFU].bInterval = 0U;

  /* Free allocated memory */
  if (pdev->pClassData_HID2_Custom != NULL)
  {
    ((USBD_CUSTOM_HID2_ItfTypeDef *)pdev->pUserData_HID2_Custom)->DeInit();
#if (0)
    USBD_free(pdev->pClassData_HID2_Custom);
#endif
    pdev->pClassData_HID2_Custom = NULL;
  }

  return (uint8_t)USBD_OK;
}

/**
  * @brief  USBD_CUSTOM_HID2_Setup
  *         Handle the CUSTOM_HID2 specific requests
  * @param  pdev: instance
  * @param  req: usb requests
  * @retval status
  */
static uint8_t USBD_CUSTOM_HID2_Setup(USBD_HandleTypeDef *pdev,
                                     USBD_SetupReqTypedef *req)
{
  USBD_CUSTOM_HID2_HandleTypeDef *hhid2 = (USBD_CUSTOM_HID2_HandleTypeDef *)pdev->pClassData_HID2_Custom;
  uint16_t len = 0U;
  uint8_t *pbuf = NULL;
  uint16_t status_info = 0U;
  USBD_StatusTypeDef ret = USBD_OK;

  if (hhid2 == NULL)
  {
    return (uint8_t)USBD_FAIL;
  }

  switch (req->bmRequest & USB_REQ_TYPE_MASK)
  {
  case USB_REQ_TYPE_CLASS:
    switch (req->bRequest)
    {
    case CUSTOM_HID2_REQ_SET_PROTOCOL:
      hhid2->Protocol = (uint8_t)(req->wValue);
      break;

    case CUSTOM_HID2_REQ_GET_PROTOCOL:
      (void)USBD_CtlSendData(pdev, (uint8_t *)&hhid2->Protocol, 1U);
      break;

    case CUSTOM_HID2_REQ_SET_IDLE:
      hhid2->IdleState = (uint8_t)(req->wValue >> 8);
      break;

    case CUSTOM_HID2_REQ_GET_IDLE:
      (void)USBD_CtlSendData(pdev, (uint8_t *)&hhid2->IdleState, 1U);
      break;

    case CUSTOM_HID2_REQ_SET_REPORT:
      hhid2->IsReportAvailable = 1U;
      (void)USBD_CtlPrepareRx(pdev, hhid2->Report_buf, req->wLength);
      break;

    default:
      USBD_CtlError(pdev, req);
      ret = USBD_FAIL;
      break;
    }
    break;

  case USB_REQ_TYPE_STANDARD:
    switch (req->bRequest)
    {
    case USB_REQ_GET_STATUS:
      if (pdev->dev_state == USBD_STATE_CONFIGURED)
      {
        (void)USBD_CtlSendData(pdev, (uint8_t *)&status_info, 2U);
      }
      else
      {
        USBD_CtlError(pdev, req);
        ret = USBD_FAIL;
      }
      break;

    case USB_REQ_GET_DESCRIPTOR:
      if ((req->wValue >> 8) == CUSTOM_HID2_REPORT_DESC)
      {
        len = MIN(USBD_CUSTOM_HID2_REPORT_DESC_SIZE, req->wLength);
        pbuf = ((USBD_CUSTOM_HID2_ItfTypeDef *)pdev->pUserData_HID2_Custom)->pReport;
      }
      else
      {
        if ((req->wValue >> 8) == CUSTOM_HID2_DESCRIPTOR_TYPE)
        {
          pbuf = USBD_CUSTOM_HID2_Desc;
          len = MIN(USB_CUSTOM_HID2_DESC_SIZ, req->wLength);
        }
      }

      (void)USBD_CtlSendData(pdev, pbuf, len);
      break;

    case USB_REQ_GET_INTERFACE:
      if (pdev->dev_state == USBD_STATE_CONFIGURED)
      {
        (void)USBD_CtlSendData(pdev, (uint8_t *)&hhid2->AltSetting, 1U);
      }
      else
      {
        USBD_CtlError(pdev, req);
        ret = USBD_FAIL;
      }
      break;

    case USB_REQ_SET_INTERFACE:
      if (pdev->dev_state == USBD_STATE_CONFIGURED)
      {
        hhid2->AltSetting = (uint8_t)(req->wValue);
      }
      else
      {
        USBD_CtlError(pdev, req);
        ret = USBD_FAIL;
      }
      break;

    case USB_REQ_CLEAR_FEATURE:
      break;

    default:
      USBD_CtlError(pdev, req);
      ret = USBD_FAIL;
      break;
    }
    break;

  default:
    USBD_CtlError(pdev, req);
    ret = USBD_FAIL;
    break;
  }
  return (uint8_t)ret;
}

/**
  * @brief  USBD_CUSTOM_HID2_SendReport
  *         Send CUSTOM_HID2 Report
  * @param  pdev: device instance
  * @param  buff: pointer to report
  * @retval status
  */
uint8_t USBD_CUSTOM_HID2_SendReport(USBD_HandleTypeDef *pdev,
                                   uint8_t *report, uint16_t len)
{
  USBD_CUSTOM_HID2_HandleTypeDef *hhid2;

  if (pdev->pClassData_HID2_Custom == NULL)
  {
    return (uint8_t)USBD_FAIL;
  }

  hhid2 = (USBD_CUSTOM_HID2_HandleTypeDef *)pdev->pClassData_HID2_Custom;

  if (pdev->dev_state == USBD_STATE_CONFIGURED)
  {
    if (hhid2->state == CUSTOM_HID2_IDLE)
    {
      hhid2->state = CUSTOM_HID2_BUSY;
      (void)USBD_LL_Transmit(pdev, CUSTOM_HID2_IN_EP, report, len);
    }
    else
    {
      return (uint8_t)USBD_BUSY;
    }
  }
  return (uint8_t)USBD_OK;
}

/**
  * @brief  USBD_CUSTOM_HID2_GetFSCfgDesc
  *         return FS configuration descriptor
  * @param  speed : current device speed
  * @param  length : pointer data length
  * @retval pointer to descriptor buffer
  */
static uint8_t *USBD_CUSTOM_HID2_GetFSCfgDesc(uint16_t *length)
{
  *length = (uint16_t)sizeof(USBD_CUSTOM_HID2_CfgFSDesc);

  return USBD_CUSTOM_HID2_CfgFSDesc;
}

/**
  * @brief  USBD_CUSTOM_HID2_GetHSCfgDesc
  *         return HS configuration descriptor
  * @param  speed : current device speed
  * @param  length : pointer data length
  * @retval pointer to descriptor buffer
  */
static uint8_t *USBD_CUSTOM_HID2_GetHSCfgDesc(uint16_t *length)
{
  *length = (uint16_t)sizeof(USBD_CUSTOM_HID2_CfgHSDesc);

  return USBD_CUSTOM_HID2_CfgHSDesc;
}

/**
  * @brief  USBD_CUSTOM_HID2_GetOtherSpeedCfgDesc
  *         return other speed configuration descriptor
  * @param  speed : current device speed
  * @param  length : pointer data length
  * @retval pointer to descriptor buffer
  */
static uint8_t *USBD_CUSTOM_HID2_GetOtherSpeedCfgDesc(uint16_t *length)
{
  *length = (uint16_t)sizeof(USBD_CUSTOM_HID2_OtherSpeedCfgDesc);

  return USBD_CUSTOM_HID2_OtherSpeedCfgDesc;
}

/**
  * @brief  USBD_CUSTOM_HID2_DataIn
  *         handle data IN Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t USBD_CUSTOM_HID2_DataIn(USBD_HandleTypeDef *pdev, uint8_t epnum)
{
  UNUSED(epnum);

  /* Ensure that the FIFO is empty before a new transfer, this condition could
  be caused by  a new transfer before the end of the previous transfer */
  ((USBD_CUSTOM_HID2_HandleTypeDef *)pdev->pClassData_HID2_Custom)->state = CUSTOM_HID2_IDLE;

  return (uint8_t)USBD_OK;
}

/**
  * @brief  USBD_CUSTOM_HID2_DataOut
  *         handle data OUT Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t USBD_CUSTOM_HID2_DataOut(USBD_HandleTypeDef *pdev, uint8_t epnum)
{
  UNUSED(epnum);
  USBD_CUSTOM_HID2_HandleTypeDef *hhid2;

  if (pdev->pClassData_HID2_Custom == NULL)
  {
    return (uint8_t)USBD_FAIL;
  }

  hhid2 = (USBD_CUSTOM_HID2_HandleTypeDef *)pdev->pClassData_HID2_Custom;

  /* USB data will be immediately processed, this allow next USB traffic being
  NAKed till the end of the application processing */
  ((USBD_CUSTOM_HID2_ItfTypeDef *)pdev->pUserData_HID2_Custom)->OutEvent(hhid2->Report_buf[0], hhid2->Report_buf[1]);

  return (uint8_t)USBD_OK;
}

/**
  * @brief  USBD_CUSTOM_HID2_ReceivePacket
  *         prepare OUT Endpoint for reception
  * @param  pdev: device instance
  * @retval status
  */
uint8_t USBD_CUSTOM_HID2_ReceivePacket(USBD_HandleTypeDef *pdev)
{
  USBD_CUSTOM_HID2_HandleTypeDef *hhid2;

  if (pdev->pClassData_HID2_Custom == NULL)
  {
    return (uint8_t)USBD_FAIL;
  }

  hhid2 = (USBD_CUSTOM_HID2_HandleTypeDef *)pdev->pClassData_HID2_Custom;

  /* Resume USB Out process */
  (void)USBD_LL_PrepareReceive(pdev, CUSTOM_HID2_OUT_EP, hhid2->Report_buf,
                               USBD_CUSTOMHID2_OUTREPORT_BUF_SIZE);

  return (uint8_t)USBD_OK;
}

/**
  * @brief  USBD_CUSTOM_HID2_EP0_RxReady
  *         Handles control request data.
  * @param  pdev: device instance
  * @retval status
  */
static uint8_t USBD_CUSTOM_HID2_EP0_RxReady(USBD_HandleTypeDef *pdev)
{
  USBD_CUSTOM_HID2_HandleTypeDef *hhid2 = (USBD_CUSTOM_HID2_HandleTypeDef *)pdev->pClassData_HID2_Custom;

  if (hhid2 == NULL)
  {
    return (uint8_t)USBD_FAIL;
  }

  if (hhid2->IsReportAvailable == 1U)
  {
    ((USBD_CUSTOM_HID2_ItfTypeDef *)pdev->pUserData_HID2_Custom)->OutEvent(hhid2->Report_buf[0], hhid2->Report_buf[1]);
    hhid2->IsReportAvailable = 0U;
  }

  return (uint8_t)USBD_OK;
}

/**
  * @brief  DeviceQualifierDescriptor
  *         return Device Qualifier descriptor
  * @param  length : pointer data length
  * @retval pointer to descriptor buffer
  */
static uint8_t *USBD_CUSTOM_HID2_GetDeviceQualifierDesc(uint16_t *length)
{
  *length = (uint16_t)sizeof(USBD_CUSTOM_HID2_DeviceQualifierDesc);

  return USBD_CUSTOM_HID2_DeviceQualifierDesc;
}

/**
  * @brief  USBD_CUSTOM_HID2_RegisterInterface
  * @param  pdev: device instance
  * @param  fops: CUSTOMHID2 Interface callback
  * @retval status
  */
uint8_t USBD_CUSTOM_HID2_RegisterInterface(USBD_HandleTypeDef *pdev,
                                          USBD_CUSTOM_HID2_ItfTypeDef *fops)
{
  if (fops == NULL)
  {
    return (uint8_t)USBD_FAIL;
  }

  pdev->pUserData_HID2_Custom = fops;

  return (uint8_t)USBD_OK;
}

void USBD_Update_HID2_Custom_DESC(uint8_t *desc, uint8_t itf_no, uint8_t in_ep, uint8_t out_ep, uint8_t str_idx)
{
  desc[11] = itf_no;
  desc[17] = str_idx;
  desc[29] = in_ep;
  desc[36] = out_ep;

  CUSTOM_HID2_IN_EP = in_ep;
  CUSTOM_HID2_OUT_EP = out_ep;
  CUSTOM_HID2_ITF_NBR = itf_no;
  CUSTOM_HID2_STR_DESC_IDX = str_idx;
}

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
