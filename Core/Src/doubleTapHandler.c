#include "doubleTapHandler.h"
#include "main.h"
#include "tim.h"
#include <stdio.h>

volatile tapActionEnum tapAction = IDLE;
uint16_t minTappingTicks = 500;

void setTappingTerm(uint16_t timeMs)
{
	TIM6->ARR = 50000000 / (5000 * 1000) * timeMs;
}

void setMinTappingTerm(uint16_t timeMs)
{
	minTappingTicks = 50000000 / (5000 * 1000) * timeMs;
}


void resetTimer(void)
{
	TIM6->CNT = 0;
}

void setTapState(void)
{	
	if (tapAction == IDLE) {
		tapAction = UP;
		TIM6->CNT = 0; // Reset counter value
		HAL_TIM_Base_Start_IT(&htim6); // Can count up to 6.5535 s but will overflow at TAPPINGTERM ms
	}
	else if (tapAction == UP)
	{
		if (TIM6->CNT < minTappingTicks) return;
		else tapAction = DOWN;
	}
}

