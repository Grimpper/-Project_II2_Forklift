#include "safetyHandler.h"
#include <stm32f4xx_hal.h>
#include <gpio.h>
#include <stdio.h>
#include "liftHandler.h"
#include "tim.h"

void initSafetyPins()
{
	GPIO_InitTypeDef port;

	HAL_NVIC_DisableIRQ(EXTI1_IRQn);
	
	if (!__HAL_RCC_GPIOA_IS_CLK_ENABLED()) __HAL_RCC_GPIOA_CLK_ENABLE();
	
	port.Pin = GPIO_PIN_1;
	port.Mode = GPIO_MODE_IT_RISING;
	port.Pull = GPIO_PULLDOWN;
	
	HAL_GPIO_Init(GPIOA, &port);	

	HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
	
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	
	HAL_NVIC_DisableIRQ(EXTI2_IRQn);
	
	port.Pin = GPIO_PIN_2;
	port.Mode = GPIO_MODE_IT_RISING_FALLING;
	port.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &port);
	
	HAL_NVIC_SetPriority(EXTI2_IRQn, 1, 0);
	
	HAL_NVIC_EnableIRQ(EXTI2_IRQn);

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
	stopMotor();
  HAL_NVIC_DisableIRQ(EXTI0_IRQn);
	HAL_TIM_Base_Stop_IT(&htim6);
}

void unlockLifter()
{
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}
