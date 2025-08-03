#ifndef PWM_H
#define PWM_H
#include <stdio.h>
#include <error.h>
#include <stdint.h>
#include "csv_io.h"

#define PWM_CHANNEL_MAX 7
void Pwm_Init(void);
void Pwm_SetDutyCycle(uint8_t channelId, uint16_t duty);

#endif