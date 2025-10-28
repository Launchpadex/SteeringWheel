/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LVGL_LCD_H
#define __LVGL_LCD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"
#include "lvgl.h"

/* Defines -------------------------------------------------------------------*/
#define RESOLUTION_HORIZONTAL 320
#define RESOLUTION_VERTICAL 240
#define BYTES_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565))

/* Function Prototypes -------------------------------------------------------*/
void lcd_init(void);
void lvgl_init(void);
void Set_Brightness(uint8_t brightness);
void my_flush_cb(lv_display_t * display, const lv_area_t * area, uint8_t * px_map);
void touchpad_read(lv_indev_t * indev, lv_indev_data_t * data);
int32_t get_selector_position_to_frequency(void);
uint32_t get_selector_position_from_frequency(int32_t frequency);
void lvgl_ui_init(void);

/* External Variables (to be defined in .c or other headers) ------------------*/
extern uint8_t buf1[];
extern volatile uint8_t t_irq_state;
extern lv_coord_t last_x;
extern lv_coord_t last_y;

#ifdef __cplusplus
}
#endif

#endif /* __LVGL_LCD_H */
