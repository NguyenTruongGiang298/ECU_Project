#include "Dio.h"

static int dioInitialized = 0;

/*****************************************************************************
 * @fn				- Dio_Init
 * @brief			- This function initialize a digital Pin.
 * @param[in]		- void.
 * @return			- Non-return.
 */
void Dio_Init(void)
{
    dioInitialized=1;
    printf("[Digital IO] Initialize a Channel for DIO control\n");
}

/*****************************************************************************
 * @fn				- Dio_WriteChannel
 * @brief			- This function is used to set level for an output pin.
 * @param[in]		- uint8_t level: the level set in the pin (0 / 1). 
 *                  - uint8_t channelId: The channel to set output (0 - 7).
 * @return			- None.
 */
void Dio_WriteChannel(uint8_t channelId, uint8_t level)
{
    if (!dioInitialized) {
        return;
    }
    if(channelId <=DIO_CHANNEL_MAX)
    {
            if(level == CLOCK_WISE || level == COUNTER_CLOCK_WISE)
            {
                CSV_setInt("direction",level);
            }
            else{
                printf("ERROR - Invalid level for Digital IO\n");
            }
    }
    else{
        printf("ERROR - Invalid channel for Digital IO\n");
    }
} 