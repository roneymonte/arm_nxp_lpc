/*
===============================================================================
 Name        : HelloWorld_LPC1114FN.c
 Author      : Roney Monte
 Version     : 0.1
 Copyright   : GPL
 Description : First Breadboard Project using ARM Cortex M0 (LPC1114FN28/102)
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC11xx.h"
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}
