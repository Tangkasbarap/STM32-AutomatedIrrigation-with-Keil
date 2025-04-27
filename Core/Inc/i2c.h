#ifndef __LCD_I2C_H
#define __LCD_I2C_H

#include "stm32f4xx_hal.h"

#define LCD_I2C_ADDRESS (0x27 << 1) // <<< Tambaahin INI

void LCD_I2C_Init(void);
void LCD_I2C_SendCommand(uint8_t cmd); // <<< Tambahin INI juga
void LCD_I2C_SendData(uint8_t data);
void LCD_I2C_Clear(void);
void LCD_I2C_SetCursor(uint8_t row, uint8_t col);
void LCD_I2C_PrintNumber(int num);
void LCD_I2C_Print(char *str);

#endif
