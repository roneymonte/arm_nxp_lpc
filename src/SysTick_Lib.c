/*====================================================================================
Autor: Alberto Noboru Miyadaira
Descrição: Esta biblioteca contempla uma função de atraso, em us, usando o Systick Timer.
Observação: O nível de prioridade (20) do SysTick Timer está definido considerando o
            PRIGROUP = 010.
====================================================================================*/

// obs: pequena modificacao para suporte de milisegundos por Roney Monte

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include "SysTick_Lib.h"

unsigned int  Num_int_SysTick=0; //Contador de interrupções SysTick.

void SysTick_Handler(void)
{ Num_int_SysTick++; }

void Config_SysTick_us()
{
// Atualiza o valor da frequência de clock do sistema.
SystemCoreClockUpdate();

// Período = (LOAD + 1)/C_CLK
// LOAD = (C_CLK*Período)-1 = (SystemCoreClock*Período)-1
SysTick->LOAD  = (SystemCoreClock/1000000)-1;		//uS
//SysTick->LOAD  = (SystemCoreClock/1000)-1;			//mS


//Define a prioridade da interrupção DMA.
NVIC_SetPriority(SysTick_IRQn , 20);

// SysTick->CTRL
// 0x04 – Fonte de clock C_CLK.            ->  CLKSOURCE = 1
// 0x02 – Habilita a interrupção SysTick.  ->  TICKINT = 1
// 0x01 – Habilita o contador.             ->  ENABLE = 1
SysTick->CTRL = 0x04|0x02|0x01;
}

void Config_SysTick_ms()	// rotina adicionada por Roney Monte
{
// Atualiza o valor da frequência de clock do sistema.
SystemCoreClockUpdate();

// Período = (LOAD + 1)/C_CLK
// LOAD = (C_CLK*Período)-1 = (SystemCoreClock*Período)-1
//SysTick->LOAD  = (SystemCoreClock/1000000)-1;		//uS
SysTick->LOAD  = (SystemCoreClock/1000)-1;			//mS


//Define a prioridade da interrupção DMA.
NVIC_SetPriority(SysTick_IRQn , 20);

// SysTick->CTRL
// 0x04 – Fonte de clock C_CLK.            ->  CLKSOURCE = 1
// 0x02 – Habilita a interrupção SysTick.  ->  TICKINT = 1
// 0x01 – Habilita o contador.             ->  ENABLE = 1
SysTick->CTRL = 0x04|0x02|0x01;
}

void delay_us (unsigned int Qt_Int_SysTick)
{
  Num_int_SysTick = 0;
  SysTick->CTRL |= 1<<0; //Habilita o contador.

  //Aguarda até que o número de interrupções seja alcançado.
  while (Num_int_SysTick < Qt_Int_SysTick);

  SysTick->CTRL &= ~(1<<0);//Desabilita o contador.
}

void delay_ms (unsigned int Qt_Int_SysTick)	// rotina adicionada por Roney Monte
{
  Num_int_SysTick = 0;
  SysTick->CTRL |= 1<<0; //Habilita o contador.

  //Aguarda até que o número de interrupções seja alcançado.
  while (Num_int_SysTick < Qt_Int_SysTick);

  SysTick->CTRL &= ~(1<<0);//Desabilita o contador.

  // obs: na verdade delay_ms e delay_us sao identicas, apenas criei esta
  // simplesmente para nao misturar futuras alteracoes
}
