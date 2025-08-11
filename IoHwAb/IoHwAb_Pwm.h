#ifndef IOHWAB_PWM_H
#define IOHWAB_PWM_H

#include <stdio.h>
#include "Pwm.h"

typedef enum
{
    DATA_OK,
    DATA_ERROR
}iohwab_err_t;

iohwab_err_t IoHwAb_SetDutyCycle(uint8_t channelId , uint8_t duty);
#endif