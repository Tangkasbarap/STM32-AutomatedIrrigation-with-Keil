#ifndef LCD_I2C_H
#define LCD_I2C_H

#include "stm32f4xx_hal.h"

void LCD_I2C_Init(void);
void LCD_I2C_Display(int moistureLevel);
void LCD_I2C_Command(uint8_t cmd);
void LCD_I2C_Data(uint8_t data);

#endif // LCD_I2C_H