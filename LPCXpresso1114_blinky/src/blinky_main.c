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
#include "clkconfig.h"
#include "gpio.h"

// LPCXpresso processor card LED
#define LED_PORT 0		// Port for led
#define LED_BIT 7		// Bit on port for led
#define LED_ON 1		// Level to set port to turn on led
#define LED_OFF 0		// Level to set port to turn off led

extern volatile uint32_t timer16_0_counter;

int main (void) {

  GPIOInit();

  // Initialize Timer16_0 to tick at rate of 1/2000th of second.
	// Note that as this is a 16 bit timer, the maximum count we can
	// load into timer is 0xFFFF, or 65535. Default clock speed
	// set up by CMSIS SystemInit function - SystemCoreClock - is
	// 48MHz or 48000000 Hz. Dividing this by 2000 is 24000 which is
	// within appropriate timer16 maximum. This could be extended
	// if timer routine extended to make use of Prescale Counter register
	// Note by default LPC_SYSCON->SYSAHBCLKDIV is 1.
  init_timer16(0, (SystemCoreClock/LPC_SYSCON->SYSAHBCLKDIV)/2000 );

  // Initialize counter that counts Timer16_0 ticks
  timer16_0_counter = 0;

  //Enable Timer16_0
  enable_timer16(0);

  // Set port for LED to output
  GPIOSetDir( LED_PORT, LED_BIT, 1 );

  while (1)                                /* Loop forever */
  {

	// LED is on for 1st half-second
	if ( (timer16_0_counter > 0) && (timer16_0_counter <= 1000) )
	{
	  GPIOSetValue( LED_PORT, LED_BIT, LED_OFF );
	}
	// LED is off for 2nd half-second
	if ( (timer16_0_counter > 1000) && (timer16_0_counter <= 2000) )
	{
		GPIOSetValue( LED_PORT, LED_BIT, LED_ON );
	}
	// Reset counter
	else if ( timer16_0_counter > 2000 )
	{
	  timer16_0_counter = 0;
	}
  }
}
