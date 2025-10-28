#include "misko_touch.h"

void touchIOInit(){
  //Init Misko GPIO, AF and peripherals for touchscreen
  //RCC settings
  RCC->AHB2ENR |= 1<<6 | 1<<4 | 1<<3; //GPIOG GPIOE GPIOD
  RCC->APB2ENR |= 1<<12; //SPI1
  
  //GPIO for SPI
  GPIOG->MODER &= ~(0b01<<(2*2) |0b01<<(2*3) | 0b01<<(2*4)); //AF mode for PG2, PG3, PG4
  GPIOG->AFR[0] |= 5<<(4*2) | 5<<(4*3) | 5<<(4*4); //AF5 for PG2, PG3, PG4
  GPIOG->OSPEEDR |= 0xffffffff; //very fast mode for SPI GPIO
  
  //GPIO for ~CS
  GPIOE->MODER &= ~(0b10<<2); //GPIO output for ~CS on PE1
  GPIOE->ODR |= 1<<1; //~CS disabled by default
  
  //GPIO for ~IRQ
  GPIOD->MODER &= ~(0b11<<(2*6));//GPIO input for ~IRQ on PD6
  GPIOD->PUPDR |= 0b01<<(2*6); //pullup for ~IRQ
  
}

void touchSPIInit(){
  //SPI settings
  SPI1->CR1 &= ~(1 |1<<1); //CKPOL = low at idle, CKPHASE = 1. transition
  SPI1->CR1 |= 1<<2; //SPI MASTER
  SPI1->CR1 |= 0b101<<3; //BR = fCLK/128 = 1,312,500 Hz
  SPI1->CR1 |= (1<<8 | 1<<9); //SSM
  
  SPI1->CR2 |= 0b0111<<8; //8 bit word
  SPI1->CR2 |= 1<<12; //8 bit buffer
  
  SPI1->CR1 |= 1<<6; //SPI Enable
}

void touchInit(){
  touchIOInit(); //init Misko gpio and peripherals
  touchSPIInit(); //init SPI
}

uint8_t SPI1_TransmitReceive(uint8_t dataToTransmit){
  while((SPI1->SR & (1<<1)) == 0); //wait for transmit buffer empty flag
  *((volatile uint8_t *)&SPI1->DR) = dataToTransmit; //send data, make sure the processor updates the DR
  while((SPI1->SR & (1<<0)) == 0); // wait for receive buffer not empty flag
  uint8_t rez = *((volatile uint8_t *)&SPI1->DR); //read data, make sure the processor updates the DR
  return rez; //return read data
}

void touchCSSelect(){
  GPIOE->ODR &= ~(1<<1); //~CS low == enabled
}
void touchCSDeselect(){
  GPIOE->ODR |= 1<<1; //~CS high == disabled
}

uint8_t touchCheckPressed(){
  return ((GPIOD->IDR & (1<<6)) == 0); //check if IRQ was pulled low == touch detected
}

uint16_t touchReadChannel(uint8_t channel, uint8_t conversionModeSD, uint8_t conversionDataSize, uint8_t PDmode){
  //Construct SPI command byte :  START     Channel A012   Data size 12/8            Conversion dif/se       PD mode
  uint8_t read_channel_command = ((1<<7) | (channel<<4) | (conversionDataSize<<3) | (conversionModeSD<<2) | (PDmode<<0));
  uint8_t temp[] = {0, 0}; //temporary data array
  
  SPI1_TransmitReceive(read_channel_command); //Send channel read commnad
  temp[0] = SPI1_TransmitReceive(0x00); //Read 1st part of data
  temp[1] = SPI1_TransmitReceive(0x00); //Read 2nd part of data
  
  uint16_t ret = ((((uint16_t)(temp[0]))<<5) | ((uint16_t)temp[1]>>3)); //Shift data to correct position
  return ret;
}

uint16_t touchReadRawXPos(){
  //macro function for reading raw x position (voltage)
  return touchReadChannel(TOUCH_X_CHANNEL_SELECT, TOUCH_CHANNEL_DIFFERENTIAL_MEAS, TOUCH_12BIT_MODE, TOUCH_FULL_PD_IRQ);
}

uint16_t touchReadRawYPos(){
  //macro function for reading raw y position (voltage)
  return touchReadChannel(TOUCH_Y_CHANNEL_SELECT, TOUCH_CHANNEL_DIFFERENTIAL_MEAS, TOUCH_12BIT_MODE, TOUCH_FULL_PD_IRQ);
}

void touchReadRawXYPos(uint16_t * xPos, uint16_t * yPos){
  //macro function for reading raw x and y positions (voltage)
  *xPos = touchReadRawXPos();
  *yPos = touchReadRawYPos();
}

void touchReadRawXYPosAvg(uint16_t * xPosAvg, uint16_t * yPosAvg, uint8_t numAvg){
  //low pass filter (average) for reading raw x and y positions (voltage) 
  uint32_t xAcc = 0; //x data accumulator for average
  uint32_t yAcc = 0; //y data accumulator for average
  uint16_t xTemp = 0; //x data temporary variable
  uint16_t yTemp = 0; //y data temporary variable
  for(uint8_t i = 0; i < numAvg; i++){ //accumulate data for numAvg samples
    touchReadRawXYPos(&xTemp, &yTemp); //acquire current data
    xAcc += xTemp; //Accummulate x
    yAcc += yTemp; //accummulate y
  }
  *xPosAvg = xAcc/numAvg; //calculate average x data
  *yPosAvg = yAcc/numAvg; //Calculate average y data
}

uint16_t touchScaleValue(uint16_t value, uint16_t max, uint16_t min, uint16_t range){
  //Clamp value between min and max 
  if(value > max) value = max;
  if(value < min) value = min;
  
  uint16_t ret = ((value - min)* range)/(max - min); //calculate pixel coordinates(scale from voltage to pixel coords)
  return ret;
}

void touchReadXY(uint16_t * xPos, uint16_t * yPos){
  //macro function to read scaled and averaged x and y pos (in screen space) (LIM_HI and LIM_LO experimentally chosen, calibrate for better precision)
  uint16_t xTemp = 0;
  uint16_t yTemp = 0;
  touchReadRawXYPosAvg(&xTemp, &yTemp, 64);
  *xPos = touchScaleValue(xTemp, TOUCH_X_LIM_HI, TOUCH_X_LIM_LO, TOUCH_LCD_RESOLUTION_X);
  *yPos = TOUCH_LCD_RESOLUTION_Y - touchScaleValue(yTemp, TOUCH_Y_LIM_HI, TOUCH_Y_LIM_LO, TOUCH_LCD_RESOLUTION_Y); // Flip y
}
