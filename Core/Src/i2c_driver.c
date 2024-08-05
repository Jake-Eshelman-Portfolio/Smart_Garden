/*
 * motor_driver.c
 *
 *  Created on: Aug 1, 2024
 *      Author: jakee
 */
/*
#define G6_GPIO_Port GPIOC
#define I2C3_SDA_Pin GPIO_PIN_9
#define I2C3_SDA_GPIO_Port GPIOC
#define I2C3_SCL_Pin GPIO_PIN_8
 *
 */
#include "i2c_driver.h"
#include "stm32f4xx_hal.h"
#include "main.h"
#include <stdio.h>
#include <stdint.h>

I2C_HandleTypeDef hi2c3;


/**
  * @brief I2C3 Initialization Function
  * @param None
  * @retval None
  */
void MX_I2C3_Init(void)
{

  /* USER CODE BEGIN I2C3_Init 0 */

  /* USER CODE END I2C3_Init 0 */

  /* USER CODE BEGIN I2C3_Init 1 */

  /* USER CODE END I2C3_Init 1 */
  hi2c3.Instance = I2C3;
  hi2c3.Init.ClockSpeed = 100000;
  hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c3, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c3, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C3_Init 2 */

  /* USER CODE END I2C3_Init 2 */

}

/**
  * @brief Function to read the temperature from the sensor
  * @param None
  * @retval None
  */

void read_temperature()
{
	uint8_t data[2];

	HAL_StatusTypeDef status;
	status = HAL_I2C_Mem_Read(&hi2c3, SENSOR_ADDRESS << 1, TEMPERATURE_REGISTER, REGISTER_SIZE, data, REGISTER_SIZE, HAL_MAX_DELAY);

	if (status == HAL_OK)
	{
		uint16_t combined_temperature = data[0] << 8 | data[1];
		printf("Temperature read successfully from sensor: %d \n", combined_temperature);
	}
	else
	{
		printf("Temperature failed with status: %d \n", status);
	}

}










































