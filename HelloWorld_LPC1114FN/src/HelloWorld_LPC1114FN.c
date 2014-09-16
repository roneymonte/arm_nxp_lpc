/*
===============================================================================
 Name        : HelloWorld_LPC1114FN.c
 Author      : Roney Monte
 Version     : 0.1
 Copyright   : GPL
 Description : First Breadboard Project using ARM Cortex M0 (LPC1114FN28/102)
===============================================================================
*/

//#ifdef __USE_CMSIS
#include "LPC11xx.h"
//#endif

//#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

    // TODO: insert code here
	SystemInit();

	/* Enable AHB clock to the GPIO domain. */
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);


	//SystemCoreClockUpdate();

	unsigned int contador;

	//LPC_SYSCON->SYSPLLCLKSEL = SYSPLLCLKSEL_SEL_IRC; // foi definido dentro do SystemInit.
	//LPC_SYSCON->
	//LPC_GPIO0->
	//LPC_GPIO0->DIR  = 0x0FFF;	// todos pinos como output
	LPC_GPIO0->DIR	|= (1<<8);	// habilita a porta 0_8 (pino 1 do LPC1114) como saida (1)
	//LPC_GPIO0->DIR |=  (1<<7);
	//LPC_GPIO1->DIR |=  (1<<8);

	//LPC_GPIO0->DATA = 0x0000;	// pinos em low
	LPC_GPIO0->DATA &= ~(1<<8);	// coloca a porta 0_8 como low
	//LPC_GPIO0->DATA &= ~(1<<7);
	//LPC_GPIO1->DATA &= ~(1<<8);

	//LPC_GPIO0->MASKED_ACCESS[(1<<8)]=(1<<8);	// seta o PI0.8 como high
	//LPC_GPIO0->DATA = 0x0FFF;	// pinos em high
	//LPC_GPIO0->MASKED_ACCESS[(1<<8)]=0;			// limpa o PI0.8 como low
	//SET_GPIO(0,8)=0;

	//LPC_IOCON->PIO0_8 = 0;	// configura o pino 0_8 como saida

	//LPC_GPIO0->DATA |= (1<<7);
	//LPC_GPIO1->DATA |= (1<<8);


    // Force the counter to be placed into memory
    //volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        //i++ ;

        LPC_GPIO0->DATA |= (1<<8);	// liga o led no pino 0_8
        //LPC_GPIO0->DATA &= ~(1<<7);
        //LPC_GPIO1->DATA &= ~(1<<8);
        for(contador=0; contador<2000000;contador++);

        LPC_GPIO0->DATA &= ~(1<<8);	// desliga o led no pino 0_8
        //LPC_GPIO0->DATA |= (1<<7);
        //LPC_GPIO1->DATA |= (1<<8);
        for(contador=0; contador<2000000;contador++);

    }
    return 0 ;
}
