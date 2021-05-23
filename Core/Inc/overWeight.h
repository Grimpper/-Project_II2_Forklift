#ifndef __WEIGHT_H
#define __WEIGHT_H
#include <stm32f4xx.h>

void overWeightCondition(void);
void weightInit(void);
void adcInit(void);
int32_t readWeight(void);
void overWeightRutine(void);
typedef enum{
	NO,
	YES
} overWeightEnum;
#endif