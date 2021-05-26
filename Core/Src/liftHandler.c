#include "liftHandler.h"
#include "safetyHandler.h"
#include "displayHandler.h"
#include "gpio.h"
#include "tim.h"

#define DUTY_CYCLE 75

static uint16_t _currentFloor = 0;

void initUserButton()
{
	GPIO_InitTypeDef lift_port;
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	lift_port.Pin = GPIO_PIN_0;
	lift_port.Mode = GPIO_MODE_INPUT;
	lift_port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOA, &lift_port);
}

void initLift(){
	initUserButton();
	initDisplay();
	initSafetyPins();	
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
	htim14.Instance->CCR1 = DUTY_CYCLE;
	
}

void liftDown()
{
	// Motor actuator DOWN
	htim14.Instance->CCR1 = DUTY_CYCLE;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET); 	//relay active to change motor polarity
}

void stopMotor()
{
	htim14.Instance-> CCR1 = 0;
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
