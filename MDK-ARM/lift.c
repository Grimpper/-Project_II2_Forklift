#include "lift.h"
#include "gpio.h"
#include "tim.h"

#define INIT_FLOOR 0
#define DUTY_CYCLE 75

int current_floor = INIT_FLOOR;




void lift_Init(void){
	GPIO_InitTypeDef lift_port;
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	lift_port.Pin = GPIO_PIN_0;
	lift_port.Mode = GPIO_MODE_INPUT;
	lift_port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOA, &lift_port);
	
	
}

void pwm_switch_Init(void)
{
	GPIO_InitTypeDef pwm_port;
	
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	pwm_port.Pin = GPIO_PIN_15;
	pwm_port.Mode = GPIO_MODE_OUTPUT_PP;
	pwm_port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOD,&pwm_port);
	
}

void lift_Up(void)
{
	// Motor actuator UP
	htim14.Instance->CCR1 = DUTY_CYCLE;
	
}

void lift_Down(void)
{
	// Motor actuator DOWN
	htim14.Instance->CCR1 = DUTY_CYCLE;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);  //relay active to change motor polarity
}

void update_floor(int aux_floor)
{	
	if(aux_floor == 1 && current_floor != 4) //check if the current floor is the top one
		{
				current_floor++;
				lift_Up();
	  }
		
	if(aux_floor == 2 && current_floor != 0) //check if the current floor is the botton one
		{
				current_floor--;
				lift_Down();
		}

	
}

void motor_stop(void)
{
	htim14.Instance-> CCR1 = 0;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

int get_floor(void){ //return current floor (0-4)
	
	return current_floor;
	
}
