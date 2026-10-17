#include "buzz.h"
#include "delay.h"

void Buzz_Times( unsigned char times)

	{
		unsigned char i=0;
	  for(i=0;i<times;i++)
	  {	
		  buzz=0;
		  delay(10000);
		  buzz=1;
		  delay(10000);
	  }
	}
