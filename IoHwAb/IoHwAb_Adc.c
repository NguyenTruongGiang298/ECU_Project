/***************************************************************************
 * @file    IoHwAb_Adc.c
 * @brief   Provides APIs for abstracting ADC channel readings.
 * @details This file defines functions for reading ADC channels (Temperature,
 *          Current, Voltage, etc.) at the Abstraction Layer.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#include "IoHwAb_Adc.h"
#include "Adc.h"

/**
 * @fn IoHwAb_ReadTemp
 * @brief API to read Temperature(C) from MCU in Abstraction Layer
 * @param[in,out] uint16_t *temp_adc, float* temp_C
 * @return DATA_OK or DATA_ERROR
 * 
 */
iohwab_err_t IoHwAb_ReadTemp(uint16_t *temp_adc, float* temp_C)
{
    if(temp_adc == NULL || temp_C ==NULL)
    {
            printf("ERROR! - INVALID variable");
            return DATA_ERROR;
    }
   *temp_adc = Adc_ReadChannel("temp");
   *temp_C =  (*temp_adc) * MAX_TEMPERATURE / (ADC_12_BIT-1);
   return DATA_OK;
}

/**
 * @fn IoHwAb_ReadVoltage
 * @brief API to read Voltage(V) from MCU in Abstraction Layer
 * @param[in,out] uint16_t* voltage_adc, float* voltage_V
 * @return DATA_OK or DATA_ERROR
 * 
 */
iohwab_err_t IoHwAb_ReadVoltage(uint16_t* voltage_adc, float* voltage_V)
{
    if(voltage_adc == NULL || voltage_V ==NULL)
    {
            printf("ERROR! - INVALID variables");
            return DATA_ERROR;
    }
    *voltage_adc = Adc_ReadChannel("voltage");
    *voltage_V = (*voltage_adc) * MAX_VOLTAGE / (ADC_12_BIT - 1);
    return DATA_OK;
}

/**
 * @fn IoHwAb_ReadCurrent
 * @brief API to read Current(A) from MCU in Abstraction Layer
 * @param[in,out] uint16_t* current_adc, float* current_A
 * @return DATA_OK or DATA_ERROR
 * 
 */
iohwab_err_t IoHwAb_ReadCurrent(uint16_t* current_adc, float* current_A)
{
    if(current_adc == NULL || current_A ==NULL)
    {
            printf("ERROR! - INVALID variables");
            return DATA_ERROR;
    }
    *current_adc = Adc_ReadChannel("current");
    *current_A = (*current_adc) * MAX_CURRENT / (ADC_12_BIT - 1);
    return DATA_OK;
}

/**
 * @fn IoHwAb_ReadTorque
 * @brief API to read Torque(Nm) from MCU in Abstraction Layer
 * @param[in,out] uint16_t* torque_adc, float* torque_Nm
 * @return DATA_OK or DATA_ERROR
 * 
 */
iohwab_err_t IoHwAb_ReadTorque(uint16_t* torque_adc, float* torque_Nm)
{
    if(torque_adc == NULL || torque_Nm ==NULL)
    {
            printf("ERROR! - INVALID variables");
            return DATA_ERROR;
    }
    *torque_adc = Adc_ReadChannel("torque");
    *torque_Nm = (*torque_adc) * MAX_TORQUE / (ADC_12_BIT - 1);
    return DATA_OK;
}

/**
 * @fn IoHwAb_ReadRpm
 * @brief API to read RMP(V/m) from MCU in Abstraction Layer
 * @param[in,out] uint16_t*rmp
 * @return DATA_OK or DATA_ERROR
 * 
 */
iohwab_err_t IoHwAb_ReadRpm(uint16_t* rpm)
{
    if(rpm==NULL)
    {
            printf("ERROR! - INVALID variables");
            return DATA_ERROR;
    }
    *rpm = Adc_ReadChannel("rpm");
    return DATA_OK;
}

