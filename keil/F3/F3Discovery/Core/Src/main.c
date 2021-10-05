/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "measure.h"
#include "digitalToAnalog.h"
#include "analogToDigital.h"
#include "usbd_cdc_if.h"
#include "math.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define ESP_uart huart4
uint8_t blink = 0;
uint32_t byte[4];
uint32_t tempAshk = 100;
int blinkNum=0,newTest = 0,tempADC1 = 0,tempADC2 = 0,stopMode,test1=0,test2=0,lastTemp=0;
int packetNumberWifi=0,packetNumberUsb=0,wifiDataLength=0,usbDataLength=0; //transmit vars
int writingSendDataIndex = 0,readingSendDataIndex = 0;
struct SendData sendData[2];
char wifiData[30],wifiChar;
enum ConnectionState{usb, wifi, notConnected};
enum ConnectionState connectionState = notConnected;
enum DataMode{noData,analog,digital,connection,resistor,capacitor,diode,current,dac,voltageOut};
enum DataMode dataMode = noData;
int ADTime,ADPacketPerSend;
int adcMeasureReady = 0 , adcAnalogReady = 0; 

///analog vars
int analogFreq[4];
int analogSamples[4],analogSampleFreq[4],analogSampleFreqMax[2];
int analogBytes[4],analogBytesMax[2];
int analogDataReadyCh1=0,analogDataReadyCh2=0,analogDataNumberADC1=0,analogDataNumberADC2=0,analogOddNumberADC1=0,analogOddNumberADC2=0;
uint32_t analogByteADC1[1001],analogByteADC2[1001];
				
///digital vars
int digitalFreq[4],digitalFreqMax,digitalBytes[4],digitalBytesMax;
int digitalDataReady = 0;
uint8_t digitalByteCH1[1001],digitalByteCH2[1001],digitalByteCH3[1001],digitalByteCH4[1001];
int digitalIndex = 0;

//uint32_t temp[2] = {4095,0};

//
//led blink
void ledBlink(){
	if (blink == 0){
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11|GPIO_PIN_15, GPIO_PIN_RESET);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_12);
	}
	if (blink == 1){
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_12);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
	}
	if (blink == 2){
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_10);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
	}
	if (blink == 3){
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_10);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11);
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_15);
		blink = -1;
	}
	
	blink++;
}
//
//calculate analog and digital number of bytes per packet to be sent
void calcAnalogSampleFreq(){
	for (int i=0 ; i<4 ; i++){
		if (connectionState == usb){
			if(analogFreq[i] > 2500 && analogFreq[i] < 20001){
				analogSamples[i] = 10;
			}
			if(analogFreq[i] > 1000 && analogFreq[i] < 2501){
				analogSamples[i] = 20;
			}
			if(analogFreq[i] > 250 && analogFreq[i] < 1001){
				analogSamples[i] = 40;
			}
			if(analogFreq[i] < 251){
				analogSamples[i] = 200;
			}
			analogSampleFreq[i] = analogSamples[i]*analogFreq[i];
			analogBytes[i] = analogSampleFreq[i]/200;
			analogSampleFreq[i] = analogBytes[i]*200;
		}
		if (connectionState == wifi){
			if(analogFreq[i] > 25 && analogFreq[i] < 201){
				analogSamples[i] = 10;
			}
			if(analogFreq[i] < 26){
				analogSamples[i] = 20;
			}
			analogSampleFreq[i] = analogSamples[i]*analogFreq[i];
			analogBytes[i] = analogSampleFreq[i]/20;
			analogSampleFreq[i] = analogBytes[i]*20;
		}
	}
}	
//
//set analog and digital timer event time
void setADtimer(TIM_HandleTypeDef *htim,int freq){
	uint32_t period,systemFrequency = 72000000;
	if (freq < 5000){
		htim->Instance->PSC = 1439;
		systemFrequency = 50000;
		period = systemFrequency / freq;
		htim->Instance->ARR = period-1;
	}
	else {
		htim->Instance->PSC = 0;
		period = systemFrequency / freq;
		htim->Instance->ARR = period-1;
	}
}
//
//usb and wifi transmit and led blink
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim == &htim1) {
		
		if (blinkNum > 99){
				ledBlink();	
				blinkNum = 0;
		}
		blinkNum++;
		
		
		///usb send
		if (connectionState == usb && sendData[readingSendDataIndex].readySend == 1){
				sendData[readingSendDataIndex].bytes[1] = packetNumberUsb+'0';
				CDC_Transmit_FS(sendData[readingSendDataIndex].bytes , sendData[readingSendDataIndex].length);
				packetNumberUsb++;
				packetNumberUsb = packetNumberUsb%10;
				sendData[readingSendDataIndex].readySend = 0;
				readingSendDataIndex++;
				readingSendDataIndex %= 2;
		}
		///wifi send
		if (blinkNum%10 == 0){
			if (connectionState == wifi && sendData[readingSendDataIndex].readySend == 1){
				sendData[readingSendDataIndex].bytes[1] = packetNumberWifi+'0';
				HAL_UART_Transmit_IT(&huart4,sendData[readingSendDataIndex].bytes , sendData[readingSendDataIndex].length);
				packetNumberWifi++;
				packetNumberWifi = packetNumberWifi%10;
				sendData[readingSendDataIndex].readySend = 0;
				readingSendDataIndex++;
				readingSendDataIndex %= 2;
			}
		}
	}
	if (htim == &htim8) {
		if(digitalDataReady == 0){
			digitalByteCH1[digitalIndex] = HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_2);
			digitalByteCH2[digitalIndex] = HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3);
			digitalByteCH3[digitalIndex] = HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4);
			digitalByteCH4[digitalIndex] = HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_5);
			digitalIndex++;
			if(digitalIndex == digitalBytesMax){
				digitalIndex = 0;
				digitalDataReady = 1;
			}
		}
		newTest++;
	}
	if (htim == &htim3) {
		lastTemp++;
	}
}


//
//incoming data handle
void handleIncomingData(char *data , uint32_t len , enum DataMode mode){
	
	switch(mode){
		case noData : {
			stopMode = data[2];
			if(stopMode == 1){ 	///voltage out1
				voltageOutStop(0);
			}
			else if(stopMode == 2){ ///voltage out2
				voltageOutStop(1);
			}
			else if(stopMode == 3){ ///dac out1
				dacStop(0);
			}
			else if(stopMode == 4){///dac out2
				dacStop(1);
			}
			else if(stopMode == 5){ ///analog
				HAL_TIM_Base_Stop_IT(&htim6);
				HAL_TIM_Base_Stop_IT(&htim8);
				analogDataReadyCh1=0;
				analogDataReadyCh2=0;
				analogDataNumberADC1=0;
				analogDataNumberADC2=0;
			}
			else if(stopMode == 6){ ///digital
				HAL_TIM_Base_Stop_IT(&htim8);
				digitalDataReady = 0;
				digitalIndex = 0;
			}
			writingSendDataIndex=0;
			readingSendDataIndex=0;
			sendData[0].readySend=0;
			sendData[1].readySend=0;
			dataMode = noData;
			break;
		}
		case analog : {
			union Convert convert;
			
			convert.char_temp[0] = data[2];
			convert.char_temp[1] = data[3];
			convert.char_temp[2] = data[4];
			convert.char_temp[3] = data[5];
			analogFreq[0] = convert.integer4_temp;
			
			convert.char_temp[0] = data[6];
			convert.char_temp[1] = data[7];
			convert.char_temp[2] = data[8];
			convert.char_temp[3] = data[9];
			analogFreq[1] = convert.integer4_temp;
			
			convert.char_temp[0] = data[10];
			convert.char_temp[1] = data[11];
			convert.char_temp[2] = data[12];
			convert.char_temp[3] = data[13];
			analogFreq[2] = convert.integer4_temp;
			
			convert.char_temp[0] = data[14];
			convert.char_temp[1] = data[15];
			convert.char_temp[2] = data[16];
			convert.char_temp[3] = data[17];
			analogFreq[3] = convert.integer4_temp;
			
			///calculate appropriate sample and frequencies*samples that is timer trigger freq
			calcAnalogSampleFreq();
			
			if(analogSampleFreq[0] > analogSampleFreq[1]){
				analogSampleFreqMax[0] = analogSampleFreq[0];
				analogBytesMax[0] = analogBytes[0];
			}
			else{
				analogSampleFreqMax[0] = analogSampleFreq[1];
				analogBytesMax[0] = analogBytes[1];
			}
			
			if(analogSampleFreq[2] > analogSampleFreq[3]){
				analogSampleFreqMax[1] = analogSampleFreq[2];
				analogBytesMax[1] = analogBytes[2];
			}
			else{
				analogSampleFreqMax[1] = analogSampleFreq[3];
				analogBytesMax[1] = analogBytes[3];
			}
			
			setADtimer(&htim8,analogSampleFreqMax[0]);
			setADtimer(&htim6,analogSampleFreqMax[1]);
			
			HAL_TIM_Base_Start(&htim8);
			HAL_TIM_Base_Start(&htim6);
			
			if(analogBytesMax[0]%2 == 0){
					HAL_ADC_Start_DMA(&hadc1, analogByteADC1, analogBytesMax[0]);
			}
			else if(analogBytesMax[0]%2 == 1){
				if(analogOddNumberADC1%2 == 0)
					HAL_ADC_Start_DMA(&hadc1, analogByteADC1, analogBytesMax[0]+1);
				else
					HAL_ADC_Start_DMA(&hadc1, analogByteADC1, analogBytesMax[0]-1);
			analogOddNumberADC1++;
			analogOddNumberADC1%=2;
			}
			
			if(analogBytesMax[1]%2 == 0){
					HAL_ADC_Start_DMA(&hadc2, analogByteADC2, analogBytesMax[1]);
			}
			else if(analogBytesMax[1]%2 == 1){
				if(analogOddNumberADC2%2 == 0)
					HAL_ADC_Start_DMA(&hadc2, analogByteADC2, analogBytesMax[1]+1);
				else
					HAL_ADC_Start_DMA(&hadc2, analogByteADC2, analogBytesMax[1]-1);
			analogOddNumberADC2++;
			analogOddNumberADC2%=2;
			}
			
			dataMode = analog;
			break;
		}
		case digital : {
			union Convert convert;
			
			convert.char_temp[0] = data[2];
			convert.char_temp[1] = data[3];
			convert.char_temp[2] = data[4];
			convert.char_temp[3] = data[5];
			digitalFreq[0] = convert.integer4_temp;
			
			convert.char_temp[0] = data[6];
			convert.char_temp[1] = data[7];
			convert.char_temp[2] = data[8];
			convert.char_temp[3] = data[9];
			digitalFreq[1] = convert.integer4_temp;
			
			convert.char_temp[0] = data[10];
			convert.char_temp[1] = data[11];
			convert.char_temp[2] = data[12];
			convert.char_temp[3] = data[13];
			digitalFreq[2] = convert.integer4_temp;
			
			convert.char_temp[0] = data[14];
			convert.char_temp[1] = data[15];
			convert.char_temp[2] = data[16];
			convert.char_temp[3] = data[17];
			digitalFreq[3] = convert.integer4_temp;
			
			///Find max freq digital and bytes and round freq
			digitalFreqMax = 0;
			for (int i=0 ; i < 4 ; i++){
				if (connectionState == wifi){
					digitalBytes[i] = digitalFreq[i]/10;
					digitalFreq[i] = digitalBytes[i]*10;
				}
				else if(connectionState == usb){
					digitalBytes[i] = digitalFreq[i]/100;
					digitalFreq[i] = digitalBytes[i]*100;
				}
				if (digitalFreqMax < digitalFreq[i]){
					digitalFreqMax = digitalFreq[i];
					digitalBytesMax = digitalBytes[i];
				}
			}
			
			setADtimer(&htim8,digitalFreqMax);
			
			HAL_TIM_Base_Start_IT(&htim8);
			
			dataMode = digital;
			break;
		}
		case connection : {
			dataMode = connection;
			break;
		}
		case resistor : {
			dataMode = resistor;
			uint8_t channel = data[2];
			resistorInit(channel);
			break;
		}
		case capacitor : {
			uint8_t channel = data[2];
			capacitorInit(channel);
			dataMode = capacitor;
			break;
		}
		case diode : {
			dataMode = diode;
			break;
		}
		case current : {
			dataMode = current;
			break;
		}
		case dac : {
			uint8_t channel = data[2];
			uint8_t waveType = data[3];
			float freq,pp_voltage,shift;
			
			union Convert convert;
			
			convert.char_temp[0] = data[4];
			convert.char_temp[1] = data[5];
			convert.char_temp[2] = data[6];
			convert.char_temp[3] = data[7];
			pp_voltage = convert.float_temp;
			
			convert.char_temp[0] = data[8];
			convert.char_temp[1] = data[9];
			convert.char_temp[2] = data[10];
			convert.char_temp[3] = data[11];
			shift = convert.float_temp;
			
			convert.char_temp[0] = data[12];
			convert.char_temp[1] = data[13];
			convert.char_temp[2] = data[14];
			convert.char_temp[3] = data[15];
			freq = convert.float_temp;
			
			dacInit(shift,freq,pp_voltage,waveType,channel);
			
			break;
		}
		case voltageOut : {
			uint8_t channel = data[2];
			float voltage;
			
			union Convert convert;
			
			convert.char_temp[0] = data[3];
			convert.char_temp[1] = data[4];
			convert.char_temp[2] = data[5];
			convert.char_temp[3] = data[6];
			voltage = convert.float_temp;
			
			voltageOutInit(voltage , channel);
			break;
		}
	}
}
//
//incoming data check
void checkForIncomingData(char *data , uint32_t len , enum ConnectionState state){
//////wifi receive data	
	if (state == wifi){
		if(wifiDataLength == 3 && data[0] == 'B' && data[1] == 'y' && data[2] == 'e'){
			connectionState = notConnected;
			dataMode = noData;
			writingSendDataIndex=0;
			readingSendDataIndex=0;
			sendData[0].readySend=0;
			sendData[1].readySend=0;
			wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 6 && data[0] == 's' && data[1] == 's' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd'){
			handleIncomingData(data,len,noData);
		  wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 5 && data[0] == 'H' && data[1] == 'e' && data[2] == 'l' && data[3] == 'l' && data[4] == 'o'){
			connectionState = wifi;
			wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 6 && data[0] == 's' && data[1] == 'm' && data[2] == 'd' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd'){
			handleIncomingData(data,len,diode);
		  wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 6 && data[0] == 's' && data[1] == 'm' && data[2] == 'c' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd'){
			handleIncomingData(data,len,connection);
		  wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 5 && data[0] == 's' && data[1] == 'i' && data[2] == 'e' && data[3] == 'n' && data[4] == 'd'){
			handleIncomingData(data,len,current);
		  wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 6 && data[0] == 's' && data[1] == 'r' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd'){
			handleIncomingData(data,len,resistor);
		  wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 6 && data[0] == 's' && data[1] == 'c' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd'){
			handleIncomingData(data,len,capacitor);
		  wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 21 && data[0] == 's' && data[1] == 'a' && data[18] == 'e' && data[19] == 'n' && data[20] == 'd'){
			handleIncomingData(data,len,analog);
		  wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 21 && data[0] == 's' && data[1] == 'd' && data[18] == 'e' && data[19] == 'n' && data[20] == 'd'){
			handleIncomingData(data,len,digital);
		  wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 10 && data[0] == 's' && data[1] == 'v' && data[7] == 'e' && data[8] == 'n' && data[9] == 'd'){
			handleIncomingData(data,len,voltageOut);
		  wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(wifiDataLength == 19&& data[0] == 's' && data[1] == 'w' && data[16] == 'e' && data[17] == 'n' && data[18] == 'd'){
			handleIncomingData(data,len,dac);
		  wifiDataLength = 0;
			packetNumberWifi = 0;
		}
		else if(data[0] != 'H' && data[0] != 'B' && data[0] != 's'){
			wifiDataLength = 0;
		}
		else if(wifiDataLength > 20){
			wifiDataLength = 0;
		}
	}
	
//////usb receive data
	else if(state == usb){
		if(data[0] == 'H' && data[1] == 'e' && data[2] == 'l' && data[3] == 'l' && data[4] == 'o'){
				CDC_Transmit_FS("received" , 8);
				connectionState = usb;
		}
		else if(data[0] == 'B' && data[1] == 'y' && data[2] == 'e'){
			packetNumberUsb = 0;
		}
		else if(len == 6 && data[0] == 's' && data[1] == 's' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd'){
			handleIncomingData(data,len,noData);
		  packetNumberUsb = 0;
		}
		else if(len == 6 && data[0] == 's' && data[1] == 'm' && data[2] == 'd' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd'){
			handleIncomingData(data,len,diode);
		  packetNumberUsb = 0;
		}
		else if(len == 6 && data[0] == 's' && data[1] == 'm' && data[2] == 'c' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd'){
			handleIncomingData(data,len,connection);
		  packetNumberUsb = 0;
		}
		else if(len == 5 && data[0] == 's' && data[1] == 'i' && data[2] == 'e' && data[3] == 'n' && data[4] == 'd'){
			handleIncomingData(data,len,current);
		  packetNumberUsb = 0;
		}
		else if(len == 6 && data[0] == 's' && data[1] == 'r' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd'){
			handleIncomingData(data,len,resistor);
		  packetNumberUsb = 0;
		}
		else if(len == 6 && data[0] == 's' && data[1] == 'c' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd'){
			handleIncomingData(data,len,capacitor);
		  packetNumberUsb = 0;
		}
		else if(len == 21 && data[0] == 's' && data[1] == 'a' && data[18] == 'e' && data[19] == 'n' && data[20] == 'd'){
			handleIncomingData(data,len,analog);
		  packetNumberUsb = 0;
		}
		else if(len == 21 && data[0] == 's' && data[1] == 'd' && data[18] == 'e' && data[19] == 'n' && data[20] == 'd'){
			handleIncomingData(data,len,digital);
		  packetNumberUsb = 0;
		}
		else if(len == 10 && data[0] == 's' && data[1] == 'v' && data[7] == 'e' && data[8] == 'n' && data[9] == 'd'){
			handleIncomingData(data,len,voltageOut);
		  packetNumberUsb = 0;
		}
		else if(len == 19&& data[0] == 's' && data[1] == 'w' && data[16] == 'e' && data[17] == 'n' && data[18] == 'd'){
			handleIncomingData(data,len,dac);
		  packetNumberUsb = 0;
		}
	}
}

//
//usb data
void CDC_ReceiveCallBack(uint8_t *buf,uint32_t len){
	checkForIncomingData(buf,len,usb);
}


//
//esp data
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart == &huart4){
		wifiData[wifiDataLength] = wifiChar;
		wifiDataLength++;
		checkForIncomingData(wifiData,wifiDataLength,wifi);
		HAL_UART_Receive_IT(&huart4,&wifiChar,1);
	}
}

//
//ADC callback
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
		
	if (hadc == &hadc1){
		analogDataReadyCh1 = 1;
		tempADC1++;
	}
	else if(hadc == &hadc2){
		analogDataReadyCh2 = 1;
		tempADC2++;
	}
	else if(hadc == &hadc3&& dataMode != digital && dataMode != analog && dataMode != noData){
		adcMeasureReady = 1;
		
	}
}
//
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  MX_USB_DEVICE_Init();
  MX_DAC_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  MX_UART4_Init();
  MX_ADC3_Init();
  MX_TIM4_Init();
  MX_TIM8_Init();
  MX_ADC2_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim1);
	HAL_TIM_Base_Start_IT(&htim4);
	//HAL_TIM_Base_Start_IT(&htim8);
	
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
	htim2.Instance->CCR1 =  50;
	htim2.Instance->CCR2 =  99;
	htim2.Instance->CCR3 =  20;
	htim2.Instance->CCR4 =  50;
	
	HAL_UART_Receive_IT(&huart4,&wifiChar,1);
			
	makeWaveDac(&hdac,DAC_CHANNEL_1,&htim3,rect,64,128);
	
	//HAL_TIM_Base_Start_IT(&htim3);
	//tempAshk = value_dac16[10];
	//HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t *)value_dac16 , 1, DAC_ALIGN_12B_R);
	
	
	
	//////init default value

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
		//HAL_TIM_Base_Stop_IT(&htim1);
		
		//(&htim8)->Instance->PSC = 719;
		//(&htim3)->Init.Period = 9999;
		//(&htim3)->Instance->ARR = 9999;
		//__HAL_TIM_CLEAR_IT(&htim3 ,TIM_IT_UPDATE);
		//HAL_TIM_Base_Start_IT(&htim3);
		
		
  while (1)
  {
		//startAdcInput();
		//makeWaveDac(&hdac , DAC_CHANNEL_1 , sinusoidal);
		
		if(dataMode == analog){
			int ch1Div,ch2Div,ch3Div,ch4Div;
			int ch1Base,ch2Base,ch3Base,ch4Base;
			int length;
	
			if(analogDataReadyCh1 == 1 || analogDataReadyCh2 == 1){
				ch1Div = lroundf((float)analogBytesMax[0]/(float)analogBytes[0]);
				ch2Div = lroundf((float)analogBytesMax[0]/(float)analogBytes[1]);
				ch3Div = lroundf((float)analogBytesMax[1]/(float)analogBytes[2]);
				ch4Div = lroundf((float)analogBytesMax[1]/(float)analogBytes[3]);
				
				analogBytes[0] = analogBytesMax[0]/ch1Div;
				analogBytes[1] = analogBytesMax[0]/ch2Div;
				analogBytes[2] = analogBytesMax[1]/ch3Div;
				analogBytes[3] = analogBytesMax[1]/ch4Div;
				
				ch1Base = 4;
				ch2Base = ch1Base+analogBytes[0]*4+2; //channel byteNumber
				ch3Base = ch2Base+analogBytes[1]*4+2; //channe2 byteNumber
				ch4Base = ch3Base+analogBytes[2]*4+2; //channe3 byteNumber
				
				length = analogBytes[0]*4+analogBytes[1]*4+analogBytes[2]*4+analogBytes[3]*4;
				length += 13; //this 13 is for s,e,n,d,packetNumber,channel byteNumber
				
			}
			
		
			if(analogDataReadyCh1 == 1){
				uint16_t analogByteADC1Ch2[501];
				uint16_t analogByteADC1Ch1[501];				
				for(int i=0 ; i<1000 ; i++){
						if(i%2 == 0)
							analogByteADC1Ch1[i/2] = analogByteADC1[i];
						else
							analogByteADC1Ch2[i/2] = analogByteADC1[i];
					}
				analogDataReadyCh1=0;
					
					
				if(analogDataNumberADC1 < 3){
					if(analogBytesMax[0]%2 == 0){
					HAL_ADC_Start_DMA(&hadc1, analogByteADC1, analogBytesMax[0]);
					}
					else if(analogBytesMax[0]%2 == 1){
						if(analogOddNumberADC1%2 == 0)
							HAL_ADC_Start_DMA(&hadc1, analogByteADC1, analogBytesMax[0]+1);
					else
						HAL_ADC_Start_DMA(&hadc1, analogByteADC1, analogBytesMax[0]-1);
					analogOddNumberADC1++;
					analogOddNumberADC1%=2;
					}
			}
				
			
			
				if(analogDataNumberADC1 < 4){
					union Convert convert;
						
					if (sendData[writingSendDataIndex].readySend == 0){
						
						convert.integer2_temp = analogBytes[0]*4;
						sendData[writingSendDataIndex].bytes[ch1Base-2] = convert.char_temp[0];
						sendData[writingSendDataIndex].bytes[ch1Base-1] = convert.char_temp[1];
						
						convert.integer2_temp = analogBytes[1]*4;
						sendData[writingSendDataIndex].bytes[ch2Base-2] = convert.char_temp[0];
						sendData[writingSendDataIndex].bytes[ch2Base-1] = convert.char_temp[1];
						
						///////ADC1 set sending data index variables
						int index = analogBytesMax[0];
						int channel1Index = (analogDataNumberADC1*analogBytes[0])/2;
						int channel2Index = (analogDataNumberADC1*analogBytes[1])/2;
						if (index%2 == 0) index/=2;
						else if(analogDataNumberADC1%2 == 0) index=(index+1)/2;
						else if(analogDataNumberADC1%2 == 1){ index=(index-1)/2; channel1Index+=1; channel2Index+=1;}
						test1++;
						
						for(int i=0 ; i < index ; i++){ ///this is for adc1 channel 1
								if((channel1Index+i)%ch1Div == 0){
									convert.integer2_temp = analogByteADC1Ch1[i];
									sendData[writingSendDataIndex].bytes[ch1Base+2*(channel1Index+i)/ch1Div]   = convert.char_temp[0];
									sendData[writingSendDataIndex].bytes[ch1Base+2*(channel1Index+i)/ch1Div+1] = convert.char_temp[1];
								}							
						}
						for(int i=0 ; i < index ; i++){ ///this is for adc1 channel 2
								if((channel2Index+i)%ch2Div == 0){
									convert.integer2_temp = analogByteADC1Ch2[i];
									sendData[writingSendDataIndex].bytes[ch2Base+2*(channel2Index+i)/ch2Div] = convert.char_temp[0];
									sendData[writingSendDataIndex].bytes[ch2Base+2*(channel2Index+i)/ch2Div+1] = convert.char_temp[1];	
								}
						}
				}
					
					analogDataNumberADC1++;
				}
			}
			
			
			if(analogDataReadyCh2 == 1){
				uint16_t analogByteADC2Ch1[501];
				uint16_t analogByteADC2Ch2[501];	
				for(int i=0 ; i<1000 ; i++){
					if(i%2 == 0)
						analogByteADC2Ch1[i/2] = analogByteADC2[i];
				else
						analogByteADC2Ch2[i/2] = analogByteADC2[i];
				}
				analogDataReadyCh2 = 0;
					
				if(analogDataNumberADC2 < 3){			
					if(analogBytesMax[1]%2 == 0){
								HAL_ADC_Start_DMA(&hadc2, analogByteADC2, analogBytesMax[1]);
						}
						else if(analogBytesMax[1]%2 == 1){
							if(analogOddNumberADC2%2 == 0)
								HAL_ADC_Start_DMA(&hadc2, analogByteADC2, analogBytesMax[1]+1);
						else
							HAL_ADC_Start_DMA(&hadc2, analogByteADC2, analogBytesMax[1]-1);
						analogOddNumberADC2++;
						analogOddNumberADC2%=2;
						}
				}
				
				
				
				if(analogDataNumberADC2 < 4){
					union Convert convert;
						
					if (sendData[writingSendDataIndex].readySend == 0){
						
						convert.integer2_temp = analogBytes[2]*4;
						sendData[writingSendDataIndex].bytes[ch3Base-2] = convert.char_temp[0];
						sendData[writingSendDataIndex].bytes[ch3Base-1] = convert.char_temp[1];
						
						convert.integer2_temp = analogBytes[3]*4;
						sendData[writingSendDataIndex].bytes[ch4Base-2] = convert.char_temp[0];
						sendData[writingSendDataIndex].bytes[ch4Base-1] = convert.char_temp[1];
						
						///////ADC2 set sending data index variables
						int index = analogBytesMax[1];
						int channel3Index = analogDataNumberADC2*analogBytes[2]/2;
						int channel4Index = analogDataNumberADC2*analogBytes[3]/2;
						if (index%2 == 0) index/=2;
						else if(analogDataNumberADC2%2 == 0) index=(index+1)/2;
						else if(analogDataNumberADC2%2 == 1){ index=(index-1)/2; channel3Index+=1; channel4Index+=1;}
						test2++;
						
						for(int i=0 ; i < index ; i++){///this is for adc2 channel 1
								if((channel3Index+i)%ch3Div == 0){
									convert.integer2_temp = analogByteADC2Ch1[i];
									sendData[writingSendDataIndex].bytes[ch3Base+2*(channel3Index+i)/ch3Div]   = convert.char_temp[0];
									sendData[writingSendDataIndex].bytes[ch3Base+2*(channel3Index+i)/ch3Div+1] = convert.char_temp[1];	
								}							
						}
						for(int i=0 ; i < index ; i++){///this is for adc2 channel 2
								if((channel4Index+i)%ch4Div == 0){
									convert.integer2_temp = analogByteADC2Ch2[i];
									sendData[writingSendDataIndex].bytes[ch4Base+2*(channel4Index+i)/ch4Div]   = convert.char_temp[0];
									sendData[writingSendDataIndex].bytes[ch4Base+2*(channel4Index+i)/ch4Div+1] = convert.char_temp[1];	
								}
						}
				}
					
				analogDataNumberADC2++;
				}
			}
			
			if(analogDataNumberADC1 == 4 && analogDataNumberADC2 == 4){
				if (sendData[writingSendDataIndex].readySend == 0){
						sendData[writingSendDataIndex].length = length;
						sendData[writingSendDataIndex].bytes[0] = 's';
						sendData[writingSendDataIndex].bytes[length-3] = 'e';	
						sendData[writingSendDataIndex].bytes[length-2] = 'n';	
						sendData[writingSendDataIndex].bytes[length-1] = 'd';
						sendData[writingSendDataIndex].readySend = 1;
						writingSendDataIndex++;
						writingSendDataIndex %= 2;
						analogDataNumberADC1 = 0;
						analogDataNumberADC2 = 0;
					
						if(analogBytesMax[0]%2 == 0){
							HAL_ADC_Start_DMA(&hadc1, analogByteADC1, analogBytesMax[0]);
						}
						else if(analogBytesMax[0]%2 == 1){
							if(analogOddNumberADC1%2 == 0)
								HAL_ADC_Start_DMA(&hadc1, analogByteADC1, analogBytesMax[0]+1);
						else
								HAL_ADC_Start_DMA(&hadc1, analogByteADC1, analogBytesMax[0]-1);
								analogOddNumberADC1++;
								analogOddNumberADC1%=2;
							}
						
						if(analogBytesMax[1]%2 == 0){
							HAL_ADC_Start_DMA(&hadc2, analogByteADC2, analogBytesMax[1]);
						}
						else if(analogBytesMax[1]%2 == 1){
							if(analogOddNumberADC2%2 == 0)
								HAL_ADC_Start_DMA(&hadc2, analogByteADC2, analogBytesMax[1]+1);
						else
							HAL_ADC_Start_DMA(&hadc2, analogByteADC2, analogBytesMax[1]-1);
						analogOddNumberADC2++;
						analogOddNumberADC2%=2;
						}
						
							
				}
			}
		}
		
		else if(dataMode == digital){
			union Convert convert;
			uint8_t digitalByteCH1Cpy[1001],digitalByteCH2Cpy[1001],digitalByteCH3Cpy[1001],digitalByteCH4Cpy[1001];
			
			///copy data digital and release arrays 
			if(digitalDataReady == 1){
				for(int i=0 ; i < digitalBytesMax ; i++){
							digitalByteCH1Cpy[i] = digitalByteCH1[i];
				}
				for(int i=0 ; i < digitalBytesMax ; i++){
							digitalByteCH2Cpy[i] = digitalByteCH2[i];	
				}
				for(int i=0 ; i < digitalBytesMax ; i++){
							digitalByteCH3Cpy[i] = digitalByteCH3[i];
				}
				for(int i=0 ; i < digitalBytesMax ; i++){
							digitalByteCH4Cpy[i] = digitalByteCH4[i];	
				}
				digitalDataReady = 0;
				
				int ch1Div = lroundf((float)digitalBytesMax/(float)digitalBytes[0]);
				int ch2Div = lroundf((float)digitalBytesMax/(float)digitalBytes[1]);
				int ch3Div = lroundf((float)digitalBytesMax/(float)digitalBytes[2]);
				int ch4Div = lroundf((float)digitalBytesMax/(float)digitalBytes[3]);
				
				digitalBytes[0] = digitalBytesMax/ch1Div;
				digitalBytes[1] = digitalBytesMax/ch2Div;
				digitalBytes[2] = digitalBytesMax/ch3Div;
				digitalBytes[3] = digitalBytesMax/ch4Div;
				int ch1Base = 4;
				int ch2Base = ch1Base+digitalBytes[0]+2; //channel2 byteNumber
				int ch3Base = ch2Base+digitalBytes[1]+2; //channel3 byteNumber
				int ch4Base = ch3Base+digitalBytes[2]+2; //channel4 byteNumber
				
				int length = digitalBytes[0]+digitalBytes[1]+digitalBytes[2]+digitalBytes[3];
				length += 13; //this 13 is for s,e,n,d,packetNumber,channel byteNumber
				
				if (sendData[writingSendDataIndex].readySend == 0){
				sendData[writingSendDataIndex].length = length;
				sendData[writingSendDataIndex].bytes[0] = 's';
				sendData[writingSendDataIndex].bytes[length-3] = 'e';	
				sendData[writingSendDataIndex].bytes[length-2] = 'n';	
				sendData[writingSendDataIndex].bytes[length-1] = 'd';
				
				convert.integer2_temp = digitalBytes[0];
				sendData[writingSendDataIndex].bytes[ch1Base-2] = convert.char_temp[0];
				sendData[writingSendDataIndex].bytes[ch1Base-1] = convert.char_temp[1];
				
				convert.integer2_temp = digitalBytes[1];
				sendData[writingSendDataIndex].bytes[ch2Base-2] = convert.char_temp[0];
				sendData[writingSendDataIndex].bytes[ch2Base-1] = convert.char_temp[1];
				
				convert.integer2_temp = digitalBytes[2];
				sendData[writingSendDataIndex].bytes[ch3Base-2] = convert.char_temp[0];
				sendData[writingSendDataIndex].bytes[ch3Base-1] = convert.char_temp[1];
				
				convert.integer2_temp = digitalBytes[3];
				sendData[writingSendDataIndex].bytes[ch4Base-2] = convert.char_temp[0];
				sendData[writingSendDataIndex].bytes[ch4Base-1] = convert.char_temp[1];
				
				for(int i=0 ; i < digitalBytesMax ; i++){
						if(i%ch1Div == 0){
							sendData[writingSendDataIndex].bytes[ch1Base+i/ch1Div] = digitalByteCH1Cpy[i];
						}							
				}
				for(int i=0 ; i < digitalBytesMax ; i++){
						if(i%ch2Div == 0){
							sendData[writingSendDataIndex].bytes[ch2Base+i/ch2Div] = digitalByteCH2Cpy[i];	
						}
				}
				for(int i=0 ; i < digitalBytesMax ; i++){
						if(i%ch3Div == 0){
							sendData[writingSendDataIndex].bytes[ch3Base+i/ch3Div] = digitalByteCH3Cpy[i];
						}						
				}
				for(int i=0 ; i < digitalBytesMax ; i++){
						if(i%ch4Div == 0){
							sendData[writingSendDataIndex].bytes[ch4Base+i/ch4Div] = digitalByteCH4Cpy[i];	
						}
				}
				sendData[writingSendDataIndex].readySend = 1;
				writingSendDataIndex++;
				writingSendDataIndex %= 2;
			}
			}
			HAL_Delay(1);
		}
		else if(dataMode == connection){
			uint16_t adcValue = connectionCheck(&hadc3);
			
			char tempData[7];
			tempData[0] = 's';
			tempData[4] = 'e';
			tempData[5] = 'n';
			tempData[6] = 'd';
			
			union Convert convert;
			convert.integer2_temp = adcValue;
			tempData[2] = convert.char_temp[0];
			tempData[3] = convert.char_temp[1];
			
			if (sendData[writingSendDataIndex].readySend == 0){
				sendData[writingSendDataIndex].length = 7;
				//sendData[writingSendDataIndex].bytes = tempData;
				memcpy(sendData[writingSendDataIndex].bytes , tempData , sendData[writingSendDataIndex].length);
				sendData[writingSendDataIndex].readySend = 1;
				writingSendDataIndex++;
				writingSendDataIndex %= 2;
			}
			
			HAL_Delay(100);
		
		}
		else if(dataMode == resistor){
			uint16_t adcValue = resistorCheck(&hadc3);
			
			char tempData[7];
			tempData[0] = 's';
			tempData[4] = 'e';
			tempData[5] = 'n';
			tempData[6] = 'd';
			
			union Convert convert;
			convert.integer2_temp = adcValue;
			tempData[2] = convert.char_temp[0];
			tempData[3] = convert.char_temp[1];
			
			if (sendData[writingSendDataIndex].readySend == 0){
				sendData[writingSendDataIndex].length = 7;
				//sendData[writingSendDataIndex].bytes = tempData;
				memcpy(sendData[writingSendDataIndex].bytes , tempData , sendData[writingSendDataIndex].length);
				sendData[writingSendDataIndex].readySend = 1;
				writingSendDataIndex++;
				writingSendDataIndex %= 2;
			}
			
			HAL_Delay(5000);
		}
		else if(dataMode == capacitor){
			uint16_t adcValue = capacitorCheck(&hadc3);
			
			char tempData[7];
			tempData[0] = 's';
			tempData[4] = 'e';
			tempData[5] = 'n';
			tempData[6] = 'd';
			
			union Convert convert;
			convert.integer2_temp = adcValue;
			tempData[2] = convert.char_temp[0];
			tempData[3] = convert.char_temp[1];
			
			if (sendData[writingSendDataIndex].readySend == 0){
				sendData[writingSendDataIndex].length = 7;
				//sendData[writingSendDataIndex].bytes = tempData;
				memcpy(sendData[writingSendDataIndex].bytes , tempData , sendData[writingSendDataIndex].length);
				sendData[writingSendDataIndex].readySend = 1;
				writingSendDataIndex++;
				writingSendDataIndex %= 2;
			}
			
			
			HAL_Delay(5000);
		}
		else if(dataMode == diode){
			uint16_t adcValue = diodeCheck(&hadc3);
			
			char tempData[7];
			tempData[0] = 's';
			tempData[4] = 'e';
			tempData[5] = 'n';
			tempData[6] = 'd';
			
			union Convert convert;
			convert.integer2_temp = adcValue;
			tempData[2] = convert.char_temp[0];
			tempData[3] = convert.char_temp[1];
			
			if (sendData[writingSendDataIndex].readySend == 0){
				sendData[writingSendDataIndex].length = 7;
				//sendData[writingSendDataIndex].bytes = tempData;
				memcpy(sendData[writingSendDataIndex].bytes , tempData , sendData[writingSendDataIndex].length);
				sendData[writingSendDataIndex].readySend = 1;
				writingSendDataIndex++;
				writingSendDataIndex %= 2;
			}
			
			HAL_Delay(100);
		}
		else if(dataMode == current){
			uint16_t adcValue = currentCheck(&hadc3);
			
			char tempData[7];
			tempData[0] = 's';
			tempData[4] = 'e';
			tempData[5] = 'n';
			tempData[6] = 'd';
			
			union Convert convert;
			convert.integer2_temp = adcValue;
			tempData[2] = convert.char_temp[0];
			tempData[3] = convert.char_temp[1];
			
			if (sendData[writingSendDataIndex].readySend == 0){
				sendData[writingSendDataIndex].length = 7;
				//sendData[writingSendDataIndex].bytes = tempData;
				memcpy(sendData[writingSendDataIndex].bytes , tempData , sendData[writingSendDataIndex].length);
				sendData[writingSendDataIndex].readySend = 1;
				writingSendDataIndex++;
				writingSendDataIndex %= 2;
			}
			
			HAL_Delay(100);
		}
		
		
		//setPwm(0,60);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB|RCC_PERIPHCLK_USART1
                              |RCC_PERIPHCLK_UART4|RCC_PERIPHCLK_TIM1
                              |RCC_PERIPHCLK_TIM8|RCC_PERIPHCLK_ADC12
                              |RCC_PERIPHCLK_ADC34;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Uart4ClockSelection = RCC_UART4CLKSOURCE_PCLK1;
  PeriphClkInit.Adc12ClockSelection = RCC_ADC12PLLCLK_DIV1;
  PeriphClkInit.Adc34ClockSelection = RCC_ADC34PLLCLK_DIV1;
  PeriphClkInit.USBClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  PeriphClkInit.Tim1ClockSelection = RCC_TIM1CLK_HCLK;
  PeriphClkInit.Tim8ClockSelection = RCC_TIM8CLK_HCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
