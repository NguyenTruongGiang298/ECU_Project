#include "Pwm.h"
 
static uint8_t pwmInitialized=0;

/*****************************************************************************
 * @fn				- Pwm_Init
 * @brief			- This function initialize a PWM Channel.
 * @param[in]		- void.
 * @return			- Non-return.
 */
void Pwm_Init(void)
{
    pwmInitialized=1;
     printf("[PWM] Initialize a PWM Channel\n");
}

/*****************************************************************************
 * @fn				- Pwm_SetDutyCycle
 * @brief			- This function is used to control pulse output.
 * @param[in]		- uint16_t duty: The value to set into the channel. 
 *                  - uint8_t channelId: The channel to set a PWM pulse (0 - 7).
 * @return			- None.
 */
void Pwm_SetDutyCycle(uint8_t channelId, uint16_t duty)
{
    if (!pwmInitialized) {
        return;
    }
    if(channelId <PWM_CHANNEL_MAX)
    {
        CSV_setInt("duty",duty);
    }
    else{
         printf("ERROR - Invalid PWM channel\n");
    }  
}