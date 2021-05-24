#ifndef __WEIGHT_H
#define __WEIGHT_H
#include <stm32f4xx.h>
void initOverweightPin(void);
void overWeightRutine(void);
typedef enum{
	NO,
	YES
} overWeightEnum;

#endif
