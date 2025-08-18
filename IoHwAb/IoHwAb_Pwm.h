/***************************************************************************
 * @file    IoHwAb_Pwm.h
 * @brief   Provides APIs for abstracting pulse width modulation control.
 * @details This file provides the interface for modifying PWM pulse width
 *          to control the motor at the Abstraction Layer.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#ifndef IOHWAB_PWM_H
#define IOHWAB_PWM_H

#include <stdio.h>
#include <stdint.h>

typedef enum
{
    DATA_OK,
    DATA_ERROR
}iohwab_err_t;

iohwab_err_t IoHwAb_SetDutyCycle(uint8_t channelId , uint8_t duty);
#endif