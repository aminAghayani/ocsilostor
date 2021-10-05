#include "measure.h"

int theTemp = 0;
uint8_t connected = 0;
uint16_t value_adc,ADC_valConnection,ADC_valDiode,ADC_valResistor,ADC_valCapacitor,ADC_valCurrent;
uint16_t resistorRiseTime;
uint32_t capacitorRiseTime,arrayADC[5];
uint8_t resistorChannel,capacitorChannel;
unsigned int flagg;

void readADC(ADC_HandleTypeDef* hadc){
	HAL_ADC_Start_DMA(hadc, arrayADC, 5);
	flagg = DMA_FLAG_TC5;
	HAL_ADC_PollForConversion(&hadc3, 1);
	while(adcMeasureReady == 0)HAL_Delay(1);
	//HAL_Delay(1000);
	adcMeasureReady = 0;
	
}

uint16_t connectionCheck(ADC_HandleTypeDef* hadc){
	readADC(hadc);
	ADC_valConnection = arrayADC[0];
	if (ADC_valConnection > 3930 && ADC_valConnection< 4090){
		connected = 1;
	}
	else{
		connected = 0;
	}
	return ADC_valConnection;
}

uint16_t resistorCheck(ADC_HandleTypeDef* hadc){
	htim2.Instance->CNT = 0;
	HAL_TIM_Base_Start(&htim2);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
	ADC_valResistor = 0;
	while (ADC_valResistor <2020){
			readADC(hadc);
			ADC_valResistor = arrayADC[1];
			theTemp++;
			if(htim2.Instance->CNT > 6000){
					break;
				}
	}
	resistorRiseTime = htim2.Instance->CNT;
	HAL_TIM_Base_Stop(&htim2);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	return resistorRiseTime;
}

uint16_t capacitorCheck(ADC_HandleTypeDef* hadc){
	htim2.Instance->CNT = 0;
	HAL_TIM_Base_Start(&htim2);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
	ADC_valCapacitor = 0;
	while (ADC_valCapacitor <2550 || ADC_valCapacitor >4000){
			readADC(hadc);
			ADC_valCapacitor = 4040-arrayADC[2];
			theTemp++;
			if(htim2.Instance->CNT > 6000){
				break;
			}
	}
	capacitorRiseTime = htim2.Instance->CNT;
	HAL_TIM_Base_Stop(&htim2);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	return capacitorRiseTime;
}

uint16_t diodeCheck(ADC_HandleTypeDef* hadc){
	readADC(hadc);
	ADC_valDiode = arrayADC[3];
	return ADC_valDiode;
}

uint16_t currentCheck(ADC_HandleTypeDef* hadc){
	readADC(hadc);
	ADC_valCurrent = arrayADC[4];
	return ADC_valCurrent;
}

void capacitorInit(uint8_t channel){
	capacitorChannel = channel;
}

void resistorInit(uint8_t channel){
	resistorChannel = channel;
}
