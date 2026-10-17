#ifndef _float_operations_H  
#define _float_operations_H

#include <reg52.h>

sbit key1=P1^1;
sbit key2=P1^2;
sbit key3=P1^6;
sbit key4=P1^7;

extern float value;

float float_calculation1(float y,float increment,  float decrement);
float float_calculation2(float y,float increment,  float decrement);  
void float_To_String(float x, char *str_1);

#endif