#include "doubleTapHandler.h"
#include "timerHandler.h"

uint16_t tapState = 0;
uint32_t firstTapTime = 0;
uint32_t TAPPINGTERM = 200;

void setTappingTerm(uint32_t timeMs)
{
	TAPPINGTERM = timeMs;
}

void setTapState(void)
{	
	if (tapState == 1 && timerElapsedTimeMs(firstTapTime) < TAPPINGTERM) tapState = 2;
	tapState = 1;
	firstTapTime = timerValue();
}

