#include "safetyHandler.h"
#include <stm32f4xx_hal.h>
#include <gpio.h>
#include <stdio.h>
#include "tim.h"

void initSafetyPins()
{
	GPIO_InitTypeDef port;
	
	if (!__HAL_RCC_GPIOA_IS_CLK_ENABLED()) __HAL_RCC_GPIOA_CLK_ENABLE();
	
	port.Pin = GPIO_PIN_1;
	port.Mode = GPIO_MODE_IT_RISING;
	port.Pull = GPIO_PULLDOWN;
	
	HAL_GPIO_Init(GPIOA, &port);	
	
	port.Pin = GPIO_PIN_2;
	port.Mode = GPIO_MODE_IT_RISING_FALLING;

	HAL_GPIO_Init(GPIOA, &port);	
}

void emergencyStop()
{
	lockLifter();
	
	uint32_t emergencyLightPins = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	while (1) 
	{
		HAL_GPIO_WritePin(GPIOD, emergencyLightPins, GPIO_PIN_SET);
		HAL_Delay(250);
		HAL_GPIO_WritePin(GPIOD, emergencyLightPins, GPIO_PIN_RESET);
		HAL_Delay(250);
	}
}

void lockLifter()
{	
	//ANTONIO'S FUNCTION TO STOP MOTOR
  HAL_NVIC_DisableIRQ(EXTI0_IRQn);
	HAL_TIM_Base_Stop_IT(&htim6);
}

void unlockLifter()
{
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}
