#include "liftHandler.h"
#include "safetyHandler.h"
#include "displayHandler.h"
#include "doubleTapHandler.h"
#include "gpio.h"
#include "tim.h"
#include <stdio.h>

#define DUTY_CYCLE 75

static uint16_t _currentFloor = 0;

void initUserButton()
{
	GPIO_InitTypeDef lift_port;
	
	HAL_NVIC_DisableIRQ(EXTI0_IRQn);
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	lift_port.Pin = GPIO_PIN_0;
	lift_port.Mode = GPIO_MODE_IT_RISING;
	lift_port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOA, &lift_port);
	
	HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void initStatusLeds()
{
	GPIO_InitTypeDef port;
	
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	port.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	port.Mode = GPIO_MODE_OUTPUT_PP;
	port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOD, &port);	
}

void initLift(){
	initUserButton();
	initStatusLeds();
	initDisplay();
	initSafetyPins();	
	initPwmSwitch();
	
	setTappingTerm(300);
	setMinTappingTerm(60);
	updateDisplay();
	
	HAL_TIM_PWM_Start (&htim14,TIM_CHANNEL_1);
	
	printf("\nINITIALIZED\n");
}

void initPwmSwitch()
{
	GPIO_InitTypeDef pwm_port;
	
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	pwm_port.Pin = GPIO_PIN_15;
	pwm_port.Mode = GPIO_MODE_OUTPUT_PP;
	pwm_port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOD,&pwm_port);
}

void liftUp()
{
	// Motor actuator UP
	TIM14->CCR1 = DUTY_CYCLE;
}

void liftDown()
{
	// Motor actuator DOWN
	TIM14->CCR1 = DUTY_CYCLE;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET); 	//relay active to change motor polarity
}

void stopMotor()
{
	TIM14-> CCR1 = 0;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

void updateFloor(tapActionEnum tapAction)
{	
	if(_currentFloor != TOP_FLOOR && tapAction == UP) //check if the current floor is the top one
		{	
				liftUp();
				_currentFloor++;
	  }
		
	else if(_currentFloor != BOTTOM_FLOOR && tapAction == DOWN) //check if the current floor is the botton one
		{	
				liftDown();
			  _currentFloor--;
		}
}

uint16_t getFloor(){ //return current floor
	
	return _currentFloor;
	
}
