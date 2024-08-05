/*
 * i2c_driver.h
 *
 *  Created on: Aug 4, 2024
 *      Author: jakee
 */

#ifndef INC_I2C_DRIVER_H_
#define INC_I2C_DRIVER_H_

#include "stm32f4xx_hal.h"

#define SENSOR_ADDRESS 0x20
#define TEMPERATURE_REGISTER 0x05
#define REGISTER_SIZE 0x02

extern I2C_HandleTypeDef hi2c3;

void MX_I2C3_Init(void);
void read_temperature();




#endif /* INC_I2C_DRIVER_H_ */
