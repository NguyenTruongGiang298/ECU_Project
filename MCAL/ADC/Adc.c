/***************************************************************************
 * @file    Adc.c
 * @brief   Khai báo các hàm và cấu trúc liên quan đến đọc giá trị ADC.
 * @details Cung cấp định nghĩa cho API đọc giá trị ADC từ các kênh khác nhau. 
 *          Mô phỏng đọc các tín hiệu analog từ cảm biến.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/
#include "adc.h"
#include "csv_io.h"

static int adcInitialized = 0;
static const char* ADC_KEY_NAMES[] = {
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