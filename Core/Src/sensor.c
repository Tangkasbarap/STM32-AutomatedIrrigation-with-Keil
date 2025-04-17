
#include "sensor.h"
#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;

uint16_t Sensor_BacaKelembaban(void)
{
    uint16_t nilai = 0U;
    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, 100U) == HAL_OK)
    {
        nilai = HAL_ADC_GetValue(&hadc1);
    }
    HAL_ADC_Stop(&hadc1);
    return nilai;
}
