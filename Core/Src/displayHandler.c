#include "gpio.h"
#include "liftHandler.h"
#include "displayHandler.h"

const uint8_t floorTable[10] = {
	0x3F,	// 0b 0011 1111 = 0
	0x06, // 0b 0000 0110 = 1
	0x5B, // 0b 0101 1011 = 2
	0x4F, // 0b 0100 1111 = 3
	0x66, // 0b 0110 0110 = 4
	0x6D, // 0b 0110 1101 = 5
	0x7D, // 0b 0111 1101 = 6
	0x07, // 0b 0000 0111 = 7
	0x7F, // 0b 0111 1111 = 8
	0x6F  // 0b 0110 1111 = 9
};

void initDisplay()
{
	GPIO_InitTypeDef display_port;
	
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	display_port.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | 
										 GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
	display_port.Mode = GPIO_MODE_OUTPUT_PP;
	display_port.Speed = GPIO_SPEED_FREQ_LOW;
	display_port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOC, &display_port);
}

void updateDisplay()
{
	clearDisplay();
	GPIOC->ODR |= floorTable[getFloor()];
}

void clearDisplay()
{
	GPIOC->ODR &= 0xFF80;
}
