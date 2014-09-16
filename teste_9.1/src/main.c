/*
===============================================================================
 Name        : teste_9.1.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "UART0_Lib.h"

// TODO: insert other definitions and declarations here

int main(void) {

    // TODO: insert code here
	SystemInit();
	Config_UART0_RS232(19200);

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}
