//*****************************************************************************
//   +--+
//   | ++----+
//   +-++    |
//     |     |
//   +-+--+  |
//   | +--+--+
//   +----+    Copyright (c) 2010 Code Red Technologies Ltd.
//
// LED flashing Timer16 application for LPCXPresso1114 board
//
// Software License Agreement
//
// The software is owned by Code Red Technologies and/or its suppliers, and is
// protected under applicable copyright laws.  All rights are reserved.  Any
// use in violation of the foregoing restrictions may subject the user to criminal
// sanctions under applicable laws, as well as to civil liability for the breach
// of the terms and conditions of this license.
//
// THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
// OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
// USE OF THIS SOFTWARE FOR COMMERCIAL DEVELOPMENT AND/OR EDUCATION IS SUBJECT
// TO A CURRENT END USER LICENSE AGREEMENT (COMMERCIAL OR EDUCATIONAL) WITH
// CODE RED TECHNOLOGIES LTD.
//
//*****************************************************************************
#include "LPC11xx.h"                        /* LPC11xx definitions */
#include "timer16.h"
#include "small_gpio.h"

// LPCXpresso processor card LED
#define LED_PORT 0		// Port for led
#define LED_BIT 7		// Bit on port for led
#define LED_ON 1		// Level to set port to turn on led
#define LED_OFF 0		// Level to set port to turn off led

extern volatile uint32_t timer16_0_counter;

static void InitPLLIRC48(void)
{
    // Set PLL frequency= x4 = 48 MHz from 12 MHz IRC
    LPC_SYSCON->SYSPLLCTRL = 0x3 + (0x2<<5);

    // Turn on PLL
    LPC_SYSCON->PDRUNCFG &= ~(1<<7);

    // Wait for PLL lock
    while(!(LPC_SYSCON->SYSPLLSTAT&1))
        ;

    // Switch main clock from IRC to PLLOUT
    LPC_SYSCON->MAINCLKSEL = 3;
    LPC_SYSCON->MAINCLKUEN = 1; LPC_SYSCON->MAINCLKUEN = 0;
}

static void setupTimer16(uint16_t TimerInterval)
{
	timer16_0_counter = 0;

	LPC_TMR16B0->TCR |= 0x2; //Assert Timer Reset
	LPC_TMR16B0->TCR &= ~0x2; //De-assert Timer Reset

	LPC_TMR16B0->IR = 0xF;

	LPC_TMR16B0->MR0 = TimerInterval;
	LPC_TMR16B0->MCR = 0x3;				/* Interrupt and Reset on MR0 */

	/* Enable the TIMER0 Interrupt */
	NVIC_EnableIRQ(TIMER_16_0_IRQn);

	//Start timer running
	LPC_TMR16B0->TCR |= 1;

}

int main (void)
{
	InitPLLIRC48();
	LPC_SYSCON->SYSAHBCLKCTRL |= ( (1<<6) | (1<<7) | (1<<16) );

	// Initialize Timer16_0 to tick at rate of 1/2000th of second.
	// Note that as this is a 16 bit timer, the maximum count we can
	// load into timer is 0xFFFF, or 65535. Default clock speed
	// set up by CMSIS SystemInit function - SystemCoreClock - is
	// 48MHz or 48000000 Hz. Dividing this by 2000 is 24000 which is
	// within appropriate timer16 maximum. This could be extended
	// if timer routine extended to make use of Prescale Counter register
	// Note by default LPC_SYSCON->SYSAHBCLKDIV is 1.

	//init_timer16(0, (SystemCoreClock/LPC_SYSCON->SYSAHBCLKDIV)/2000 ); //refers to SystemCoreClock, does integer division
	//init_timer16(0, 48000000/2000 ); //Uses constant, --gc-sections remove SystemCoreClock and integer division routines.

	//Blinking is toggled via main, rather than using MAT registers in timer, so this routine is very lean.
	//However, code size can be reduced further if a PCB with the LED tied to the timer MATx pin is used
	//in conjunction with the timer's pin toggling feature.
	setupTimer16(24000);

	// Set port for LED to output
	SetupGPIO(LED_PORT,LED_BIT,GPIO_DIR_OUTPUT,GPIO_FUNC_MASK,GPIO_FUNC_0);


	while (1)
	{
		//more compact code than if/else structure
		//and only updates LED at two particular count values.
		switch ( timer16_0_counter )
		{
		case 2000:
			timer16_0_counter = 0;
		case 0:
			ClrGPIOBit(LED_PORT, LED_BIT);
			break;

		case 1000:
			SetGPIOBit(LED_PORT, LED_BIT);
			break;

		//If an LED update isn't required, go to sleep (or do something more useful)
		default:
			__WFI();
			break;
		}
	}
}
