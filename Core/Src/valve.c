
#include "valve.h"
#include "stm32f4xx_hal.h"

#define VALVE_PIN GPIO_PIN_0
#define VALVE_PORT GPIOB

void Valve_Nyalakan(void)
{
    HAL_GPIO_WritePin(VALVE_PORT, VALVE_PIN, GPIO_PIN_SET);
}

void Valve_Matikan(void)
{
    HAL_GPIO_WritePin(VALVE_PORT, VALVE_PIN, GPIO_PIN_RESET);
}
