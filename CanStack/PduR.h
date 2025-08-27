/***************************************************************************
 * @file    PduR.h
 * @brief   Declaration of function and structures related to Pdu sector
 * @details Provides APIs for receving and transforming CAN frames from 
 *          Can driver to higher layer. 
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/
#include <stdio.h>
#include "PduTypes.h"


/**
 * @brief			- This function initialize a Pdu Router.
 */
void PduR_Init(void);

/**
 *  @brief  This function acts as the bridge between Pdu Router (PduR)
 *          and COM layer in AUTOSAR architecture.
 */
Pdu_Status_t PduR_RouteReceive(PduInfo_t pdu); 
