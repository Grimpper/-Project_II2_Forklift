#ifndef __TIMERHANDLER_H
#define __TIMERHANDLER_H

#include <stdint.h>

void initTimer(void);

void resetTickCount(void);
uint32_t timerValueMs(void);
uint32_t timerElapsedTimeMs(uint32_t mark);

#endif
