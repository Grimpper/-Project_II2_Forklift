#ifndef __DOUBLETAPHANDLER_H
#define __DOUBLETAPHANDLER_H

#include <stdint.h>

typedef enum {
	IDLE,
	DOWN,
	UP,
	WAITING
} tapActionEnum;

typedef enum{
	CLOSE,
	OPEN
} latchStateEnum;

void setTappingTerm(uint16_t timeMs);
void setMinTappingTerm(uint16_t timeMs);
void resetTimer(void);
void setTapState(void);

#endif
