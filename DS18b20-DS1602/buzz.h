#ifndef _buzz_H
#define _buzz_H
#include <reg52.h>

sbit buzz=P2^0;

void Buzz_Times( unsigned char times);

#endif