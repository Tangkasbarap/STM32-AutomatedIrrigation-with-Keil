#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx_hal.h" // ?? tambahkan baris ini

extern TIM_HandleTypeDef htim2;
void Timer2_Init(void);
void Delay_ms_with_TIM2(uint32_t delay);

#endif /* TIMER_H_ */
