/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : lvgl_lcd.c
  * @brief          : This file contains the implementation for LCD and LVGL initialization,
  *                   flush callback, and touch input handling.
  ******************************************************************************
  * @notice
  * Copyright (c) 2025 by [Your Name/Organization]
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "lvgl_lcd.h"
#include "main.h"
#include "ili9341.h"
#include "lvgl.h"
#include "ui.h"
#include "actions.h"
#include "misko_touch.h"
#include "tim.h"
#include "vars.h"
#include "FLASH_PAGE.h"


/* Static Variables ----------------------------------------------------------*/
uint8_t buf1[RESOLUTION_HORIZONTAL * RESOLUTION_VERTICAL / 10 * BYTES_PER_PIXEL];
volatile uint8_t t_irq_state;
lv_coord_t last_x = 0;
lv_coord_t last_y = 0;
uint16_t available_frequencies[] = {10, 50, 100, 250, 500, 750, 1000};
char available_frequencies_str[100] = "";

extern SystemSettings system_settings;


/* Function Implementations --------------------------------------------------*/

void lcd_init(void) {
    HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
    HAL_Delay(50);
    HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
    Set_Brightness(80);
}

void lvgl_init(void) {
	lcdInit();
	lcdSetOrientation(LCD_ORIENTATION_LANDSCAPE);
	lv_init();
	lv_tick_set_cb(HAL_GetTick);
	lv_display_t * display1 = lv_display_create(RESOLUTION_HORIZONTAL, RESOLUTION_VERTICAL);
	lv_display_set_buffers(display1, buf1, NULL, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);
	lv_display_set_flush_cb(display1, my_flush_cb);
	lv_indev_t * indev = lv_indev_create();
	lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
	lv_indev_set_read_cb(indev, touchpad_read);
	ui_init();
	set_var_force_feedback_status("!FFB ON!");	//Just a text box value setter
}

void my_flush_cb(lv_display_t * display, const lv_area_t * area, uint8_t * px_map) {
    /* Set the display window to the specified area */
    lcdSetWindow(area->x1, area->y1, area->x2, area->y2);

    /* Calculate the number of pixels in the area */
    int32_t width = area->x2 - area->x1 + 1;
    int32_t height = area->y2 - area->y1 + 1;
    int32_t pixel_count = width * height;

    /* Cast buffer to uint16_t for RGB565 format */
    uint16_t * buf16 = (uint16_t *)px_map;

    /* Write the entire pixel buffer to the LCD memory-mapped register */
    volatile uint16_t * lcd_reg = (volatile uint16_t *)LCD_BASE1;
    for (int32_t i = 0; i < pixel_count; i++) {
        *lcd_reg = buf16[i];
    }

    /* Inform LVGL that flushing is complete */
    lv_display_flush_ready(display);
}

void touchpad_read(lv_indev_t * indev, lv_indev_data_t * data)
{
    /*Save the pressed coordinates and the state*/
    if(touchCheckPressed()) {
    	touchReadXY(&last_x, &last_y);
        data->state = LV_INDEV_STATE_PRESSED;
    }
    else {
        data->state = LV_INDEV_STATE_RELEASED;
    }

    /*Set the last pressed coordinates*/
    data->point.x = last_x;
    data->point.y = last_y;
}

void convert_frequencies_to_string(void) {
    int position = 0;
    int max_size = sizeof(available_frequencies_str);

    for (int i = 0; i < sizeof(available_frequencies) / sizeof(available_frequencies[0]); i++) {
        if (i > 0) {
            position += snprintf(available_frequencies_str + position, max_size - position, "\n");
        }
        position += snprintf(available_frequencies_str + position, max_size - position, "%d", available_frequencies[i]);

        if (position >= max_size) {
            break;
        }
    }
}

int32_t get_selector_position_to_frequency(){
	uint32_t position = lv_dropdown_get_selected(objects.sampling_freq_selector);
	return available_frequencies[position];
}

uint32_t get_selector_position_from_frequency(int32_t frequency) {
    uint32_t position = -1;
    size_t array_size = sizeof(available_frequencies) / sizeof(available_frequencies[0]);
    for (size_t i = 0; i < array_size; i++) {
        if (available_frequencies[i] == frequency) {
            position = (uint32_t)i;
            break;
        }
    }
    return position;
}

void lvgl_ui_init(){
	convert_frequencies_to_string();
	set_var_frequencies(available_frequencies_str);
	set_var_selected_frequency_position(get_selector_position_from_frequency(system_settings.frequency));
	set_var_ffb_state(system_settings.ffb);
	set_var_force_feedback_status(system_settings.ffb ? "1" : "0");
	set_var_brightness(system_settings.brightness);
}
