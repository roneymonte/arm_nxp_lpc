Pisca-LED no LPC1114 (SysTick e Contador)
==

Exemplo de 2 pisca-leds (4 LEDs) controlados de maneiras diferentes por SysTick e por contador implementado matematicamente de maneira pobre. A finalidade eh a validacao do SysTick assim como a configuracao do Clock interno (IRC) com divisor de 12, transformando o oscilador inicial de 12 mhz em um clock de 1 mhz, facilitando os calculos de SysTick e contagem de ciclos.

O programa foi escrito com o editor "vi" e compilado com o gcc-arm-none-eabi, dentro de ambiente Windows 7.

O microcontrolador usado foi um Arm Cortex M0 (NXP modelo LPC1114FN28/102).
