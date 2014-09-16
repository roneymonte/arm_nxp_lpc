#ifndef SYSTICK_LIB_H_
#define SYSTICK_LIB_H_

//unsigned int  Num_int_SysTick=0; //Contador de interrupções SysTick.

void Config_SysTick_us();
void Config_SysTick_ms();

void delay_us (unsigned int Qt_Int_SysTick);
void delay_ms (unsigned int Qt_Int_SysTick);

#endif /* SYSTICK_LIB_H_ */
