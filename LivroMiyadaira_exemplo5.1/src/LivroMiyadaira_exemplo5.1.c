/*
===============================================================================
 Name        : LivroMiyadaira_exemplo5.1.c
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


// TODO: insert other definitions and declarations here
void Config_CLK();
void Config_FLASH();
void Config_CLKOUT();
void PLL0_FEED();

int main(void) {

    // TODO: insert code here
	Config_CLK();
	Config_FLASH();
	Config_CLKOUT();

	//SystemInit();	// A funcao SystemInit foi apresentada na pagina 177 do CAP 5.
	//Passo 1 :
	//#define CLOCK_SETUP           1
	//#define SCS_Val               0x00000020	// se CLOCKS_SETUP, configure SCS com VAL

	//Passo4 : Fonte de Clock para o PLL0:
	//#define CLKSRCSEL_Val         0x00000001	// clock do oscilador principal

	//Passo5 :
	//#define PLL0_SETUP            1
	//#define PLL0CFG_Val           0x00050063	// se PLL0_SETUP, configure com 05 00 63
	// Seria PRE-Divisor = 0x05 (5 decimal), e Multiplicador = 0x63 (100 decimal)
	/*
	 * Fcco = (2 * multiplicador+1 * clock) / divisor+1
	 * 0x63 = 99 com +1 = 100 (multiplicador)
	 * 0x05 = 5 com +1 = 6 (pre-divisor)
	 *
	 * Fcco = (2 * 100 * 12 mhz) / 6
	 * Fcco = (2 * 100 * 12.000.000) / 6
	 * Fcco = (2 * 1.200.000.000) / 6
	 * Fcco = 2.400.000.000 / 6
	 * Fcco = 400.000.000 = 400 mhz
	 *
	 */

	//Passo6 :
	//#define PLL1_SETUP            1
	//#define PLL1CFG_Val           0x00000023	// se PLL1_SETUP, configura com 00 00 23
	// Valor multiplicador PLL1=0x23 [bits 6:5=01 = 1 divisor // 4:0 = 00011 = 3 multiplic]

	//Passo2 :
	//#define CCLKCFG_Val           0x00000003	// configura CCLKCFG  = DIVISOR DE CLOCK /4

	//Passo7 :
	//#define USBCLKCFG_Val         0x00000000	// usado caso o PLL1_SETUP nao for configurado

	//Passo3 :	Selecao do Periferico de Clock
	//#define PCLKSEL0_Val          0x00000000	//
	//#define PCLKSEL1_Val          0x00000000

	//Passo8:
	//#define PCONP_Val             0x042887DE	// Power Control para Perifericos
	//04 = 4  =  0000.0100 [31:24] = 1 = PCI2C2 / I2C 2
	//28 = 40 =  0010.1000 [23:16] = 1 = PCSSP0 / SSP0
	//87 = 135 = 1000.0111 [15:8]  = [15 reservado], [10:8] = 111 = SSP1 / RTC / SPI
	//DE = 222 = 1101.1110 [7:0]   = I2C 0 / PWM 1 / UART 1 / UART 0 / Timer 1 / Timer 0

	//Passo 9:
	//#define CLKOUTCFG_Val         0x00000000	// Configura Clock de Saida no pino fisico





    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}



void Config_CLK ()
{
	LPC_SC->SCS = 1<<5;						// habilita uso do oscilador principal
	while(!(LPC_SC->SCS & (1<<6)));			// espera oscilador ficar pronto

	LPC_SC->PLL0CON=0x00;					// desabilita o PLL0
	PLL0_FEED();							// injeta o comando 0xAA e 0x55 no PLL0

	LPC_SC->CLKSRCSEL=0b01;					// define o oscilador principal (externo) de 12 mhz
	LPC_SC->PLL0CFG = 99<<0 | 7<<16;		// define MSEL=99 (multiplicador) e NSEL=7 (divisor)
	/*
	 * Fcco = (2 * multiplicador+1 * clock) / divisor+1
	 *
	 * Fcco = (2 * 100 * 12 mhz) / 8
	 * Fcco = (2 * 100 * 12.000.000) / 8
	 * Fcco = (2 * 1.200.000.000) / 8
	 * Fcco = 2.400.000.000 / 8
	 * Fcco = 300.000.000 = 300 mhz
	 *
	 */
	PLL0_FEED();							// injeta o comando 0xAA e 0x55 no PLL0

	LPC_SC->PLL0CON = 1<<0;					// agora habilita o PLL0
	PLL0_FEED();							// injeta o comando 0xAA e 0x55 no PLL0
	while (!(LPC_SC->PLL0STAT & (1<<26))) ;	// aguarda a estabilizacao do PLL0

	LPC_SC->CCLKCFG = 4;					// divide o clock por 4+1 = 300 mhz / 5 = 60 mhz
	LPC_SC->PLL0CON = 1<<0 | 1<<1;			// Habilita e Conecta o PLL0 (PPLC0)
	PLL0_FEED();							// injeta o comando 0xAA e 0x55 no PLL0
	while(!(LPC_SC->PLL0STAT & ( (1<<25)|(1<<24) ) ));	// aguarda o PLL0 conectar

	LPC_SC->PCLKSEL0=((LPC_SC->PCLKSEL0 & ~(0b11<<4|0b11<<6)) | (0b01<<4|0b00<<6));
	// seta o TIMER1 e UART1 com AND ~11,
	// configura o TIMER1 (60/1 = 60mhz)e UART0 (60/4 = 15mhz) para receberem o clock (/1 e /4)
}

void Config_FLASH ()
{
	// memoria flash para ser acessada em 3 clocks da CPU
	LPC_SC->FLASHCFG = ((LPC_SC->FLASHCFG & ~(0b1111<<12)) | (2<<12));
	// seta a FLASH Configuration escrevendo 0000 (~1111) na posicao 15:14:13:12
	// configura a Flashcfg escrevendo 0010 na posicao 15:14:13:12
}

void Config_CLKOUT ()
{

}

void PLL0_FEED()
{
	__disable_irq();
	LPC_SC->PLL0FEED = 0xAA;
	LPC_SC->PLL0FEED = 0x55;
	__enable_irq();
}

/*------------- System Control (SC) ------------------------------------------

	typedef struct
	{
	  __IO uint32_t FLASHCFG;               /* Flash Accelerator Module
		   uint32_t RESERVED0[31];
	  __IO uint32_t PLL0CON;                /* Clocking and Power Control
	  __IO uint32_t PLL0CFG;
	  __I  uint32_t PLL0STAT;
	  __O  uint32_t PLL0FEED;
		   uint32_t RESERVED1[4];
	  __IO uint32_t PLL1CON;
	  __IO uint32_t PLL1CFG;
	  __I  uint32_t PLL1STAT;
	  __O  uint32_t PLL1FEED;
		   uint32_t RESERVED2[4];
	  __IO uint32_t PCON;
	  __IO uint32_t PCONP;
		   uint32_t RESERVED3[15];
	  __IO uint32_t CCLKCFG;
	  __IO uint32_t USBCLKCFG;
	  __IO uint32_t CLKSRCSEL;
	  __IO uint32_t	CANSLEEPCLR;
	  __IO uint32_t	CANWAKEFLAGS;
		   uint32_t RESERVED4[10];
	  __IO uint32_t EXTINT;                 /* External Interrupts
		   uint32_t RESERVED5;
	  __IO uint32_t EXTMODE;
	  __IO uint32_t EXTPOLAR;
		   uint32_t RESERVED6[12];
	  __IO uint32_t RSID;                   /* Reset
		   uint32_t RESERVED7[7];
	  __IO uint32_t SCS;                    /* Syscon Miscellaneous Registers
	  __IO uint32_t IRCTRIM;                /* Clock Dividers
	  __IO uint32_t PCLKSEL0;
	  __IO uint32_t PCLKSEL1;
		   uint32_t RESERVED8[4];
	  __IO uint32_t USBIntSt;               /* USB Device/OTG Interrupt Register
	  __IO uint32_t DMAREQSEL;
	  __IO uint32_t CLKOUTCFG;              /* Clock Output Configuration
	 } LPC_SC_TypeDef;
 *
 */
