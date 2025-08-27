/***************************************************************************
 * @file    CanIf.h
 * @brief   Provides APIs for initializes the MCAL CAN driver and sets up
 *          the CAN Interface layer.
 * @details This file declares functions for Receiving a CAN frame and 
 *          forward it to the upper layer.    
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/
#ifndef CANIF_H
#define CANIF_H

#include <stdio.h>
#include <stdint.h>

void CanIf_Init(void);
void CanIf_Receive(uint16_t canId, uint8_t* data, uint8_t dlc);
#endif /* CANIF_H */

