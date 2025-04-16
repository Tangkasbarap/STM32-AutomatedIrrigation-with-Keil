#include "relay.h"
#include "stm32f4xx_hal.h"

#define RELAY_PIN GPIO_PIN_8
#define RELAY_PORT GPIOB

void Relay_Nyalakan(void)
{
    HAL_GPIO_WritePin(RELAY_PORT, RELAY_PIN, GPIO_PIN_SET);
}

void Relay_Matikan(void)
{
    HAL_GPIO_WritePin(RELAY_PORT, RELAY_PIN, GPIO_PIN_RESET);
}
