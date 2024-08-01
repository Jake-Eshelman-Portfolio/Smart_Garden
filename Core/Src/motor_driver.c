/*
 * motor_driver.c
 *
 *  Created on: Aug 1, 2024
 *      Author: jakee
 */
/*
 * GPIO_PIN_0 = PA0
 * GPIO_PIN_1 = PA1
 *
 *
 *
 */
#include "motor_driver.h"
#include "stm32f4xx_hal.h"
#include "main.h"
#include <stdint.h>



// Global variables
extern TIM_HandleTypeDef htim9;  // Assuming TIM9 for PWM

void Motor_Init(void)
{
    HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_1);  // Start PWM on PE5
}

void Motor_SetSpeed(uint16_t speed)
{
    // Assuming 16-bit timer, adjust if different
    __HAL_TIM_SET_COMPARE(&htim9, TIM_CHANNEL_1, speed);
}

void Motor_Forward(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);    // IN1 High
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);  // IN2 Low
}

void Motor_Backward(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);  // IN1 Low
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);    // IN2 High
}

void Motor_Stop(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);  // IN1 Low
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);  // IN2 Low
}
