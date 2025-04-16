
#include "sensor.h"
#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;

uint16_t Sensor_BacaKelembaban(void)
{
    uint16_t nilai = 0U;

    (void)HAL_ADC_Start(&hadc1);
    (void)HAL_ADC_PollForConversion(&hadc1, 10U);
    nilai = (uint16_t)HAL_ADC_GetValue(&hadc1);
    (void)HAL_ADC_Stop(&hadc1);

    return nilai;
}
