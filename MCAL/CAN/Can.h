/***************************************************************************
 * @file    Can.h
 * @brief   Declaration of functions and structures related to data 
 *          transmission and reception via the CAN protocol.
 * @details Provides APIs for initializing and reading CAN frames. 
 *          Simulates CAN frame transmission/reception using strings in a CSV file.   
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#ifndef CAN_H
#define CAN_H
#include <stdio.h>
#include <stdint.h>

#define MAX_DATA_BYTES 8

void Can_Init(void);
void Can_Receive(uint32_t* canId, uint8_t* data, uint8_t* dlc);



#endif