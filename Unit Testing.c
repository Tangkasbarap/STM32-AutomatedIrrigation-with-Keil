/* Unit Testing */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h> // buat sleep()

/* === Definisi Konstanta === */
#define SOIL_THRESHOLD 2000U
#define DELAY_CORRECTION_S 3 /* 3 detik (bukan ms) */

/* === Simulasi Fungsi Periferal === */
void LCD_I2C_SetCursor(uint8_t row, uint8_t col) {
    printf("[LCD] Cursor set ke Row:%d, Col:%d\n", row, col);
}

void LCD_I2C_Print(const char *text) {
    printf("[LCD] %s\n", text);
}

void LCD_I2C_PrintNumber(uint32_t num) {
    printf("[LCD] %lu\n", num);
}

void Pump_Start() {
    printf("[Pump] START ✅\n");
}

void Pump_Stop() {
    printf("[Pump] STOP ✅\n");
}

void Valve_Open() {
    printf("[Valve] OPEN ✅\n");
}

void Valve_Close() {
    printf("[Valve] CLOSE ✅\n");
}

/* === Simulasi Baca Sensor === */
uint32_t Sensor_Read() {
    uint32_t input_value;
    printf("\n>> Masukkan nilai simulasi soil sensor (0-4095): ");
    scanf("%u", &input_value);
    return input_value;
}

/* === Simulasi Water Control Process === */
void Water_Control_Process_Simulated() {
    uint32_t soil_value = Sensor_Read();

    LCD_I2C_SetCursor(0, 0);
    LCD_I2C_Print("Soil: ");
    LCD_I2C_PrintNumber(soil_value);

    if (soil_value < SOIL_THRESHOLD) {
        Pump_Start();
        LCD_I2C_SetCursor(1, 0);
        LCD_I2C_Print("Pump ON...");

        printf("[Delay] Menunggu %d detik untuk koreksi...\n", DELAY_CORRECTION_S);
        sleep(DELAY_CORRECTION_S);

        soil_value = Sensor_Read(); // Koreksi setelah penyiraman

        if (soil_value > (SOIL_THRESHOLD + 300U)) {
            Valve_Close();
            LCD_I2C_SetCursor(1, 0);
            LCD_I2C_Print("Valve CLOSED!");
        }

        Pump_Stop();
    }
    else {
        Pump_Start();
        Valve_Open();
        LCD_I2C_SetCursor(1, 0);
        LCD_I2C_Print("Soil OK        ");
    }
}

/* === Main Program === */
int main() {
    printf("===== SIMULASI WATER CONTROL TEST =====\n");

    int repeat = 1;
    while (repeat) {
        Water_Control_Process_Simulated();
        
        printf("\n>> Test lagi? (1=Yes, 0=No): ");
        scanf("%d", &repeat);
    }

    printf("===== SIMULASI SELESAI! =====\n");
    return 0;
}
