#include "dac.h"
#include "tim.h"
#include "dma.h"
#include "math.h"
#include "digitalToAnalog.h"


float analogVoltageOut[2];
float dacShift[2],dacFreq[2],dacVoltage[2];
enum waveType dacWaveType[2];
uint32_t temp[16] = {0,0,0,0,0,0,0,0,4000,4000,4000,4000,4000,4000,4000,4000};
uint32_t dacVal[128] = {0,0,0,0,0,0,0,0,4000,4000,4000,4000,4000,4000,4000,4000};

void fillValueDac(enum waveType wave){
	
	for(int i = 0 ; i <128 ; i++){
		double temp = i;
		switch (wave) {
			case sinusoidal:
				temp = temp/127; //scale to 1
				temp *= 6.283; //2pi
				temp = sin(temp);
				temp *= 2047;
				temp += 2047;
				dacVal[i] = round(temp);
				break;
			case rect:
				if (i > 63) dacVal[i] = 4095;
				else dacVal[i] = 0;
				break;
			case ramp:
				dacVal[i] = (i*4095)/127;
				break;
		}
	}
	
//	for(int i = 0 ; i <64 ; i++){
//		double temp = i;
//		switch (wave) {
//			case sinusoidal:
//				temp = temp/63; //scale to 1
//				temp *= 6.283; //2pi
//				temp = sin(temp);
//				temp *= 2048;
//				temp += 2048;
//				dacVal[i] = round(temp);
//				break;
//			case rect:
//				if (i > 31) dacVal[i] = 4095;
//				else dacVal[i] = 0;
//				break;
//			case ramp:
//				dacVal[i] = (i*4095)/63;
//				break;
//		}
//	}
//	
//	for(int i = 0 ; i <32 ; i++){
//		double temp = i;
//		switch (wave) {
//			case sinusoidal:
//				temp = temp/31; //scale to 1
//				temp *= 6.283; //2pi
//				temp = sin(temp);
//				temp *= 2048;
//				temp += 2048;
//				dacVal[i] = round(temp);
//				break;
//			case rect:
//				if (i > 15) dacVal[i] = 4096;
//				else dacVal[i] = 0;
//				break;
//			case ramp:
//				dacVal[i] = (i*4096)/31;
//				break;
//		}
//	}
//	
//	for(int i = 0 ; i <16 ; i++){
//		double temp = i;
//		switch (wave) {
//			case sinusoidal:
//				temp = temp/15; //scale to 1
//				temp *= 6.283; //2pi
//				temp = sin(temp);
//				temp *= 2048;
//				temp += 2048;
//				dacVal[i] = round(temp);
//				break;
//			case rect:
//				if (i > 7) dacVal[i] = 4095;
//				else dacVal[i] = 0;
//				break;
//			case ramp:
//				dacVal[i] = (i*4095)/15;
//				break;
//		}
//	}
}

void makeWaveDac(DAC_HandleTypeDef* hdac , uint32_t Channel , TIM_HandleTypeDef* htim , enum waveType wave, int frequency, int sampleNumber) {
	uint32_t period,systemFrequency = 72000000;
	if (frequency < 5000){
		htim->Instance->PSC = 1439;
		systemFrequency = 50000;
		period = systemFrequency / frequency;
		htim->Instance->ARR = period-1;
	}
	else {
		htim->Instance->PSC = 0;
		period = systemFrequency / frequency;
		htim->Instance->ARR = period-1;
	}
	

	HAL_TIM_Base_Start_IT(htim);
	
	fillValueDac(wave);
	
	//HAL_DAC_Start_DMA(hdac, Channel, dacVal , 16, DAC_ALIGN_12B_R);
	
	
	HAL_DAC_Start_DMA(hdac, Channel, dacVal , sampleNumber, DAC_ALIGN_12B_R);
	
}

void stopWaveDac(DAC_HandleTypeDef* hdac , uint32_t Channel , TIM_HandleTypeDef* htim) {
		HAL_TIM_Base_Stop(htim);
		HAL_DAC_Stop_DMA(hdac, Channel);
}

void setPwm(uint8_t pwmNumber,uint8_t percent){
			htim2.Instance->CCR1 =  percent;

}

void dacInit(float dacShiftTemp,float dacFreqTemp,float dacVoltageTemp,enum waveType dacWaveTypeTemp,uint8_t channel){
			dacShift[channel] = dacShiftTemp;
			dacFreq[channel] = dacFreqTemp;
			dacVoltage[channel] = dacVoltageTemp;
			dacWaveType[channel] = dacWaveTypeTemp;
}

void dacStop(uint8_t channel){
	if(channel == 0){
		;
	}
	else if(channel == 1){
		;
	}
}

void voltageOutInit(float voltageTemp ,uint8_t channel){
	analogVoltageOut[channel] = voltageTemp;
	//float voltageUnit = (float)voltageTemp;
	if (channel == 0){
		htim2.Instance->CCR1 =  50;
		htim2.Instance->CCR2 =  50;
	}
	else if(channel == 1){
		htim2.Instance->CCR3 =  50;
		htim2.Instance->CCR4 =  50;
	}
}

void voltageOutStop(uint8_t channel){
	if(channel == 0){
		htim2.Instance->CCR1 =  0;
		htim2.Instance->CCR2 =  0;
	}
	else if(channel == 1){
		htim2.Instance->CCR3 =  0;
		htim2.Instance->CCR4 =  0;
	}
}

