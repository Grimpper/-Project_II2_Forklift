#include "lift.h"
#include "gpio.h"

#define INIT_FLOOR 0

int current_floor = INIT_FLOOR;

void lift_Init(void){
	GPIO_InitTypeDef lift_port;
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	lift_port.Pin = GPIO_PIN_0;
	lift_port.Mode = GPIO_MODE_INPUT;
	lift_port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOA, &lift_port);
	
	
}

void lift_Up(void)
{
	// Motor actuator UP
	
	
}

void lift_Down(void)
{
	// Motor actuator DOWN
}

void update_floor(int aux_floor)
{	
	if(aux_floor == 1 && current_floor != 4) //check if the current floor is the top one
		{
				current_floor++;
				lift_Up();
	  }
		
	if(aux-floor == 2 && current_floor != 0) //check if the current floor is the botton one
		{
				current_floor--;
				lift_Down();
		}

	
}

int get_floor(void){ //return current floor (0-4)
	
	return current_floor;
	
}
