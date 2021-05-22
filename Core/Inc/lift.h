#ifndef __LIFT_H
#define __LIFT_H

#define INITIAL_FLOOR 0 

void lift_Init(void);
void lift_Up (void);
void lift_Down(void);

void update_floor(int);
int get_floor (void);
#endif
