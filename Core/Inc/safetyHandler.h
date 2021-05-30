#ifndef __SAFETY_H
#define __SAFETY_H

#define emergencyLightPins GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15

#include <stdint.h>

struct Emergency {
   uint8_t  stop;
   uint8_t  door;
   uint8_t  overweight;
};

void initSafetyPins(void);
void handleEmergency(void);
void lockLifter(void);
void unlockLifter(void);
void overweightRoutine(void);

#endif
