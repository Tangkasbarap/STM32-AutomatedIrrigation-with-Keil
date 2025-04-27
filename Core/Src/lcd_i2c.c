#include "lcd_i2c.h"
#include "i2c.h"
#include <string.h>
#include <stdio.h>
extern I2C_HandleTypeDef hi2c1;

#define LCD_BACKLIGHT 0x08
#define ENABLE_BIT    0x04

static void LCD_I2C_Write(uint8_t data);
static void LCD_I2C_SendInternal(uint8_t data, uint8_t flags);

void LCD_I2C_Init(void) {
    HAL_Delay(50);
    LCD_I2C_SendInternal(0x30, 0);
    HAL_Delay(5);
    LCD_I2C_SendInternal(0x30, 0);
    HAL_Delay(1);
    LCD_I2C_SendInternal(0x30, 0);
    LCD_I2C_SendInternal(0x20, 0); // 4-bit mode

    LCD_I2C_SendCommand(0x28); // 2 lines
    LCD_I2C_SendCommand(0x08); // Display OFF
    LCD_I2C_SendCommand(0x01); // Clear
    HAL_Delay(2);
    LCD_I2C_SendCommand(0x06); // Entry mode set
    LCD_I2C_SendCommand(0x0C); // Display ON
}

void LCD_I2C_SendCommand(uint8_t cmd) {
    LCD_I2C_SendInternal(cmd & 0xF0, 0);
    LCD_I2C_SendInternal((cmd << 4) & 0xF0, 0);
}

void LCD_I2C_SendData(uint8_t data) {
    LCD_I2C_SendInternal(data & 0xF0, 1);
    LCD_I2C_SendInternal((data << 4) & 0xF0, 1);
}

void LCD_I2C_Clear(void) {
    LCD_I2C_SendCommand(0x01);
    HAL_Delay(2);
}

void LCD_I2C_SetCursor(uint8_t row, uint8_t col) {
    uint8_t address = (row == 0) ? 0x80 + col : 0xC0 + col;
    LCD_I2C_SendCommand(address);
}

void LCD_I2C_Print(char *str) {
    while (*str) {
        LCD_I2C_SendData((uint8_t)(*str));
        str++;
    }
}

void LCD_I2C_PrintNumber(int num) {
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d", num);
    LCD_I2C_Print(buffer);
}

// ===== INTERNAL FUNCTIONS =====

static void LCD_I2C_SendInternal(uint8_t data, uint8_t flags) {
    uint8_t up = data | LCD_BACKLIGHT | flags;
    uint8_t lo = (data | ENABLE_BIT | LCD_BACKLIGHT | flags);

    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDRESS, &lo, 1, 10);
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDRESS, &up, 1, 10);
}

static void LCD_I2C_Write(uint8_t data) {
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDRESS, &data, 1, 10);
}
