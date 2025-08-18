/***************************************************************************
 * @file    Can.c
 * @brief   Declaration of functions and structures related to data 
 *          transmission and reception via the CAN protocol.
 * @details Provides APIs definitions for initializing and reading CAN frames. 
 *          Simulates CAN frame transmission/reception using strings in a CSV file.   
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/
#include "Can.h"
#include "csv_io.h"

static int canInitialized = 0;

/*****************************************************************************
 * @fn				- Can_Init
 * @brief			- This function initialize a Can protocol.
 * @param[in]		- void.
 * @return			- Non-return.
 */
void Can_Init(void) 
{
    canInitialized=1;
    printf("[CAN] Initialized controller for CAN protocol\n");
}

/*****************************************************************************
 * @fn				    - Can_Receive
 * @brief			    - This function read a data frame from Can protocol.
 * @param[in][out]		- uint32_t* canId: The id of a device (7 bits address). 
 *                      - uint8_t* data: The data receive from Can network.
 *                      - uint8_t* dlc: the number of byte data.
 * @return			    - Non-return.
 */
void Can_Receive(uint32_t* canId, uint8_t* data, uint8_t* dlc)
{
    if (!canInitialized) {
        return;
    }
    char *frameStr = CSV_getString("can");
     if (!frameStr) {
        /* invalid string */
        return;
    }
    char *token = strtok(frameStr, " ");
    if (!token) {
        free(frameStr);
        return;
    }
    errno = 0;
    /* Canid */
    *canId = (uint32_t)strtoul(token, NULL, 0);
    if (errno != 0) {
        free(frameStr);
        return;
    }
   
    /* DLC */
    token = strtok(NULL," ");
    if (!token) {
        free(frameStr);
        return;
    }
    errno = 0;
    *dlc = (uint8_t)atoi(token);
    if (errno != 0 || *dlc > MAX_DATA_BYTES) {
        free(frameStr);
        return;
    }
    /* Data */
    for (uint8_t i = 0; i <*dlc; i++) {
        token = strtok(NULL, " ");
        if (!token) 
        {
            data[i]=0;
            continue;
        }
        errno = 0;
        unsigned long byteVal = strtoul(token, NULL, 16); //str , endptr, type(hex, dec, bin)
        if (errno != 0 || byteVal > 0xFF) {
            free(frameStr);
            return;
        }
        data[i] = (uint8_t)byteVal;
    }
    free(frameStr);
}




