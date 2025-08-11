#include "IoHwAb_Pwm.h"

/**
 * @fn IoHwAb_ReadRpm
 * 
 * @brief API to set Duty cycle for the motor in the Abstraction Layer
 * 
 * @param[in] uint8_t channelId , uint8_t duty
 * 
 * @return DATA_OK or DATA_ERROR
 * 
 */
iohwab_err_t IoHwAb_SetDutyCycle(uint8_t channelId , uint8_t duty)
{
    Pwm_SetDutyCycle(channelId,duty);
    return DATA_OK;
}