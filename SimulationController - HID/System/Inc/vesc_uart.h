/**
  ******************************************************************************
  * @file    vesc_uart.h
  * @brief   Minimal VESC UART driver — current control only.
  ******************************************************************************
  */

#ifndef VESC_UART_H
#define VESC_UART_H

#include "stm32g4xx_hal.h"
#include <stdint.h>

void vesc_init(UART_HandleTypeDef *huart);

// Set motor current in amperes (positive = drive, negative = reverse)
void vesc_set_current(float current_amps);

// Set braking current in amperes
void vesc_set_current_brake(float current_amps);

// Stop motor immediately (sends 0 A)
void vesc_stop(void);

// Queue current from ISR context — call vesc_process_pending() from main loop
void vesc_queue_current(int32_t current_mA);
void vesc_process_pending(void);

#endif // VESC_UART_H
