#include <reg52.h>
#include <intrins.h>
#include <stdio.h>
#include <math.h>
#include "float_operations.h"
#include "delay.h"

float value;

 float float_calculation1(float y,float increment, float decrement) 
	{
   if(key1==0)
			    {
					 delay(5);
            if(key1==0)
						{
						 y += increment;
             while(key1==0); 
						}
					}
		 if(key2==0)
			   {
					 delay(5);
					 if(key2==0)
					 {
						 y -= decrement;
						 while(key2==0); 
					 }
				 }
				 
				value=y;
			 return value;	
  }
float float_calculation2(float y,float increment, float decrement) 
	{
   if(key3==0)
			    {
					 delay(5);
            if(key3==0)
						{
						 y += increment;
             while(key3==0); 
						}
					}
		 if(key4==0)
			   {
					 delay(5);
					 if(key4==0)
					 {
						 y -= decrement;
						 while(key4==0); 
					 }
				 }
				 
				value=y;
			 return value;	
  }
 void float_To_String(float x, char *str_1)
  { 
		 int x_int = (int)x;       
     int x_dec = (int)((x - x_int) * 10); 
		 str_1[0] = x_int/10 + '0';   
     str_1[1] = x_int%10 + '0';   
     str_1[2] = '.';                 
     str_1[3] = x_dec + '0';      
     str_1[4] = ' ';                 
     str_1[5] = 'C';                 
     str_1[6] = '\0';  
   }