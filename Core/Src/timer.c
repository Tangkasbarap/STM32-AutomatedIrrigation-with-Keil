#include "timer.h"
#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim2;

void Timer2_Init(void)
{
    HAL_TIM_Base_Start(&htim2);
}

void Delay_ms_with_TIM2(uint32_t delay)
{
    __HAL_TIM_SET_COUNTER(&htim2, 0U);
    while (__HAL_TIM_GET_COUNTER(&htim2) < delay) { }
}
