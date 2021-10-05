
#include "main.h"
#include "analogToDigital.h"

uint32_t adcAnalogInput[2];
int interrupted = 0,called = 0;

//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
//{
//		interrupted++;
    // Read & Update The ADC Result
    //AD_RES = HAL_ADC_GetValue(&hadc1);
//}

void startAdcInput(){
			HAL_ADC_Start_DMA(&hadc1, adcAnalogInput, 2);
}
