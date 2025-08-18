/***************************************************************************
 * @file    Dio.h
 * @brief   Declaration of functions and structures related to digital 
 *          INPUT/OUTPUT signal control.
 * @details Provides APIs for initializing and writing values to control 
 *          motor rotation direction. Used to simulate digital signal control.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#ifndef DIO_H
#define DIO_H
#include <stdio.h>
#include <stdint.h>

#define COUNTER_CLOCK_WISE 0
#define CLOCK_WISE 1
#define DIO_CHANNEL_MAX    7

void Dio_Init(void);
void Dio_WriteChannel(uint8_t channelId, uint8_t level);


#endif