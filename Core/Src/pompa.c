
#include "pompa.h"
#include "stm32f4xx_hal.h"

#define POMPA_PIN GPIO_PIN_1
#define POMPA_PORT GPIOB

void Pompa_Nyalakan(void)
{
    HAL_GPIO_WritePin(POMPA_PORT, POMPA_PIN, GPIO_PIN_SET);
}

void Pompa_Matikan(void)
{
    HAL_GPIO_WritePin(POMPA_PORT, POMPA_PIN, GPIO_PIN_RESET);
}
