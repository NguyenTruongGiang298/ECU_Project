#ifndef CAN_TYPES_H
#define CAN_TYPES_H

#include <stdio.h>
#include <stdint.h>

/* an enum to indicate Pdu Router status */
typedef enum
{
    OK,
    NOT_OK,
    BUSY,
}Pdu_Status_t;


/* A struct definition to store payload from Can Interface */
typedef struct{
    uint8_t  *sdu_Data;
    uint32_t sdu_Length;
    uint16_t sdu_id;
}PduInfo_t;

typedef enum{
   PDU_ENGINE_SPEED =0x03,
   PDU_STOP_ENGINE  =0X04,
}PduCommand_t;

#endif