#ifndef __SAFETY_H
#define __SAFETY_H

void initSafetyPins(void);
void emergencyStop(void);
void lockLifter(void);
void unlockLifter(void);
void overWeightRutine(void);
typedef enum{
	NO,
	YES
} overWeightEnum;


#endif
