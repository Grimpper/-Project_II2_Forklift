#include "gpio.h"
#include "lift.h"
#include "display.h"

const uint8_t floorTable[10] = {
	0x40,	// 0b 0100 0000 = 0
	0x79, // 0b 0111 1001 = 1
	0x24, // 0b 0010 0100 = 2
	0x30, // 0b 0011 0000 = 3
	0x19, // 0b 0001 1001 = 4
	0x12, // 0b 0001 0010 = 5
	0x02, // 0b 0000 0010 = 6
	0x78, // 0b 0111 1000 = 7
	0x00, // 0b 0000 0000 = 8
	0x18  // 0b 0001 1000 = 9
};

void initDisplay(void)
{
	GPIO_InitTypeDef display_port;
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	display_port.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
	display_port.Mode = GPIO_MODE_OUTPUT_PP;
	display_port.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOC, &display_port);
}

void showDisplay(void)
{
	GPIOC->ODR = floorTable[get_floor()];
}

void clearDisplay(void)
{
	GPIOC->ODR &= 0xFF80;
}
