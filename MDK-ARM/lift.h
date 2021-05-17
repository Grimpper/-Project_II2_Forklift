#ifndef __LIFT_H
#define __LIFT_H

#define INITIAL_FLOOR 0 

void lift_Init(void);
void pwm_switch_Init(void);
void motor_stop(void);
	
void lift_Up (void);
void lift_Down(void);

void update_floor(int);
int get_floor (void);
#endif
