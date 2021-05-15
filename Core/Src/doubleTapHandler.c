#include "doubleTapHandler.h"
#include "main.h"
#include "tim.h"
#include <stdio.h>

volatile uint16_t tapState = 0;
uint16_t minTappingTerm = 500 * (uint16_t)50000000 / 5000;

void setTappingTerm(uint32_t timeMs)
{
	TIM6->ARR = 50000000 / 500 * 0.2;
}

void setTapState(void)
{	
	if (tapState == 0) {
		tapState = 1;
		TIM6->CNT = 0; // Reset counter value
		HAL_TIM_Base_Start_IT(&htim6); // Can count up to 655.35 ms but will overflow at 200 ms
	}
	else if (tapState == 1)
	{
		if (TIM6->CNT < minTappingTerm) return;
		else tapState = 2;
	}
	
	/*
	if (tapState == 1 && TIM6->CNT > minTappingTerm) tapState = 2;
	else if (tapState == 0 || TIM6->CNT > minTappingTerm)
	{
		tapState = 1;
		TIM6->CNT = 0; // Reset counter value
		HAL_TIM_Base_Start_IT(&htim6); // Can count up to 655.35 ms but will overflow at 200 ms
	}*/
}

