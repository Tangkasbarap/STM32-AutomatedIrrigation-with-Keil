#include "pump.h"
#include "stm32f4xx_hal.h"

// Definisikan pin untuk pompa
#define PUMP_PIN GPIO_PIN_1
#define PUMP_PORT GPIOB

void Pump_Init(void) {
    // Inisialisasi GPIO untuk pompa
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitStruct.Pin = PUMP_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(PUMP_PORT, &GPIO_InitStruct);
}

void Pump_Start(void) {
    HAL_GPIO_WritePin(PUMP_PORT, PUMP_PIN, GPIO_PIN_SET); // Nyalakan pompa
}

void Pump_Stop(void) {
    HAL_GPIO_WritePin(PUMP_PORT, PUMP_PIN, GPIO_PIN_RESET); // Matikan pompa
}