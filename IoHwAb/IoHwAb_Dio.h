#ifndef IOHWAB_DIO_H
#define IOHWAB_DIO_H

#include <stdio.h>
#include <Dio.h>

typedef enum
{
    DATA_OK,
    DATA_ERROR
}iohwab_err_t;

iohwab_err_t IoHwAb_WriteDirection(uint8_t channelId, int direction);

#endif