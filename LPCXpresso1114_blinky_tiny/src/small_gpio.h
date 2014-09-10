/*
===============================================================================
 File small_gpio.h: Small gpio for LPC111x and LPC134x
 Project DebugTips_1114: Demonstration of debugging techniques for LPCXpresso
 Copyright (C) 2010 NXP Semiconductors
===============================================================================
*/

#ifndef SMALLGPIO_H_INCLUDED
#define SMALLGPIO_H_INCLUDED

//#include "LPC13xx.h"
#include "LPC11xx.h"

// InitGPIO() turns on the GPIO and IOCON clocks
#define InitGPIO() LPC_SYSCON->SYSAHBCLKCTRL |= ((1<<6) | (1<<16))

#define PORT_BIT_COUNT 12 // up to 12 I/O lines per port
#define PORT_COUNT 4 // up to 4 ports

#ifdef REALLY_SMALL
extern const uint8_t IOCON_LUT[];
#define IOCONAddress(port,bit) ((volatile uint16_t * const) (LPC_IOCON_BASE + IOCON_LUT[(PORT_BIT_COUNT*port)+bit]))
#else
extern const uint8_t IOCON_LUT[PORT_COUNT][PORT_BIT_COUNT];
#define IOCONAddress(port,bit) ((volatile uint16_t * const) (LPC_IOCON_BASE + IOCON_LUT[port][bit]))
#endif

#define GPIODirAddress(port) ((volatile uint16_t * const) (LPC_GPIO_BASE + (0x10000*(port)) + 0x8000))
#define GPIOMaskAddress(port,bits) ((volatile uint16_t * const) (LPC_GPIO_BASE + (0x10000*(port)) + (4*(bits))))


#define SetupGPIO(port, bit, output, ioconmask, ioconbits) \
    { \
	*IOCONAddress( (port),(bit) ) = ( *IOCONAddress((port),(bit)) & ~(ioconmask) ) | (ioconbits); \
	*GPIODirAddress((port)) = (output) ? *GPIODirAddress((port)) | (1<<(bit)) : *GPIODirAddress((port)) & ~(1<<(bit));\
    }
        //(output) ? *GPIODirAddress((port)) |= (1<<(bit)) : *GPIODirAddress((port)) &= ~(1<<(bit));
/*
	if (output)\
	{\
		*GPIODirAddress((port)) |= (1<<(bit));\
	}\
	else\
	{\
		*GPIODirAddress((port)) &= ~(1<<(bit));\
	}\
 */
#define SetGPIOOutMask(port, mask) *GPIODirAddress((port)) |= mask
#define SetGPIOOut(port, bit) *GPIODirAddress((port)) |= 1<<(bit)
#define SetGPIOIn(port, bit) *GPIODirAddress((port)) &= ~(1<<(bit))

#define SetGPIOBits(port,bits) ( *GPIOMaskAddress((port),(bits)) = (bits) )
#define ClrGPIOBits(port,bits) ( *GPIOMaskAddress((port),(bits)) = 0 )
#define ToggleGPIOBits(port,bits) ( *GPIOMaskAddress((port),(bits)) = ~(*GPIOMaskAddress((port),(bits))) )

#define SetGPIOBit(port,bit) SetGPIOBits((port), 1<<(bit))
#define ClrGPIOBit(port,bit) ClrGPIOBits((port), 1<<(bit))
#define ToggleGPIOBit(port,bit) ToggleGPIOBits((port), 1<<(bit))
#define GetGPIOBit(port, bit) (*GPIOMaskAddress((port), 1<<(bit)) ? 1 : 0)

#define GPIO_DIR_INPUT 0
#define GPIO_DIR_OUTPUT 1
#define GPIO_MODE_MASK (3<<3)
#define GPIO_MODE_PULLUP (2<<3)
#define GPIO_MODE_PULLDOWN (1<<3)
#define GPIO_MODE_REPEATER (3<<3)
#define GPIO_MODE_INACTIVE (0<<3)
#define GPIO_FUNC_MASK 7
#define GPIO_FUNC_0 0
#define GPIO_FUNC_1 1
#define GPIO_FUNC_2 2
#define GPIO_FUNC_3 3
#define GPIO_FUNC_4 4
#define GPIO_FUNC_5 5
#define GPIO_FUNC_6 6
#define GPIO_FUNC_7 7
#define GPIO_HYS_MASK (1<<5)
#define GPIO_HYS_ENABLE (1<<5)
#define GPIO_HYS_DISABLE (0<<5)
#define GPIO_ADMODE_MASK (1<<7)
#define GPIO_ADMODE_ANALOG (0<<7)
#define GPIO_ADMODE_DIGITAL (1<<7)


// #ifndef SMALLGPIO_H_INCLUDED
#endif
