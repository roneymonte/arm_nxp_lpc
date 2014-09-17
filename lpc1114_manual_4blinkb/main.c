/*
  Este sistema dispoe de 4 LEDs conectados as portas 0_7, 0_8, 0_9, 1_5 e 1_8.
  O objetivo eh testar um "pisca-led" em pares independentes, um oscilando
  dentro de um contador com 100.000 ciclos (aprox 1,3 seg) e o outro par
  oscilando na interrupcao do SysTick com contador de 999 (1hz no SYST_RVR),
  dentro de um ambiente onde o clock interno (IRC de 12mhz) foi utilizado com
  divisor de 12 (SYSAHBCLKDIV=12) gerando um MainClock dividdo de 1mhz
  (1.000.000)

  por Roney Monte em 16/Setembro/2014
  utilizando o LPC1114FN28/102

*/

#include "lpc111x.h"

/*----------------------------------------*/

void delay(unsigned int dly);
void initSysTick();
void Config();
void apagaTodos();
void ligaTodos();

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
	// 12mhz/12 = 1mhz = 1.000.000 / 1.000 -1 = 1.000 -1 = 999 (para milisegundos)
	// 1.000.000 / 1 = 1.000.000 - 1 = 999.999; (1 segundo)
	SYST_RVR=999999;

	//When enabled, count down from SysTick Current Value 
	//Register (SYST_CVR) to zero, and reload SysTick Reload 
	//Value Register (SYST_RVR), then continue decrement
	// CVR fica no Stack + 8 bytes = Systick Current Value (RW)
	SYST_CVR=1;

	enable_interrupts();	// esta funcao esta em LPC11xx.h
}

void SysTick ()
{	
	GPIO0DATA |= (1<<9); 	// sinalizacao de interrupcao SysTick
	static short int contador = 1;

	switch (contador)
	{
		case 1: {
				GPIO0DATA |=  (1<<8);
				GPIO0DATA &= ~(1<<7);
				//GPIO1DATA &= ~(1<<8);
				//GPIO1DATA &= ~(1<<5);
			break;
			}

		case 2: {
				GPIO0DATA &= ~(1<<8);
				GPIO0DATA |=  (1<<7);
				//GPIO1DATA &= ~(1<<8);
				//GPIO1DATA &= ~(1<<5);
			break;
			}
		/*---------------------------------*/
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
	if (contador>2) contador=1;

	delay(500); GPIO0DATA &= ~(1<<9); // desliga sinalizacao de interrupcao
}

void Config()
{
	SYSAHBCLKCTRL |= (1<<6) | (1<<16);	// Turn on clock for GPIO and IOCON 

	IOCON_PIO1_8=(0<<8);
	IOCON_PIO0_1=0x1;			// configura pino 0_1 como CLKOUT
	/* o pino 0_1 serve simplesmente para se ligar o Osciloscopio para aferir */

	// Coloque estas portas como saida Outputs
	GPIO0DIR |= (1<<9)|(1<<8)|(1<<7);	// Porta 0_9 0_8 0_7 como saida output
	GPIO1DIR |= (1<<8)|(1<<5);		// Porta 1_8 1_5 como saida output
	
	ligaTodos();				// liga todos LEDs para testar
}

/*----------------------------------------*/

int main()
{	
	Config();

	delay(300000);
	apagaTodos();				// apaga todos LEDs para testar
	delay(300000);
	
	initSysTick();	// inicia a interrupcao por tempo do SysTick

	delay(1000000);	// neste delay de quase 13 seg, mostra apenas o pisca-led systick

	while(1) 
	{	// aqui o pisca-led de tempo decrementado (implementacao ruim)
		GPIO1DATA &= ~(1<<8);
		GPIO1DATA |=  (1<<5);
		delay(100000);	// 100 mil decrementos ~ 1,3 segundo

		// aqui o pisca-led de tempo decrementado (implementacao ruim)
		GPIO1DATA |=  (1<<8);
		GPIO1DATA &= ~(1<<5);
		delay(100000); // 100 mil decrementos ~ 1,3 segundo
	}    
}

void apagaTodos ()
{
	GPIO0DATA &= ~((1<<9)|(1<<8)|(1<<7));
	GPIO1DATA &= ~((1<<8)|(1<<5));
}

void ligaTodos()
{
	GPIO0DATA |= (1<<9)|(1<<8)|(1<<7);
	GPIO1DATA |= (1<<8)|(1<<5);
}
