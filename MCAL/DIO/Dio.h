#ifndef DIO_H
#define DIO_H
#include <stdio.h>
#include <error.h>
#include <stdint.h>
#include "csv_io.h"

#define COUNTER_CLOCK_WISE 0
#define CLOCK_WISE 1
#define DIO_CHANNEL_MAX    7

void Dio_Init(void);
void Dio_WriteChannel(uint8_t channelId, uint8_t level);


#endif