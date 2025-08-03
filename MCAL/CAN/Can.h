#ifndef CAN_H
#define CAN_H
#include <stdio.h>
#include <stdint.h>
#include <error.h>
#include "csv_io.h"

#define MAX_DATA_BYTES 8

void Can_Init(void);
void Can_Receive(uint32_t* canId, uint8_t* data, uint8_t* dlc);



#endif