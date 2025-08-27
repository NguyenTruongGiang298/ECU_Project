/***************************************************************************
 * @file    CanIf.c
 * @brief   Provides APIs for initializes the MCAL CAN driver and sets up
 *          the CAN Interface layer.
 * @details This file defines functions for Receiving a CAN frame and 
 *          forward it to the upper layer.    
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#include "Canif.h"
#include "PduTypes.h"
#include "PduR.h"
#include "Can.h"
#include <stdlib.h>
#include <string.h>

/**
 * @fn      CanIf_Init
 * @brief   Initialize the CAN Interface (CanIf) module.
 * @param   None
 * @return  None
 */
void CanIf_Init(void)
{
    /* Initializing MCAL CAN driver */
    Can_Init();
    printf("[CanIf] Initialized (filter IDs: 0x3F0)\n");
}

/**
 * @brief       Receive a CAN frame and forward it to the upper layer via PDU routing.
 * @param[in]   canId   CAN Identifier of the received frame.
 *              data    Pointer to the received CAN data payload (0–8 bytes for CAN Classic).
 *              dlc     Data Length Code (number of valid bytes in `data`).
 * @return      None
 */
void CanIf_Receive(uint16_t canId, uint8_t* data, uint8_t dlc)
{
    PduInfo_t info;
    info.sdu_id =canId;
    info.sdu_Length = dlc;
    info.sdu_Data = (uint8_t *)malloc(dlc);
    if (info.sdu_Data == NULL) {
        printf("Error! Memory allocation failed\n");
        return;
    }
    memcpy(info.sdu_Data,data,dlc);
    PduR_RouteReceive(info);
    free(info.sdu_Data);
}