#ifndef H_digitalToAnalog_H
#define H_digitalToAnalog_H

#include "stm32f3xx_hal.h"

enum waveType{sinusoidal, rect, ramp};

void makeWaveDac(DAC_HandleTypeDef* hdac , uint32_t Channel , TIM_HandleTypeDef* htim  , enum waveType wave, int frequency, int sampleNumber);

void setPwm(uint8_t pwmNumber,uint8_t percent);

void voltageOutInit(float voltageTemp ,uint8_t channel);

void dacInit(float dacShiftTemp,float dacFreqTemp,float dacVoltageTemp,enum waveType dacWaveTypeTemp,uint8_t channel);

#endif 


