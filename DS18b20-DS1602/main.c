#include <reg52.h>
#include <intrins.h>
#include <stdio.h>
#include <math.h>
#include "DS18b20.h"
#include "delay.h"
#include "DS1602.h"
#include "float_operations.h"
#include "buzz.h"
#include "L298N.h"

 void main()
	  {
			float temp_set1=20.0;
			float temp_set2=25.0;
			float temperature_realtime;
			char  temp_str[16];
			char  tempset1_str[16];
			char  tempset2_str[16];
			LCD1602_init();
			while(1)
			{	
				temperature_realtime =DS18B20_GetTemp();
				temperature_To_String(temperature_realtime, temp_str);
	    		temp_set1=float_calculation1(temp_set1,1.0f, 1.0f);
				temp_set2=float_calculation2(temp_set2,1.0f, 1.0f);		 
				float_To_String(temp_set1,  tempset1_str);
				float_To_String(temp_set2,  tempset2_str);
			LCD1602_dis_1(1, 0, "Set:");
			LCD1602_dis_1(2, 0, "Env:");
			LCD1602_display_2(0x84, tempset1_str, 0, 6);
			LCD1602_display_2(0x89, tempset2_str, 0, 6);	
			LCD1602_display_2(0xC4, temp_str, 0, 6);
			if(temperature_realtime<temp_set1||temperature_realtime>temp_set2)
			{
			 Buzz_Times(10);
			 if(temperature_realtime<temp_set1)
			 {motor_run1();}
			 if(temperature_realtime>temp_set2)
			 {motor_run2();}
			}
			else
			{
			 motor_stop();	
			}
			}
	 }