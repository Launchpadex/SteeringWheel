#include "nau7802.h"

/* Register map */
#define REG_PU_CTRL  0x00
#define REG_CTRL1    0x01
#define REG_CTRL2    0x02
#define REG_ADCO_B2  0x12   /* result MSB */
#define REG_ADCO_B1  0x13
#define REG_ADCO_B0  0x14
#define REG_ADC      0x15   /* ADC chopper control */
#define REG_PGA      0x1B   /* PGA chopper control */

/* PU_CTRL bits */
#define PU_CTRL_RR      (1 << 0)   /* register reset */
#define PU_CTRL_PUD     (1 << 1)   /* power up digital */
#define PU_CTRL_PUA     (1 << 2)   /* power up analog  */
#define PU_CTRL_PWRUP   (1 << 3)   /* power-up ready (read-only) */
#define PU_CTRL_CS      (1 << 4)   /* cycle start */
#define PU_CTRL_CR      (1 << 5)   /* cycle ready / data ready (read-only) */

#define I2C_TIMEOUT 10

static int32_t g_tare_offset = 0;

/* ------------------------------------------------------------------ */
static bool reg_write(I2C_HandleTypeDef *hi2c, uint8_t reg, uint8_t val)
{
    uint8_t buf[2] = { reg, val };
    return HAL_I2C_Master_Transmit(hi2c, NAU7802_ADDR, buf, 2, I2C_TIMEOUT) == HAL_OK;
}

static bool reg_read(I2C_HandleTypeDef *hi2c, uint8_t reg, uint8_t *val)
{
    if (HAL_I2C_Master_Transmit(hi2c, NAU7802_ADDR, &reg, 1, I2C_TIMEOUT) != HAL_OK)
        return false;
    return HAL_I2C_Master_Receive(hi2c, NAU7802_ADDR, val, 1, I2C_TIMEOUT) == HAL_OK;
}
/* ------------------------------------------------------------------ */

bool NAU7802_Init(I2C_HandleTypeDef *hi2c, NAU7802_Gain gain, NAU7802_SPS sps)
{
    /* 1. Reset all registers */
    if (!reg_write(hi2c, REG_PU_CTRL, PU_CTRL_RR)) return false;
    HAL_Delay(1);
    if (!reg_write(hi2c, REG_PU_CTRL, 0x00)) return false;

    /* 2. Power up digital */
    if (!reg_write(hi2c, REG_PU_CTRL, PU_CTRL_PUD)) return false;

    /* 3. Wait for PWRUP ready */
    uint32_t t = HAL_GetTick();
    uint8_t pu;
    do {
        if (!reg_read(hi2c, REG_PU_CTRL, &pu)) return false;
        if (HAL_GetTick() - t > 200) return false;
    } while (!(pu & PU_CTRL_PWRUP));

    /* 4. Power up analog */
    if (!reg_write(hi2c, REG_PU_CTRL, PU_CTRL_PUD | PU_CTRL_PUA)) return false;

    /* 5. Set gain (CTRL1 bits [2:0]) */
    if (!reg_write(hi2c, REG_CTRL1, (uint8_t)(gain & 0x07))) return false;

    /* 6. Set sample rate (CTRL2 bits [6:4]) */
    if (!reg_write(hi2c, REG_CTRL2, (uint8_t)((sps & 0x07) << 4))) return false;

    /* 7. Disable ADC chopper and PGA chopper (default-on, causes periodic noise bursts) */
    if (!reg_write(hi2c, REG_ADC, 0x30)) return false;
    if (!reg_write(hi2c, REG_PGA, 0x30)) return false;

    /* 8. Start conversions */
    if (!reg_write(hi2c, REG_PU_CTRL, PU_CTRL_PUD | PU_CTRL_PUA | PU_CTRL_CS)) return false;

    /* Discard a few initial samples */
    HAL_Delay(100);

    return true;
}

bool NAU7802_IsDataReady(I2C_HandleTypeDef *hi2c)
{
    uint8_t pu;
    if (!reg_read(hi2c, REG_PU_CTRL, &pu)) return false;
    return (pu & PU_CTRL_CR) != 0;
}

int32_t NAU7802_ReadRaw(I2C_HandleTypeDef *hi2c)
{
    uint8_t b[3];
    uint8_t reg = REG_ADCO_B2;

    if (HAL_I2C_Master_Transmit(hi2c, NAU7802_ADDR, &reg, 1, I2C_TIMEOUT) != HAL_OK)
        return 0;
    if (HAL_I2C_Master_Receive(hi2c, NAU7802_ADDR, b, 3, I2C_TIMEOUT) != HAL_OK)
        return 0;

    /* Assemble 24-bit two's complement and sign-extend to 32 bits */
    int32_t raw = ((int32_t)b[0] << 16) | ((int32_t)b[1] << 8) | b[2];
    if (raw & 0x800000)
        raw |= (int32_t)0xFF000000;

    return raw;
}

void NAU7802_Tare(I2C_HandleTypeDef *hi2c)
{
    /* Average a few readings at rest to establish zero */
    int32_t sum = 0;
    for (int i = 0; i < 32; i++) {
        uint32_t t = HAL_GetTick();
        while (!NAU7802_IsDataReady(hi2c)) {
            if (HAL_GetTick() - t > 200) break;
        }
        sum += NAU7802_ReadRaw(hi2c);
    }
    g_tare_offset = sum / 32;
}

int32_t NAU7802_ReadTared(I2C_HandleTypeDef *hi2c)
{
    return NAU7802_ReadRaw(hi2c) - g_tare_offset;
}
