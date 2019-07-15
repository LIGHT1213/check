#ifndef MAIN_H
#define MAIN_H
#include "stm32f4xx_hal.h"
#include "usart.h"
#include "stm32_hal_legacy.h"
#include "adc.h"
void UserMain(void);
void GetCommand(void);
void GetAndPrintADCValue(void);
#endif