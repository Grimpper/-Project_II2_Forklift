#include <stdio.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_gpio.h"
#include "tim.h"
#include "gpio.h"
#include "overWeight.h"
#include "safetyHandler.h"

#define MVOLT_REF 2950

void overWeightCondition(void)
{
		uint32_t weight;
	
			weight = readWeight();
		
		if (weight > 5000)
		{
			lockLifter();
			
		  while(weight > 5000){
      
			weight = readWeight();
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
      HAL_Delay(2000);
				
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);	
			HAL_Delay(2000);
				
			}
			
		  unlockLifter();
			
		}
	
	
}


void weightInit(void){
	
	/*
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); // PORT C
	
	// ANALOGIC INPUT
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}
	

void adcInit(void){
	
	RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_ADC1, ENABLE); // ADC 1
	
	//PREPARE HARDWARE
	
	ADC_CommonStruckInit (&ADC_CommonInitStructure);
	
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaelr_Div4;
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStructure);
	
	// ADC init
	ADC_StructInit (&ADC_InitStructure);
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfConversion = 1;
  ADC_Init(ADC1, &ADC_InitStructure);

  ADC_InjectedSequencerLengthConfig(ADC, 1);
	ADC_SetInjectedOffset(ADC!, ADC_InjectedChannel_1, 0);
	ADC_InjectedChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_480Cycles);
	
	ADC_Cmd(ADC!, ENABLE);
	
}
*/

int32_t readWeight(void){  //EJEMPLO COPIADO DE UN LM35, VER COMO SERÍA LA ECUACIÓN PARA EL PESO CON OTRO SENSOR.
/*	
	uint32_t adcValue;
	int32_T milivolts;
	int32_t kg;
	
	ADC_ClearFlag(ADC1, ADC_FLAG_JEOC);
	
	ADC_SoftwareStartInjectedConv(ADC1);
	
	while (ADC_GetInjectedConversionValue(ADC1, ADC_FLAG_JEOC) == RESET);
	
	adcValue = ADC_GetInjectedConversionValue(ADC1, ADC_injectedChannel_1);
	
	milivolts = (adcValue * MVOLT_REF)/0XFFF;
	milivolts *=2;
	kg = milivolts/10;
	
	return kg;
*/	
}	
void overWeightRutine(void){
	
}
	
	