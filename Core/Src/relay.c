#include "relay.h"
#include "stm32f4xx_hal.h"

// Definisikan pin untuk relay
#define RELAY_PIN GPIO_PIN_2
#define RELAY_PORT GPIOB

void Relay_Init(void) {
    // Inisialisasi GPIO untuk relay
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitStruct.Pin = RELAY_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(RELAY_PORT, &GPIO_InitStruct);
}

void Relay_Activate(void) {
    HAL_GPIO_WritePin(RELAY_PORT, RELAY_PIN, GPIO_PIN_SET); // Aktifkan relay
}

void Relay_Deactivate(void) {
    HAL_GPIO_WritePin(RELAY_PORT, RELAY_PIN, GPIO_PIN_RESET); // Nonaktifkan relay
}