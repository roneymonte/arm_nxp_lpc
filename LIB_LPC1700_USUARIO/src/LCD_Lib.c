/*============================================================================
Autor: Alberto Noboru Miyadaira
Livro: Microcontroladores ARM Cortex-M3 (Família LPC1700 da NXP)
Tipo de comunicação: 4bits.
Versão: v0.01
Data: 24/03/2011
Observação: Esta biblioteca requer a inclusão da biblioteca Systick_Lib.h.
============================================================================*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
#include "LCD_Lib.h"
#include "SysTick_Lib.h"

int __sys_write (int iFileHandle, char *pcBuffer, int iLength)
{
unsigned int i;
 for (i = 0; i<iLength; i++)
 {
	 LCD_ESCREVE_DADO(pcBuffer[i]);
 }
return iLength;
}

void Config_GPIO_LCD(void)
{
	/*
//--------------------------- LPC175x/6x -----------------------------------//
//Configura os pinos P1[0], P1[1], P1[4], P1[8], P1[9], P1[10] e P1[14] como GPIO.
LPC_PINCON->PINSEL2 &= ~(0b11<<0|0b11<<2|0b11<<8|0b11<<16|0b11<<18|0b11<<20|0b11<<28);
//--------------------------------------------------------------------------
*/

//------------------ (LPCXpresso: target LPC1768/69)------------------------//
//Configura os pinos P0[4], P0[5], P0[10] e P0[11] como GPIO.
LPC_PINCON->PINSEL0 &= ~(0b11<<8|0b11<<10|0b11<<20|0b11<<22);

//Configura os pinos P2[0], P2[1] e P2[2] como GPIO.
LPC_PINCON->PINSEL4 &= ~(0b11<<0|0b11<<2|0b11<<4);
//--------------------------------------------------------------------------//

}

//----------------------------- LCD_SETA_NIBBLE ----------------------------//
//Seta os pinos de dados conforme o valor do dado.
//Se o parâmetro H_L = 1 : Seta os pinos com os 4bits mais significativos do dado.
//Se o parâmetro H_L = 0 : Seta os pinos com os 4bits menos significativos do dado.
void LCD_SETA_NIBBLE (unsigned char H_L, unsigned char dado)
{
	if(H_L)
	{
	  B7 = dado>>7; //B7 recebe o bit 7 da variável dado.
	  B6 = dado>>6; //B6 recebe o bit 6 da variável dado.
	  B5 = dado>>5; //B5 recebe o bit 5 da variável dado.
	  B4 = dado>>4; //B4 recebe o bit 4 da variável dado.
	}
	else
	{
	  B7 = dado>>3; //B7 recebe o bit 3 da variável dado.
	  B6 = dado>>2; //B6 recebe o bit 2 da variável dado.
	  B5 = dado>>1; //B5 recebe o bit 1 da variável dado.
	  B4 = dado;    //B4 recebe o bit 0 da variável dado.
	}
    E = 1;        //Habilita o Display LCD.
    delay_us(2);  //Gera um delay de 2us.
    E = 0;        //Desabilita o Display LCD.
}

//----------------------------- LCD_LE_NIBBLES -----------------------------//
//Lê os pinos de dados.
unsigned char LCD_LE_NIBBLES (void)
{
unsigned char dado_entrada;

    E = 1;//Habilita o Display LCD.
    delay_us(2); //Gera um delay de 2us.

    dado_entrada = B7;
    dado_entrada = (dado_entrada<<1) | B6;
    dado_entrada = (dado_entrada<<1) | B5;
    dado_entrada = (dado_entrada<<1) | B4;

    E = 0; //Desabilita o Display LCD.
    delay_us(1); //Gera um delay de 1us.
    E = 1; //Habilita o Display LCD.
    delay_us(2); //Gera um delay de 2us.

    dado_entrada = (dado_entrada<<1) | B7;
    dado_entrada = (dado_entrada<<1) | B6;
    dado_entrada = (dado_entrada<<1) | B5;
    dado_entrada = (dado_entrada<<1) | B4;

    E = 0; //Desabilita o Display LCD.

    return dado_entrada;
}

unsigned char LCD_ENVIA_CONTROLE (unsigned char I_D, unsigned char E_L, unsigned char dado, unsigned int atraso_us)
{
//---------------- Descrição dos parâmetros de entrada ---------------------//
// - I_D = 0 : Instrução.
// - I_D = 1 : Dado.
//--------------------------------------------------------------------------//
// - E_L = 1 : Leitura.
// - E_L = 0 : Escrita.
//--------------------------------------------------------------------------//
// - dado : Dado ou instrução encaminhada para o display.
//--------------------------------------------------------------------------//
// - atraso_us = 1 : Tempo para o processamento da instrução em us.
//--------------------------------------------------------------------------//

//Variável local para armazenamento do dado enviado pelo display LCD.
unsigned char dado_entrada;

//------------- Configura todos os pinos de controle como saída ------------//
D_E(SAIDA);
D_RW(SAIDA);
D_RS(SAIDA);

//------------- Informa o tipo de operação e direção do dado --------------//
RS = I_D; //Informa se é um comando ou dado.
RW = E_L; //Informa se é escrita ou leitura.

   if(E_L == 0)
   {
//------------- Configura todos os pinos de dados como saída --------------//
	   D_B7(SAIDA);
	   D_B6(SAIDA);
	   D_B5(SAIDA);
	   D_B4(SAIDA);

//------------------------ Envio de dado ou instrução ---------------------//
       LCD_SETA_NIBBLE (1,dado); //Envia o nibble mais significativo.
       LCD_SETA_NIBBLE (0,dado); //Envia o nibble menos significativo.
       delay_us(atraso_us);      //Gera um atraso de us.
       return 0;
    }
    else
    {
//------------ Configura todos os pinos de dados como entrada -------------//
       D_B7(ENTRADA);
       D_B6(ENTRADA);
       D_B5(ENTRADA);
       D_B4(ENTRADA);

//---------------------------- Leitura de dado ----------------------------//
       dado_entrada = LCD_LE_NIBBLES(); //Lê os dados de entrada.
       delay_us(atraso_us); //Gera um delay de us.
       return dado_entrada;
   }
}

//------------------------------- LCD_INICIA ------------------------------//
// Inicializa o Display LCD conforme os parâmetros abaixo:
// - conf1 : Configuração do Display.
// - conf2 : Controle do Display.
// - conf3 : Configuração de Deslocamento do Cursor e da Mensagem.
// Exemplo:
// - conf1 = 0x28
//     # Comunicação de 4 vias
//     # Display com mais de uma linha
//     # Matriz 8x5
// - conf2 = 0x0f
//     # Liga display
//     # Cursor piscante
// - conf3 = 0x06
//     # Desloca o cursor para à direita quando um novo caractere for inserido.
//     # Não desloca a mensagem quando um novo caractere for inserido.
void LCD_INICIA( unsigned char conf1, unsigned char conf2, unsigned char conf3)
{
//----------------- Configura todos os pinos de como saída ----------------//
D_B7(SAIDA);
D_B6(SAIDA);
D_B5(SAIDA);
D_B4(SAIDA);
D_E(SAIDA);
D_RW(SAIDA);
D_RS(SAIDA);

//----------------- Desabilita operações com o Display LCD ----------------//
E = 0;

delay_us(20000); //Aguarda 20ms antes de iniciar a sequência de comandos de configuração.

LCD_SETA_NIBBLE (0, 0x03);        //Envia o valor 0x03
delay_us(4500);                   //Gera um atraso de 4,5ms.
LCD_SETA_NIBBLE (0, 0x03);        //Envia o valor 0x03
delay_us(150);                    //Gera um atraso de 150us.
LCD_SETA_NIBBLE (0, 0x03);        //Envia o valor 0x03
delay_us(45);                     //Gera um atraso de 45us.
LCD_SETA_NIBBLE (0, 0x02);        //Envia o valor 0x02
delay_us(45);                     //Gera um atraso de 45us.
LCD_ENVIA_CONTROLE(0,0,conf1,45); //Configuração do Display.
LCD_ENVIA_CONTROLE(0,0,conf2,45); //Controle do Display.
LCD_ENVIA_CONTROLE(0,0,conf3,45); //Configuração de deslocamento do cursor e da mensagem.
LCD_LIMPA_TELA( );                //Limpa a tela e desloca o cursor para a posição (1,1).
}

//---------------------------- LCD_CONTROLE ----------------------------//
// - controle = 0 : Desliga o cursor.
// - controle = 1 : Desliga o display.
// - controle = 2 : Liga o display, o cursor e o modo piscante.
// - controle = 3 : Liga o display e o cursor.
// - controle = 4 : Liga o display e o modo de cursor piscante.
void LCD_CONTROLE (unsigned char controle)
{
unsigned char cursor [5] = {0x0C, 0x08, 0x0F, 0x0E, 0x0D};

LCD_ENVIA_CONTROLE(0,0,cursor[controle],45);
}

//---------------------------- LCD_STATUS -----------------------------//
//Retorna o estado do controlador.
//0 - Livre.
//1 - Ocupado.
unsigned char LCD_STATUS ( )
{
	if((LCD_ENVIA_CONTROLE(0,1,0,45)&0x80))
        return 1;
	else
        return 0;
}

//---------------------------- LCD_LIMPA_TELA ----------------------------//
// - Limpa a tela do Display LCD.
// - Coloca o cursor na linha 1 coluna 1.
void LCD_LIMPA_TELA (void)
{  LCD_ENVIA_CONTROLE(0,0,0x01,2000);  }

//--------------------------- LCD_CURSOR_HOME ----------------------------//
// - Coloca o cursor na linha 1 coluna 1.
void LCD_CURSOR_HOME (void)
{  LCD_ENVIA_CONTROLE(0,0,0x02,2000);  }

//------------------------- LCD_DESLOCA_CURSOR ---------------------------//
// - D_E = 0 : Desloca o cursor para à direita.
// - D_E = 1 : Desloca o cursor para à esquerda.
void LCD_DESLOCA_CURSOR(unsigned char D_E)
{
	if (!D_E)
		LCD_ENVIA_CONTROLE(0,0,0x14,45);
	else
		LCD_ENVIA_CONTROLE(0,0,0x10,45);
}

//------------------------ LCD_DESLOCA_MENSAGEM -------------------------//
// - D_E = 0 : Desloca a mensagem para à direita.
// - D_E = 1 : Desloca a mensagem para à esquerda.
void LCD_DESLOCA_MENSAGEM(unsigned char D_E)
{
	if (!D_E)
		LCD_ENVIA_CONTROLE(0,0,0x1C,45);
	else
		LCD_ENVIA_CONTROLE(0,0,0x18,45);
}

//------------------------- LCD_DESLOCA_POSICAO -------------------------//
//Desloca o cursor para a posição apontada pelos parâmetros L(linha)e C(coluna).
void LCD_DESLOCA_POSICAO(unsigned char L, unsigned char C)
{
   switch (L)
   {
     case 1: LCD_ENVIA_CONTROLE(0,0,0x80+C-1,45);  break;
     case 2: LCD_ENVIA_CONTROLE(0,0,0xC0+C-1,45);  break;
     case 3: LCD_ENVIA_CONTROLE(0,0,0x94+C-1,45);  break;
     case 4: LCD_ENVIA_CONTROLE(0,0,0xD4+C-1,45);  break;
   }
}

//-------------------------- LCD_LE_POSICAO ---------------------------//
//Retorna a posição do cursor.
unsigned char LCD_LE_POSICAO ( )
{
return ((0x7F)&(LCD_ENVIA_CONTROLE(0,1,0,45)));
}

//-------------------------- LCD_ESCREVE_DADO --------------------------//
//Escreve um caractere ou símbolo no display.
void LCD_ESCREVE_DADO(unsigned char dado)
{ LCD_ENVIA_CONTROLE(1,0,dado,45); }

//---------------------------- LCD_LE_DADO -----------------------------//
//Retorna o caractere presente na posição do cursor.
unsigned char LCD_LE_DADO( )
{ return LCD_ENVIA_CONTROLE(1,1,0,45); }

//------------------------- LCD_IMPRIME_STRING -------------------------//
//Envia uma string para o Display LCD.
void LCD_IMPRIME_STRING (const char *string)
{
   while (*string!=0)
   {
	   LCD_ESCREVE_DADO(*string);
       string++;
   }
}

//------------------------- LCD_IMPRIME_STRING -------------------------//
//Envia uma matriz de dados para o Display LCD.
void LCD_IMPRIME_BUFFER(unsigned char *buffer, unsigned char tamanho_buffer)
{
   while (tamanho_buffer--)
   {
	   LCD_ESCREVE_DADO(*buffer);
       buffer++;
   }
}
