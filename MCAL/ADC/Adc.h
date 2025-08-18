/***************************************************************************
 * @file    Adc.h
 * @brief   Khai báo các hàm và cấu trúc liên quan đến đọc giá trị ADC.
 * @details Cung cấp API đọc giá trị ADC từ các kênh khác nhau. Mô phỏng
 *          đọc các tín hiệu analog từ cảm biến.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/
#ifndef ADC_H
#define ADC_H
#include <stdio.h>
#include <stdint.h>

#define ADC_CHANNEL_MAX 5

void Adc_Init(void);
uint16_t Adc_ReadChannel(uint8_t channelId); 


#endif