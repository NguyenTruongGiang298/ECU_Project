/***************************************************************************
 * @file    Com.h
 * @brief   This header file declares the public APIs, macros, and data
 *          structures of the COM module.
 * @details t provides an AUTOSAR-like abstraction for communication over
 *          CAN, using CanIf and PduR as lower layers.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief    initialization API for communication stack (Com_Init)
 * */ 
void Com_Init(void);

/**
 * @brief    Declare callback API for indication of received PDUs (Com_Indication)
 * */ 
void Com_Indication(uint16_t pduId, uint8_t* data, uint8_t dlc);

/**
 * @brief   Define API to extract application data
 *          such as Engine Speed or Stop Engine commands
 * */ 
void Com_ReceiveEngineSpeed(double* rpm);