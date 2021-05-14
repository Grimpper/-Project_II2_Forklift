#ifndef __TIMERHANDLER_H
#define __TIMERHANDLER_H

#include <stdint.h>

void initTimer(void);
uint32_t timerValue(void);
uint32_t timerElapsedTime(uint32_t mark);

#endif
