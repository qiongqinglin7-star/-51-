#ifndef _L298N_H  
#define _L298N_H

#include <reg52.h>

sbit IN1=P2^3;
sbit IN2=P2^4;

void motor_run1();
void motor_run2();
void motor_stop();

#endif