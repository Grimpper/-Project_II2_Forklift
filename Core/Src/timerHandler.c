#include "timerHandler.h"
#include "stm32f4xx_hal.h"

volatile uint32_t tickCount = 0;

void initTimer(void)
{	
	HAL_SYSTICK_Config(SystemCoreClock * 0.001);
}

void resetTickCount(void)
{
	tickCount = 0;
}

uint32_t timerValueMs(void)
{
	return tickCount;
}

uint32_t timerElapsedTimeMs(uint32_t mark)
{
	return timerValueMs() - mark;
}
