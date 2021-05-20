#include "gpio.h"
#include "lift.h"
#include "display.h"

volatile uint16_t numbers[]={0xff40,0xff79,0xffa4,0xff30,0xff19};
uint8_t i=0;

void display_init (void)
{
	GPIO_InitTypeDef display_port;
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	display_port.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
	display_port.Mode = GPIO_MODE_OUTPUT_PP;
	display_port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOA, &display_port);
}

void display_show (void)
{
	GPIOC->ODR = numbers[get_floor()];
}

