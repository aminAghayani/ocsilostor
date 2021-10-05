#ifndef H_measure_H
#define H_measure_H

#include "stm32f3xx_hal.h"
#include "adc.h"
#include "gpio.h"
#include "tim.h"

extern int adcMeasureReady; 
	
uint16_t connectionCheck(ADC_HandleTypeDef* hadc);

uint16_t resistorCheck(ADC_HandleTypeDef* hadc);

uint16_t capacitorCheck(ADC_HandleTypeDef* hadc);

uint16_t diodeCheck(ADC_HandleTypeDef* hadc);

uint16_t currentCheck(ADC_HandleTypeDef* hadc);

void capacitorInit(uint8_t channel);

void resistorInit(uint8_t channel);

#endif 


