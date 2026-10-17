#include <reg52.h>

#include "L298N.h"

void motor_run1()
  {
   IN1=1;
	 IN2=0;
  }
void motor_run2()
  {
   IN1=0;
	 IN2=1;
  }
void motor_stop()
	 {
   IN1=0;
	 IN2=0;
   }