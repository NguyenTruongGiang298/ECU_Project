/***************************************************************************
 * @file    Pwm.h
 * @brief   Declaration of functions and structures related to PWM control.
 * @details Provides APIs for initializing and writing pulse widths. Used to 
 *          simulate speed changes (duty cycle) of a motor.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#ifndef PWM_H
#define PWM_H
#include <stdio.h>
#include <stdint.h>

#define PWM_CHANNEL_MAX 7
void Pwm_Init(void);
void Pwm_SetDutyCycle(uint8_t channelId, uint16_t duty);

#endif