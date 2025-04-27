#include "sensor.h"
#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1; // Deklarasi handle ADC

void Sensor_Init(void) {
    // Inisialisasi ADC
    __HAL_RCC_ADC1_CLK_ENABLE(); // Aktifkan clock ADC1

    hadc1.Instance = ADC1;
    hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
    hadc1.Init.Resolution = ADC_RESOLUTION_12B;
    hadc1.Init.ScanConvMode = DISABLE;
    hadc1.Init.ContinuousConvMode = ENABLE;
    hadc1.Init.DiscontinuousConvMode = DISABLE;
    hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    hadc1.Init.NbrOfConversion = 1;
    HAL_ADC_Init(&hadc1);
}

int Sensor_Read(void) {
    HAL_ADC_Start(&hadc1); // Mulai konversi ADC
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY); // Tunggu konversi selesai
    return HAL_ADC_GetValue(&hadc1); // Kembalikan nilai ADC
}