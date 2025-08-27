/***************************************************************************
 * @file    Com.c
 * @brief  This file contains the implementation of the COM module, which
 *         acts as an AUTOSAR-like communication layer.
 * @details It provides APIs for initialization, reception indication, and
 *          decoding of application-level signals from PDUs received over CAN.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#include "Com.h"
#include "PduTypes.h"
#include <string.h>
#include "PduR.h"
#include "Canif.h"
#include <stdlib.h>

static struct
{
    uint16_t id;
    uint8_t data[8];
    uint8_t len;
}ENGINE_SPEED_Buffer;

static bool   st_stopRequested  = false;
static bool   st_speedReceived  = false;

/**
 * @fn      Com_Init
 * @brief   Initialize the COM module.
 * @param   None
 * @return  None
 */
void Com_Init(void) {
    /* Khởi CanIf và PduR ngay từ Com_Init */
    CanIf_Init();
    PduR_Init();
    printf("[Com] Initialized (calling CanIf_Init & PduR_Init)\n");
}


/**
 * @brief   Indication callback when a new CAN frame is received.
 * @param   uint16_t pduId   Identifier of the received PDU.
 *          uint8_t* data    Pointer to the received data payload.
 *          uint8_t dlc      Data Length Code (number of valid bytes).
 * @return  None
 * @details
 */
void Com_Indication(uint16_t pduId, uint8_t* data, uint8_t dlc) {
        memcpy(ENGINE_SPEED_Buffer.data, data, dlc);
        ENGINE_SPEED_Buffer.id = pduId;
        ENGINE_SPEED_Buffer.len = dlc;
}

/**
 * @fn              Com_ReceiveEngineSpeed
 * @brief           Decode engine-related commands from the reception buffer.
 * @param[in][out]  uint16_t rpm   Pointer to variable to store decoded engine speed (rpm).
 * @return          None
 */
void Com_ReceiveEngineSpeed(double* rpm)
{   
    if (ENGINE_SPEED_Buffer.data[0] == PDU_ENGINE_SPEED) 
    {
    uint16_t raw= ((uint16_t)ENGINE_SPEED_Buffer.data[2] << 8) | (uint16_t)ENGINE_SPEED_Buffer.data[1] ;
    double speed = raw / 100.0;
    *rpm  = speed;
    st_speedReceived = true;
    // Giả sử biến rpm là double*, raw là uint32_t
    printf("[Com] Decoded SetSpeed: raw=0x%03X (%.0f rpm) Speed=%.2f km/h\n", raw, *rpm, *rpm);
    }
    else if (ENGINE_SPEED_Buffer.id == PDU_STOP_ENGINE) {
        /* Lệnh StopEngine */
        st_stopRequested = true;
        printf("[Com] Decoded StopEngine: stopRequested = true\n");
    }
    else {
        printf("[Com] Unknown command: %u\n",ENGINE_SPEED_Buffer.id);
    }
}