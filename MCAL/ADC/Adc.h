#ifndef ADC_H
#define ADC_H
#include <stdio.h>
#include <error.h>
#include <stdint.h>
#include "csv_io.h"

#define ADC_CHANNEL_MAX 5

void Adc_Init(void);
uint16_t Adc_ReadChannel(uint8_t channelId); 


#endif