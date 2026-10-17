#ifndef _DS18b20_H  
#define _DS18b20_H

#include <reg52.h>

extern float temperature;

	
sbit DQ=P1^0;

bit DS18B20_Init();
void writebyte(unsigned char dat);
unsigned char readbyte();   
float DS18B20_GetTemp(); 
void temperature_To_String(float temperature, char *temperature_str);

#endif