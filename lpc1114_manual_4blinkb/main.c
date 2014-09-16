#include "lpc111x.h"

/*----------------------------------------*/

void delay(unsigned int dly);
void initSysTick();
void Config();

/*----------------------------------------*/

void delay(unsigned int dly)
{
  while (dly--);
}

void initSysTick()
{
	// System Timer fica em 0xE000E010 no Stack de memoria
	// SysTick: 24-bit clear-on-write, decrementing, wrap-on-zero counter

	// Inicio do Stack chamado System Timer (SYST)
	// CSR Systick Control and Status (RW)
	/*
	0 ENABLE System Tick counter enable. When 1, the counter is enabled. 
	When 0, the counter is disabled.

	1 TICKINT System Tick interrupt enable. When 1, the System Tick interrupt 
	is enabled. When 0, the System Tick interrupt is disabled. When 
	enabled, the interrupt is generatedwhen the System Tick counter 
	counts down to 0.

	2 CLKSOURCE System Tick clock source selection. When 1, the system clock 
	(CPU) clock is selected. When 0, the system clock/2 is selected 
	as the reference clock.
	*/
	SYST_CSR |= (1<<0) | (1<<1) | (1<<2);	// habilita systicks e interrupcoes
	// 48mhz/48= 1.000.000 ; divisor = 1000000/1000 = 1000 = 1 mhz
	// 1 milhao de ciclos por segundo = 1 mhz

	//SYST_RVR =0, timer=0. (disable timer even if timer enable)
	// RVR fica no Stack + 4 bytes = Systick Reload Value (RW)
	// 1 ciclo de cada mil do mhz = 1 khz = 1000 - 1
	// 1000 ciclos de cada mil do mhz = 1 hertz = 1 seg = 1000 - 1000
	SYST_RVR=99999999;

	//When enabled, count down from SysTick Current Value 
	//Register (SYST_CVR) to zero, and reload SysTick Reload 
	//Value Register (SYST_RVR), then continue decrement
	// CVR fica no Stack + 8 bytes = Systick Current Value (RW)
	SYST_CVR=1;

	enable_interrupts();	// esta funcao esta em LPC11xx.h
}

void SysTick ()
{
	static short int contador = 1;

	switch (contador)
	{
		case 1: {
				GPIO0DATA |=  (1<<8);
				GPIO0DATA &= ~(1<<7);
				GPIO1DATA &= ~(1<<8);
				GPIO1DATA &= ~(1<<5);
			break;
			}

		case 2: {
				GPIO0DATA &= ~(1<<8);
				GPIO0DATA |=  (1<<7);
				GPIO1DATA &= ~(1<<8);
				GPIO1DATA &= ~(1<<5);
			break;
			}

		case 3: {
				GPIO0DATA &= ~(1<<8);
				GPIO0DATA &= ~(1<<7);
				GPIO1DATA |=  (1<<8);
				GPIO1DATA &= ~(1<<5);
			break;
			}

		case 4: {
				GPIO0DATA &= ~(1<<8);
				GPIO0DATA &= ~(1<<7);
				GPIO1DATA &= ~(1<<8);
				GPIO1DATA |=  (1<<5);
			break;
			}
	}

	contador++;
	if (contador>4) contador=1;

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
	delay(1000000);
	delay(1000000);
	delay(1000000);
	delay(1000000);
	delay(1000000);
	delay(1000000);
	delay(1000000);
	delay(1000000);
	GPIO0DATA &= ~((1<<8)|(1<<7));
	GPIO1DATA &= ~((1<<8)|(1<<5));
	delay(1000000);
	delay(1000000);
	delay(1000000);
	delay(1000000);
	delay(1000000);
	delay(1000000);
	delay(1000000);
	delay(1000000);
	initSysTick();
	
	while(1) 
	{

		delay(1000000);

		delay(1000000);

		delay(1000000);

		delay(1000000);
		
	}    
}



