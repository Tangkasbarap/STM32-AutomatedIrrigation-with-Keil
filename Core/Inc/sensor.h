#ifndef SENSOR_H_
#define SENSOR_H_

#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;

uint16_t Sensor_BacaKelembaban(void);

#endif /* SENSOR_H_ */
