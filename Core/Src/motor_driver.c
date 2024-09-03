/*
 * motor_driver.c
 *
 *  Created on: Aug 1, 2024
 *      Author: jakee
 */
/*
 * GPIO_PIN_1 = PC1
 * GPIO_PIN_2 = PC2
 *
 *
 */
#include "motor_driver.h"
#include "stm32f4xx_hal.h"
#include "main.h"
#include <stdint.h>



// Global variables
extern TIM_HandleTypeDef htim9;  

void Motor_Init(void)
{
    // Start PWM on PE5
    HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_1);  
}

void Motor_SetSpeed(uint16_t speed)
{
    // 16-bit timer
    __HAL_TIM_SET_COMPARE(&htim9, TIM_CHANNEL_1, speed);
}

void Motor_Forward(void)
{
    HAL_GPIO_WritePin(Motor1_GPIO_Port, Motor1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Motor2_GPIO_Port, Motor2_Pin, GPIO_PIN_RESET);
}

void Motor_Backward(void)
{
    HAL_GPIO_WritePin(Motor1_GPIO_Port, Motor1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Motor2_GPIO_Port, Motor2_Pin, GPIO_PIN_SET);
}

void Motor_Stop(void)
{
    HAL_GPIO_WritePin(Motor1_GPIO_Port, Motor1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Motor2_GPIO_Port, Motor2_Pin, GPIO_PIN_RESET);
}