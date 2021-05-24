#include <stdio.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_gpio.h"
#include "tim.h"
#include "gpio.h"
#include "overWeight.h"
#include "safetyHandler.h"


void initOverweightPin(void)
{
	GPIO_InitTypeDef port;
	
	HAL_NVIC_DisableIRQ(EXTI3_IRQn);
	
	if (!__HAL_RCC_GPIOA_IS_CLK_ENABLED()) __HAL_RCC_GPIOA_CLK_ENABLE();
	
	port.Pin = GPIO_PIN_3;
	port.Mode = GPIO_MODE_IT_RISING_FALLING;
  port.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &port);
	
	HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
	
	HAL_NVIC_EnableIRQ(EXTI3_IRQn);
	
	
}

void overWeightRutine(void)
{
			extern uint8_t overWeight;
			lockLifter();
			
		  while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)==SET){
			
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

	
	