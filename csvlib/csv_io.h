/***************************************************************************
 * @file    csv_io.h
 * @brief   Declaration of functions and structures related to CSV file communication.
 * @details Provides APIs to read/write CSV files in key-value format, used by all
 *          MCAL modules.
 *          Enables access to or updates of simulated input/output data.
 * @version 1.0
 * @date    2025-08-18
 * author   Nguyen Truong Giang
 ***************************************************************************/

#ifndef CSV_IO_H
#define CSV_IO_H
#include <stdio.h>

#define ERROR -1
#define CSV_PATH    "C:/C_C++/C/ECU_Project/UI/Data.csv"
#define BUFFER_SIZE 512


int CSV_getInt(const char *key);
char* CSV_getString(const char *key);
void CSV_setInt(const char *key, int value);
#endif