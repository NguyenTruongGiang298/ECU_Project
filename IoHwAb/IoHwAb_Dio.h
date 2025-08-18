/***************************************************************************
 * @file    IoHwAb_Dio.h
 * @brief   Provides APIs for abstracting I/O channel read/write operations.
 * @details This file provides the interface for controlling motor rotation direction
 *          at the Abstraction Layer.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#ifndef IOHWAB_DIO_H
#define IOHWAB_DIO_H

#include <stdio.h>
#include <stdint.h>

typedef enum
{
    DATA_OK,
    DATA_ERROR
}iohwab_err_t;

iohwab_err_t IoHwAb_WriteDirection(uint8_t channelId, int direction);

#endif