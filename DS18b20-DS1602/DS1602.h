#ifndef __DS1602__H
#define __DS1602__H

#include "reg52.h"

#define DataPort P0
sbit RS= P2^5;     
sbit RW= P2^6;     
sbit EN= P2^7; 

void delay15ms();
void delay5ms();
void check_busy();
void write_cmd(char cmd);
void write_data(char datashow);
void LCD1602_init();
void LCD1602_dis_1(char row, char column, char *string);
void LCD1602_display_2(unsigned char addr,unsigned char* pointer,unsigned char index,unsigned char num);

#endif