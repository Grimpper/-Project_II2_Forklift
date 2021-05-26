#ifndef __SAFETY_H
#define __SAFETY_H

#define emergencyLightPins GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15

void initSafetyPins(void);
void handleEmergency(void);
void lockLifter(void);
void unlockLifter(void);
void overweightRoutine(void);

#endif
