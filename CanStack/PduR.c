/***************************************************************************
 * @file    PduR.c
 * @brief   Definition of functions related to data 
 *          transmission and reception via the CAN protocol.
 * @details When a CAN frame is received. It validates the PDU data 
 *          and forwards it to the COM layer for further processing.  
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/
#include "PduR.h"
#include "Com.h"



/*****************************************************************************
 * @fn				- PduR_Init
 * @brief			- This function initialize a Pdu Router.
 * @param[in]		- void.
 * @return			- Non-return.
 */
void PduR_Init(void) {
    printf("[PduR] Init (1 entry)\n");
}

/**
 * @fn          - PduR_RouteReceive
 * @brief       - Route a received PDU from CanIf to the upper communication layer.
 * @param[in]   - PduInfo_t pdu   The received PDU structure containing:
 *                - sdu_id:     PDU (or CAN ID) identifier.
 *                - sdu_Data:   Pointer to the received data buffer.
 *                - sdu_Length: Length of the received data in bytes.
 * @return      - Pdu_Status_t
 *                - OK      : PDU was successfully routed to COM.
 *                - NOT_OK  : PDU routing failed (e.g., NULL data pointer).
 */
Pdu_Status_t PduR_RouteReceive(PduInfo_t pdu)
{
    if(pdu.sdu_Data == NULL) return NOT_OK;
    Com_Indication(pdu.sdu_id, pdu.sdu_Data, pdu.sdu_Length);
    return OK;
}   

 

