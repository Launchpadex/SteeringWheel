/**
  ******************************************************************************
  * @file    vesc_uart.c
  * @brief   Minimal VESC UART driver — current control only.
  *
  * Packet format: [0x02] [len] [payload...] [crc_hi] [crc_lo] [0x03]
  * All values big-endian. Current scaled by 1000 (5.0 A → 5000).
  ******************************************************************************
  */

#include "vesc_uart.h"
#include <string.h>

#define COMM_SET_CURRENT        6
#define COMM_SET_CURRENT_BRAKE  7

static UART_HandleTypeDef *_huart;

static volatile int32_t _pending_current_mA = 0;
static volatile int      _pending            = 0;

/* ---------------------------------------------------------------------------
 * CRC16 (CCITT)
 * --------------------------------------------------------------------------- */
static uint16_t crc16(const uint8_t *buf, uint16_t len)
{
    uint16_t crc = 0;
    while (len--) {
        uint8_t b = *buf++;
        for (int i = 0; i < 8; i++) {
            if ((crc ^ ((uint16_t)b << 8)) & 0x8000)
                crc = (crc << 1) ^ 0x1021;
            else
                crc <<= 1;
            b <<= 1;
        }
    }
    return crc;
}

/* ---------------------------------------------------------------------------
 * Build and transmit one packet
 * --------------------------------------------------------------------------- */
static void send_packet(const uint8_t *payload, uint8_t len)
{
    // Max packet: 1 header + 1 len + 5 payload + 2 crc + 1 end = 10 bytes
    uint8_t buf[16];
    uint8_t i = 0;

    buf[i++] = 0x02;    // short-packet header
    buf[i++] = len;

    memcpy(&buf[i], payload, len);
    i += len;

    uint16_t crc = crc16(payload, len);
    buf[i++] = (crc >> 8) & 0xFF;
    buf[i++] =  crc       & 0xFF;
    buf[i++] = 0x03;    // end byte

    HAL_UART_Transmit(_huart, buf, i, 100);
}

/* ---------------------------------------------------------------------------
 * Append int32 big-endian into buffer
 * --------------------------------------------------------------------------- */
static void append_int32(uint8_t *buf, int32_t val, int *idx)
{
    buf[(*idx)++] = (val >> 24) & 0xFF;
    buf[(*idx)++] = (val >> 16) & 0xFF;
    buf[(*idx)++] = (val >>  8) & 0xFF;
    buf[(*idx)++] =  val        & 0xFF;
}

/* ---------------------------------------------------------------------------
 * Public API
 * --------------------------------------------------------------------------- */
void vesc_init(UART_HandleTypeDef *huart)
{
    _huart = huart;
}

void vesc_set_current(float current_amps)
{
    uint8_t payload[5];
    int idx = 0;
    payload[idx++] = COMM_SET_CURRENT;
    append_int32(payload, (int32_t)(current_amps * 1000.0f), &idx);
    send_packet(payload, idx);
}

void vesc_set_current_brake(float current_amps)
{
    uint8_t payload[5];
    int idx = 0;
    payload[idx++] = COMM_SET_CURRENT_BRAKE;
    append_int32(payload, (int32_t)(current_amps * 1000.0f), &idx);
    send_packet(payload, idx);
}

void vesc_stop(void)
{
    vesc_set_current(0.0f);
}

void vesc_queue_current(int32_t current_mA)
{
    _pending_current_mA = current_mA;
    _pending = 1;
}

void vesc_process_pending(void)
{
    if (_pending) {
        int32_t current = _pending_current_mA;
        _pending = 0;
        vesc_set_current(current / 1000.0f);
    }
}
