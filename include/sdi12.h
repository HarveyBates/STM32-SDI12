/*
 ******************************************************************************
 * @file           : sdi12.h
 * @brief          : SDI-12 library for STM32 microcontrollers.
 *            Built using a STM32L476RG and STM32L073RZ.
 ******************************************************************************
 * @attention
 *
 * !! SDI-12 uses 5 V logic, ensure your microcontrollers pins are 5 V
 * compatible !!
 *
 ******************************************************************************
 * @currently_supports
 *  - Acknowledge active (a!)
 *  - Send idenfification (aI!)
 *  - Change address (aAb!)
 *  - Start measurement (aM!)
 *  - Send data (aD0!)
 *  - Start verification (aV!)
 ******************************************************************************
 */

#ifndef SDI12_
#define SDI12_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"

#define MAX_RESPONSE_SIZE 75

/*
 * GPIO Pin, Port and UART for SDI12 functions.
 */
typedef struct {
    UART_HandleTypeDef *Huart;
    uint32_t Pin;
    GPIO_TypeDef *Port;
} SDI12_TypeDef;

/*
 * Measurement query response.
 * Query = aM!
 * Response = atttn where a = address, t = three numbers indication response
 * time (ttt) and the expected number of values (n)
 * Also used for verification response after an aV! command.
 */
typedef struct {
    char Address;
    uint16_t Time;
    uint8_t NumValues;
} SDI12_Measure_TypeDef;

void SDI12_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef SDI12_AckActive(const char addr);
void SDI12_DevicesOnBus(char *const devices);
HAL_StatusTypeDef SDI12_GetId(const char addr, char response[], uint8_t response_len);
HAL_StatusTypeDef SDI12_ChangeAddr(char *from_addr, char *to_addr);
HAL_StatusTypeDef SDI12_StartMeasurement(const char addr, SDI12_Measure_TypeDef *measure_info);
HAL_StatusTypeDef SDI12_SendData(const char addr, const SDI12_Measure_TypeDef *measurement_info, char *data);
HAL_StatusTypeDef SDI12_StartVerification(const char addr, SDI12_Measure_TypeDef *verification_info);
uint16_t SDI12_CheckCRC(char *response);
HAL_StatusTypeDef SDI12_StartMeasurementCRC(const char addr, SDI12_Measure_TypeDef *measurement_info);

#endif // SDI12_
