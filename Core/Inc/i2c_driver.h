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
#define BUSY_REGISTER 0x09
#define TEMPERATURE_READ_SIZE 0x02
#define CAPACITANCE_READ_SIZE 0x02
#define BUSY_DATA_SIZE 0x01
#define RESET_REGISTER 0x06
#define CAPACITANCE_REGISTER 0x00

extern I2C_HandleTypeDef hi2c3;

void MX_I2C3_Init(void);
void read_temperature(void);
void sensor_diagnostic(void);
void read_capacitance(void);




#endif /* INC_I2C_DRIVER_H_ */
