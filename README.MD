# Plant Watering System with nRF52dk and FreeRTOS

## Overview
This project automates the watering of plants using an STM32F429 Development Kit and FreeRTOS. 
It utilizes moisture sensors to monitor soil and controls a water pump to irrigate the plants when necessary. 
The skills I wanted to work on in this project are analog signal handling, learning FreeRTOS and STM microcontrollers, motor control, and power supply.

## Features
- Soil moisture monitoring
- Automated watering using a step-controlled motor
- FreeRTOS for task management and real-time operation
- Integration of ADC for sensor data acquisition

## Components
- STM32F429 Development Kit (https://www.digikey.com/en/products/detail/stmicroelectronics/STM32F429I-DISC1/5731713) 
- Capacitive soil moisture sensors -- https://www.tindie.com/products/miceuz/i2c-soil-moisture-sensor/, documentation: https://github.com/Miceuz/i2c-moisture-sensor/blob/master/README.md, also purchased 4 pin 90 degree header to attach
- Small water pump -- Gikfun 12V DC Dosing Pump Peristaltic (Amazon)
    - Tubing -- Gikfun 9.84 Ft 2mm x 4mm tubing (Amazon)
    - Power supply --  Kastar AC power adapter 12V 6A (Amazon)
      - Added in-line 2A fuse 
- L298N motor driver (Amazon)

## Schematic

## Software

### FreeRTOS Setup
[Instructions for setting up FreeRTOS on the nRF52dk]

### Dependencies


### Building and Flashing
- The project was built using STM32CubeMX with default settings for the board: STM32F429ZITx - STM32F429I-DISC1 except for ADC and I2C changes.
    - ADC 1 was enabled with mode IN5 added.
        - Input: PA5
    - I2C3 was added wil GPIO pullups configured. 
        - SCL: PA8 
        - SDA: PC9
    - TIM9 was configured with PWM generation on CH1 on pin PE5
        1. Calculating PWM Frequency: APB1 Frequency = (Desired PWM Frequency) * (Prescalar + 1) * (Auto reload register + 1)
            - 72,000,000 = 10,000 * (PSC + 1) * (ARR + 1)
                - PSC = 71 (For easy calculation),
                - ARR = 99 to give 10kHZ PWM frequency
        2. Duty Cycle = Counter Period / X
            - X = 50 -> 50% Duty Cycle
        3. Motor output GPIOS:
            - PC1, PC2 configured as:
                - output level: low, push pull, no pull-up/pull-down

- The project was built for STM32CubeIDE

### Usage


## Future Enhancements
- LED screen for displaying plant watering status
- IoT / mobile app component for managing plants while away
- Extension to handling multiple plants
- Custom PCB / Case

## External Documentation
- STM32F439 HAL user manual: https://www.disca.upv.es/aperles/arm_cortex_m3/llibre/st/STM32F439xx_User_Manual/group__gpio__exported__functions__group2.html







