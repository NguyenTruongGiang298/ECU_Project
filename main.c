#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_io.h"
#include "Dio.h"
#include "Pwm.h"
#include "Adc.h"
#include "Can.h"

// can,0x3F0 8 03 8B 26 00 00 00 00 00
int main()
{
    Pwm_Init();
    Can_Init();
    Dio_Init();
    Adc_Init();
    uint32_t Canid;
    uint8_t data[8];
    uint8_t dlc;

    Dio_WriteChannel(0,1);
    uint16_t adc = Adc_ReadChannel(2);
    printf("ADC: %d\n",adc);
    Pwm_SetDutyCycle(0,125);
    Can_Receive(&Canid,data,&dlc);
    printf("Can: %x ",Canid);
    printf("%d ",dlc);
    for(int i=0;i<8;i++)
    {
        printf("%x ",data[i]);
    }
    return 0;
}