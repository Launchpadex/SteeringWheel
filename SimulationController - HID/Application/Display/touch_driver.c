#include "touch_driver.h"

void touchIOInit(void)
{
    RCC->AHB2ENR |= 1<<6 | 1<<4 | 1<<3; // GPIOG GPIOE GPIOD

    // SPI GPIO: PG2, PG3, PG4 → AF5
    GPIOG->MODER  &= ~(0b01<<(2*2) | 0b01<<(2*3) | 0b01<<(2*4));
    GPIOG->AFR[0] |=  5<<(4*2) | 5<<(4*3) | 5<<(4*4);
    GPIOG->OSPEEDR = 0xFFFFFFFF;

    // ~CS: PE1 output, default high (deselected)
    GPIOE->MODER &= ~(0b10<<2);
    GPIOE->ODR   |=  1<<1;

    // ~IRQ: PD6 input with pull-up
    GPIOD->MODER &= ~(0b11<<(2*6));
    GPIOD->PUPDR |=  0b01<<(2*6);
}

void touchSPIInit(void)
{
    SPI1->CR1 &= ~(1 | 1<<1);          // CPOL=0, CPHA=0
    SPI1->CR1 |=  1<<2;                 // Master
    SPI1->CR1 |=  0b101<<3;             // BR = fCLK/64
    SPI1->CR1 |=  1<<8 | 1<<9;         // SSM + SSI

    SPI1->CR2 |=  0b0111<<8;            // 8-bit data size
    SPI1->CR2 |=  1<<12;                // FRXTH: 8-bit FIFO threshold

    SPI1->CR1 |=  1<<6;                 // SPI enable
}

void touchInit(void)
{
    touchIOInit();
    touchSPIInit();
}

uint8_t SPI1_TransmitReceive(uint8_t dataToTransmit)
{
    while ((SPI1->SR & (1<<1)) == 0);               // Wait TX empty
    *((volatile uint8_t *)&SPI1->DR) = dataToTransmit;
    while ((SPI1->SR & (1<<0)) == 0);               // Wait RX not empty
    return *((volatile uint8_t *)&SPI1->DR);
}

void touchCSSelect(void)   { GPIOE->ODR &= ~(1<<1); }
void touchCSDeselect(void) { GPIOE->ODR |=  (1<<1); }

uint8_t touchCheckPressed(void)
{
    return ((GPIOD->IDR & (1<<6)) == 0);
}

uint16_t touchReadChannel(uint8_t channel, uint8_t conversionModeSD,
                           uint8_t conversionDataSize, uint8_t PDmode)
{
    uint8_t cmd = (1<<7) | (channel<<4) | (conversionDataSize<<3)
                | (conversionModeSD<<2) | PDmode;
    uint8_t temp[2];
    SPI1_TransmitReceive(cmd);
    temp[0] = SPI1_TransmitReceive(0x00);
    temp[1] = SPI1_TransmitReceive(0x00);
    return (uint16_t)(((uint16_t)temp[0] << 5) | (temp[1] >> 3));
}

uint16_t touchReadRawXPos(void)
{
    return touchReadChannel(TOUCH_X_CHANNEL_SELECT, TOUCH_CHANNEL_DIFFERENTIAL_MEAS,
                            TOUCH_12BIT_MODE, TOUCH_FULL_PD_IRQ);
}

uint16_t touchReadRawYPos(void)
{
    return touchReadChannel(TOUCH_Y_CHANNEL_SELECT, TOUCH_CHANNEL_DIFFERENTIAL_MEAS,
                            TOUCH_12BIT_MODE, TOUCH_FULL_PD_IRQ);
}

void touchReadRawXYPos(uint16_t *xPos, uint16_t *yPos)
{
    *xPos = touchReadRawXPos();
    *yPos = touchReadRawYPos();
}

void touchReadRawXYPosAvg(uint16_t *xPosAvg, uint16_t *yPosAvg, uint8_t numAvg)
{
    uint32_t xAcc = 0, yAcc = 0;
    uint16_t xTemp, yTemp;
    for (uint8_t i = 0; i < numAvg; i++) {
        touchReadRawXYPos(&xTemp, &yTemp);
        xAcc += xTemp;
        yAcc += yTemp;
    }
    *xPosAvg = xAcc / numAvg;
    *yPosAvg = yAcc / numAvg;
}

uint16_t touchScaleValue(uint16_t value, uint16_t max, uint16_t min, uint16_t range)
{
    if (value > max) value = max;
    if (value < min) value = min;
    return ((value - min) * range) / (max - min);
}

void touchReadXY(uint16_t *xPos, uint16_t *yPos)
{
    uint16_t xTemp, yTemp;
    touchReadRawXYPosAvg(&xTemp, &yTemp, 64);
    *xPos = touchScaleValue(xTemp, TOUCH_X_LIM_HI, TOUCH_X_LIM_LO, TOUCH_LCD_RESOLUTION_X);
    *yPos = TOUCH_LCD_RESOLUTION_Y
          - touchScaleValue(yTemp, TOUCH_Y_LIM_HI, TOUCH_Y_LIM_LO, TOUCH_LCD_RESOLUTION_Y);
}
