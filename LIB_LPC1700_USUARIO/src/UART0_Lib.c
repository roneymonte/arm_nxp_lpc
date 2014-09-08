#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

void Config_UART0_RS232(unsigned int baud)
{
	float res_f;
	unsigned int res_i;

	LPC_SC->PCONP |= 1<<3;     //Ativa a UART0

	//PCLK_UART0 = C_CLK/4.
	LPC_SC->PCLKSEL0 &= ~(0b11<<6);

	// Atualiza o valor da frequência de clock do sistema.
	SystemCoreClockUpdate();

	res_f = (float)SystemCoreClock/(16*4*(float)baud);
	res_i = SystemCoreClock/(16*4*baud);

	if(res_i>res_f)
		res_i--;

	LPC_UART0->LCR = 0x80;	             //DLAB = 1
	LPC_UART0->DLL = (res_i&0xFF);	     //U0DLL = 81
	LPC_UART0->DLM = ((res_i>>8)&0xFF);  //U0DLM = 0
	LPC_UART0->FDR = 0 | 1<<4;           //DIVADDVAL = 0 e MULVAL = 1.

	//Configura os pinos P0.2 e P0.3 para a função TXD0 e RXD0 respectivamente.
	LPC_PINCON->PINSEL0 = ((LPC_PINCON->PINSEL0&~(0b11<<4|0b11<<6))|(0b01<<4|0b01<<6));

	//UART0 – 8bits de dados, sem paridade, 1bit de parada e DLAB = 0.
	LPC_UART0->LCR = 3;

	LPC_UART0->FCR = 0x07; //Ativa e reinicia as FIFOs da UART0.
}

void UART0_ESCREVE_CARACTERE(char c)
{
	//Aguarda até que o registro U0THR esteja vazio.
	while(!(LPC_UART0->LSR&(1<<5)));

	//Envia o caractere para o topo da FIFO de transmissão.
	LPC_UART0->THR = c;
}
void UART0_IMPRIME_MENSAGEM (const char *string)
{
   while (*string!=0)
   {
	   UART0_ESCREVE_CARACTERE(*string);
       string++;
   }
}

void UART0_IMPRIME_BUFFER(char *buffer, char tamanho_buffer)
{
   while (tamanho_buffer--)
   {
	   UART0_ESCREVE_CARACTERE (*buffer);
       buffer++;
   }
}

unsigned char UART0_LE_CARACTERE()
{
	// Aguarda até que o registro U0RBR contenha um dado válido.
	while(!(LPC_UART0->LSR&1));

	//Lê o dado localizado no topo da FIFO de recepção.
	return (unsigned char)LPC_UART0->RBR;
}

//Redireciona a saída formatada.
int __sys_write (int iFileHandle, char *pcBuffer, int iLength)
{
unsigned int i;
 for (i = 0; i<iLength; i++)
 {
	 UART0_ESCREVE_CARACTERE(pcBuffer[i]);
 }
return iLength;
}
