#include "valve.h"
#include "stm32f4xx_hal.h"

// Definisikan pin untuk valve
#define VALVE_PIN GPIO_PIN_0
#define VALVE_PORT GPIOB

void Valve_Init(void) {
    // Inisialisasi GPIO untuk valve
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitStruct.Pin = VALVE_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(VALVE_PORT, &GPIO_InitStruct);
}

void Valve_Open(void) {
    HAL_GPIO_WritePin(VALVE_PORT, VALVE_PIN, GPIO_PIN_SET); // Buka valve
}

void Valve_Close(void) {
    HAL_GPIO_WritePin(VALVE_PORT, VALVE_PIN, GPIO_PIN_RESET); // Tutup valve
}