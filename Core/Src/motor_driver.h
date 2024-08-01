/*
 * motor_driver.h
 *
 *  Created on: Aug 1, 2024
 *      Author: jakee
 */



#ifndef SRC_MOTOR_DRIVER_H_
#define SRC_MOTOR_DRIVER_H_

#include <stdint.h>

// Function prototypes
void Motor_Init(void);
void Motor_SetSpeed(uint16_t speed);
void Motor_Forward(void);
void Motor_Backward(void);
void Motor_Stop(void);



#endif /* SRC_MOTOR_DRIVER_H_ */
