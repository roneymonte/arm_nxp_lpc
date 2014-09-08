#ifndef UART0_LIB_H_
#define UART0_LIB_H_

//Protótipos de função
void Config_UART0_RS232(unsigned int baud);
void UART0_ESCREVE_CARACTERE(char c);
void UART0_IMPRIME_MENSAGEM(const char *string);
void UART0_IMPRIME_BUFFER(char *buffer, char tamanho_buffer);
unsigned char UART0_LE_CARACTERE();
int __sys_write (int iFileHandle, char *pcBuffer, int iLength);

#endif /* UART0_LIB_H_ */
