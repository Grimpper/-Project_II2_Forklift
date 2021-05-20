#include "gpio.h"
#include "lift.h"
#include "display.h"

volatile uint8_t numbers[]={0x3f,0x06,0x5b,0x4f,0x6d};
uint8_t i=0;

void display_init (void)
{
	GPIO_InitTypeDef display_port;
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	display_port.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
	display_port.Mode = GPIO_MODE_OUTPUT_PP;
	display_port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOC, &display_port);
}

void display_show (void)
{
	GPIOC->ODR = numbers[get_floor()];
}
