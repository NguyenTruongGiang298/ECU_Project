/***************************************************************************
 * @file    IoHwAb_Adc.h
 * @brief   Provides APIs for abstracting ADC channel readings.
 * @details This file provides the interface for reading ADC channels (Temperature,
 *          Current, Voltage, etc.) at the Abstraction Layer.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#ifndef IOHWAB_ADC_H
#define IOHWAB_ADC_H

#include <stdio.h>
#include <stdint.h>

#define ADC_12_BIT (1<<12)
#define MAX_TEMPERATURE 200.0
#define MAX_VOLTAGE 60.0   
#define MAX_CURRENT 50.0 
#define MAX_TORQUE 120 
#define VREF 5.0

typedef enum
{
    DATA_OK,
    DATA_ERROR
}iohwab_err_t;

iohwab_err_t IoHwAb_ReadTemp(uint16_t *temp_adc, float* temp_C);
iohwab_err_t IoHwAb_ReadVoltage(uint16_t* voltage_adc, float* voltage_V);
iohwab_err_t IoHwAb_ReadCurrent(uint16_t* current_adc, float* current_A);
iohwab_err_t IoHwAb_ReadTorque(uint16_t* torque_adc, float* torque_Nm);
iohwab_err_t  IoHwAb_ReadRpm(uint16_t* rpm);

#endif