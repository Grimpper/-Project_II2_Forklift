#include "timerHandler.h"
#include "stm32f4xx_hal.h"

volatile uint32_t ticksCount = 0;

void initTimer(void)
{	
	HAL_SYSTICK_Config(SystemCoreClock * 0.001);
}

uint32_t timerValueMs(void)
{
	return ticksCount;
}

uint32_t timerElapsedTime(uint32_t mark)
{
	return timerValueMs() - mark;
}
