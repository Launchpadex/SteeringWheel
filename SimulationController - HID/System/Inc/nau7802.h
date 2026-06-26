#ifndef NAU7802_H
#define NAU7802_H

#include "main.h"
#include <stdbool.h>

/* I2C address */
#define NAU7802_ADDR        (0x2A << 1)

/* Gain options for CTRL1 */
typedef enum {
    NAU7802_GAIN_1   = 0,
    NAU7802_GAIN_2   = 1,
    NAU7802_GAIN_4   = 2,
    NAU7802_GAIN_8   = 3,
    NAU7802_GAIN_16  = 4,
    NAU7802_GAIN_32  = 5,
    NAU7802_GAIN_64  = 6,
    NAU7802_GAIN_128 = 7,
} NAU7802_Gain;

/* Sample rate options for CTRL2 */
typedef enum {
    NAU7802_SPS_10  = 0,
    NAU7802_SPS_20  = 1,
    NAU7802_SPS_40  = 2,
    NAU7802_SPS_80  = 3,
    NAU7802_SPS_320 = 7,
} NAU7802_SPS;

bool    NAU7802_Init(I2C_HandleTypeDef *hi2c, NAU7802_Gain gain, NAU7802_SPS sps);
bool    NAU7802_IsDataReady(I2C_HandleTypeDef *hi2c);
int32_t NAU7802_ReadRaw(I2C_HandleTypeDef *hi2c);
void    NAU7802_Tare(I2C_HandleTypeDef *hi2c);
int32_t NAU7802_ReadTared(I2C_HandleTypeDef *hi2c);

#endif /* NAU7802_H */
