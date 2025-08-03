#include "adc.h"

static int adcInitialized = 0;
const char* const ADC_KEY_NAMES[] = {
    "temp",
    "voltage",
    "current",
    "torque",
    "rpm"
};

/*****************************************************************************
 * @fn				- Adc_Init
 * @brief			- This function initialize a ADC Channel.
 * @param[in]		- void.
 * @return			- Non-return.
 */
void Adc_Init(void)
{
    adcInitialized=1;
    printf("[ADC] Initialize a PWM Channel\n");
}


/*****************************************************************************
 * @fn				- Adc_ReadChannel
 * @brief			- This function retrieves an integer value.
 * @param[in]		- uint8_t channelId: The channel to get an Adc value (0 - 5).
 * @return			- The integer value associated with the channel or -1 for Error.
 */
uint16_t Adc_ReadChannel(uint8_t channelId)
{   
    if (!adcInitialized) {
        return -1;
    }
    if(channelId <= ADC_CHANNEL_MAX)
    {
        return (uint16_t)CSV_getInt(ADC_KEY_NAMES[channelId]);
    }
    else{
        printf("ERROR - Invalid ADC channel\n");
        return -1; 
    }  
}