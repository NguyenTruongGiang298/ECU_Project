/***************************************************************************
 * @file    IoHwAb_Pwm.c
 * @brief   Provides APIs for abstracting pulse width modulation control.
 * @details This file contains the definitions of functions for modifying PWM
 *          pulse width to control the motor at the Abstraction Layer.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#include "IoHwAb_Pwm.h"
#include "Pwm.h"

/**
 * @fn IoHwAb_ReadRpm
 * @brief API to set Duty cycle for the motor in the Abstraction Layer
 * @param[in] uint8_t channelId , uint8_t duty
 * @return DATA_OK or DATA_ERROR
 * 
 */
iohwab_err_t IoHwAb_SetDutyCycle(uint8_t channelId , uint8_t duty)
{
    Pwm_SetDutyCycle(channelId,duty);
    return DATA_OK;
}