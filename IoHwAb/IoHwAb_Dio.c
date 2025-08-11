#include "IoHwAb_Dio.h"

/**
 * @fn IoHwAb_WriteDirection
 * 
 * @brief API to set direction for the motor in the Abstraction Layer
 * 
 * @param[in] uint8_t channelId , uint8_t duty
 * 
 * @return DATA_OK or DATA_ERROR
 * 
 */
iohwab_err_t IoHwAb_WriteDirection(uint8_t channelId, int direction)
{
    Dio_WriteChannel(channelId, direction);
    return DATA_OK;
};