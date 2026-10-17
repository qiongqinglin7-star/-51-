#include <reg52.h>
#include <stdio.h>
#include <math.h>
#include <intrins.h>
#include "delay.h"
#include "DS18b20.h"
 
float temperature;

bit DS18B20_Init()    
  {
   bit  flag=0;
   DQ=1;
   delay(2);
   DQ=0;
   delay(75);
   DQ=1;
   delay(10);
   flag=DQ;
   delay(20);
   return flag;
  }
  void writebyte(unsigned char dat)    
  {    
    unsigned char n=0;
    for(n=0;n<8;n++)
    {
     DQ=0;
     DQ=dat&0x01;
     delay(5);
     DQ=1;
     dat>>=1;
     }
   }
  unsigned char readbyte()    
  {   
   unsigned char n=0,gdata=0;
   for(n=0;n<8;n++)
    {
     DQ=0;
     gdata=gdata>>1;
     DQ=1;
     if(DQ)
     { 
      gdata=gdata|0x80;
     }
     delay(4); 	   
    }
  return gdata; 
  }
	float DS18B20_GetTemp() 
  {
    unsigned char tempL,tempH;
    int temp;
    DS18B20_Init();
    writebyte(0xcc);
    writebyte(0x44);
    delay(5);
    DS18B20_Init();
    writebyte(0xcc);
    writebyte(0xbe);
    delay(5);
    tempL=readbyte();
    tempH=readbyte();
    temp=(tempH<<8)+tempL;
	  if(temp & 0x8000)
      {
        temp=~temp+1;
        temperature=temp*(-0.0625);
      }
    else
      {
        temperature = temp*0.0625;
      }
 
    return temperature;
   }
  void temperature_To_String(float temperature, char *str)
	  {

		 int temperature_int = (int)temperature;       
     int temperature_dec = (int)((temperature - temperature_int) * 10); 
		 str[0] =temperature_int/10 + '0';   
     str[1] =temperature_int%10 + '0';   
     str[2] = '.';                 
     str[3] =temperature_dec + '0';      
     str[4] =' ';                 
     str[5] = 'C';                 
     str[6] = '\0';  
			
    }
	 