#include "lcd.h"
#include "i2c-lcd.h"
#include <stdio.h>

void LCD_Init(void)
{
    lcd_init();
}

void LCD_TampilkanNilai(uint16_t nilai)
{
    char teks[16];
    (void)sprintf(teks, "Moisture: %4u", nilai);
    lcd_send_cmd(0x80);
    lcd_send_string(teks);
}
