#include<reg52.h>
#include <intrins.h>
#include "delay.h"
#include "DS1602.h"


void delay15ms() //11.0592MHz
{
  unsigned char i,j;
  i=27;
  j=226;
   do
    {
   while(--j);
    }
   while(--i);
 }

 void delay5ms() //11.0592MHz
{
  unsigned char i,j;
  i=9;
  j=244;
  do
  {
   while(--j);
   }
   while(--i);
 }
void check_busy()
 {
	 char i = 0;
	 
  char tmp=0x80;
  DataPort=0xFF;
  while(tmp&0x80)
   {
   RS=0;
   RW=1;
   EN=0;
   _nop_();
   EN=1;
   _nop_();
   _nop_();
   tmp=DataPort;
   EN=0;
   _nop_();
		 
		 i++;
		 if(i >100)
			 break;
   }
  }

void write_cmd(char cmd)
  {
  check_busy();
	RS=0;
	RW=0;
	EN=0;
	_nop_();
	DataPort=cmd;
	_nop_();
	EN=1;
	_nop_();
	_nop_();
	EN=0;
	_nop_();
  }

 void write_data(char datashow)
  {
  check_busy();
	RS=1;
	RW=0;
	EN=0;
	_nop_();
	DataPort=datashow;
	_nop_();
	EN=1;
	_nop_();
  _nop_();
	EN=0;
	_nop_();
  }

 void LCD1602_init()
  {
  delay15ms();
  write_cmd(0x38);//不检测忙信号
  delay5ms();
  write_cmd(0x38);//显示模式设置
  write_cmd(0x08);// 显示关闭
  write_cmd(0x01);//  显示清屏
  write_cmd(0x06);// 显示光标移动设置
  write_cmd(0x0c);// 显示开及光标设置
  }
void LCD1602_dis_1(unsigned char row, unsigned char column,  char *str)
	 {
		 
		 switch (row)
		 {
			 case 1:
			 write_cmd(0x80+column);
			 while (*str != '\0') 
				 {
          write_data(*str);
          str++;
         }
			 break;
			 case 2:
			 write_cmd(0x80+0x40+column);
			   	
			 while (*str != '\0') 
				 {
          write_data(*str);
          str++;
         }  
			 break;
		 }
	 }
	 void LCD1602_display_2(unsigned char addr,unsigned char* pointer,unsigned char index,unsigned char num)
  {
  	unsigned char i;
    check_busy();	
  	write_cmd(addr);	
  	for(i=0;i<num;i++)		
  	{
		 check_busy();	
     write_data(pointer[index+i]);   
  	}
	}