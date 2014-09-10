/*
===============================================================================
 File small_gpio.c: Small gpio for LPC111x and LPC134x
 Project DebugTips_1114: Demonstration of debugging techniques for LPCXpresso
 Copyright (C) 2010 NXP Semiconductors
===============================================================================
*/
//#include "LPC13xx.h"
#include "LPC11xx.h"
#include "small_gpio.h"

__attribute__ ((section(".vector_const"))) //Replace WAKEUP_IRQHandler in exception vector
const uint8_t IOCON_LUT[PORT_COUNT][PORT_BIT_COUNT] = {
    { 0x0C, 0x10, 0x1C, 0x2C, 0x30, 0x34, 0x4C, 0x50, 0x60, 0x64, 0x68, 0x74 },
    { 0x78, 0x7C, 0x80, 0x90, 0x94, 0xA0, 0xA4, 0xA8, 0x14, 0x38, 0x6C, 0x98 },
    { 0x08, 0x28, 0x5C, 0x8C, 0x40, 0x44, 0x00, 0x20, 0x24, 0x54, 0x58, 0x70 },
    { 0x84, 0x88, 0x9C, 0xAC, 0x3C, 0x48 }
};
