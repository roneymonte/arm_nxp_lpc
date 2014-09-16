/*
===============================================================================
 Name        : helloWorld_piscaLed.c
 Author      : Roney
 Version     :
 Copyright   : GPL
 Description : main definition
===============================================================================

Baseado no exemplo do Livro Miyadaira, capitulo 8.1 na pagina 249
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "SysTick_Lib.h"

// TODO: insert other definitions and declarations here
//#define C

int main(void) {

    // TODO: insert code here
	SystemInit();	// inicia o sistema e clock conforme "system_LPC17xx.c" no CMSIS
	Config_SysTick_ms();	// fiz pequena modificacao na biblioteca do Miyadaira para suportar milisegundos

	LPC_PINCON->PINSEL1	&=	~(0b11<<12);	// configura pino P0.22 como GPIO
	LPC_GPIO0->FIODIR 	|=	1<<22;			// configura pino P0.22 como saida

	LPC_GPIO0->FIOSET |=	1<<22;
	LPC_GPIO0->FIOCLR |=	1<<22;

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;

        LPC_GPIO0->FIOPIN |=	1<<22;		// liga o pino 0.22
        delay_ms(1000);					// 1/2 seg pausa

        LPC_GPIO0->FIOPIN &=	~(1<<22);	// desliga o pino 0.22
        delay_ms(1000);					// 1/2 seg pausa


        LPC_GPIO0->FIOSET |=	1<<22;		// liga (SET) o pino 0.22
        delay_ms(2000);					// 1 seg pausa

        LPC_GPIO0->FIOCLR |=	1<<22;		// desliga (CLR) o pino 0.22
        delay_ms(2000);					// 1 seg pausa


        //delay_ms(1000);
        for(i=0;i<20;i++)
        {
            LPC_GPIO0->FIOSET |=	1<<22;		// liga (SET) o pino 0.22
            delay_ms(50);					// 1 seg pausa
            LPC_GPIO0->FIOCLR |=	1<<22;		// desliga (CLR) o pino 0.22
            delay_ms(50);					// 1 seg pausa
        }
        delay_ms(1000);

    }
    return 0 ;
}
