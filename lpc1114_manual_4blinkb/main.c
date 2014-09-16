#include "lpc111x.h"

/*----------------------------------------*/

void delay(unsigned int dly);
void Config();

/*----------------------------------------*/

void delay(unsigned int dly)
{
  while (dly--);
}

void Config()
{
	SYSAHBCLKCTRL |= (1<<6) | (1<<16);	// Turn on clock for GPIO and IOCON 

	IOCON_PIO1_8=(0<<8);

	// Make all of bits outputs
	GPIO0DIR |= (1<<8)|(1<<7);		// Porta 0_8 e 0_7 como saida output
	GPIO1DIR |= (1<<8)|(1<<5);		// Porta 1_8 e 1_5 como saida output

	// Turn off (make high) all
	GPIO0DATA |= (1<<8)|(1<<7);
	GPIO1DATA |= (1<<8)|(1<<5);
}

/*----------------------------------------*/

int main()
{	
	Config();
	
	while(1) 
	{

		GPIO0DATA |=  (1<<8);
		GPIO0DATA &= ~(1<<7);
		GPIO1DATA &= ~(1<<8);
		GPIO1DATA &= ~(1<<5);
		delay(1000000);

		GPIO0DATA &= ~(1<<8);
		GPIO0DATA |=  (1<<7);
		GPIO1DATA &= ~(1<<8);
		GPIO1DATA &= ~(1<<5);
		delay(1000000);

		GPIO0DATA &= ~(1<<8);
		GPIO0DATA &= ~(1<<7);
		GPIO1DATA |=  (1<<8);
		GPIO1DATA &= ~(1<<5);
		delay(1000000);

		GPIO0DATA &= ~(1<<8);
		GPIO0DATA &= ~(1<<7);
		GPIO1DATA &= ~(1<<8);
		GPIO1DATA |=  (1<<5);
		delay(1000000);
		
	}    
}



