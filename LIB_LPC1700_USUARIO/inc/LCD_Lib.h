/*============================================================================
Autor: Alberto Noboru Miyadaira
Livro: Microcontroladores ARM Cortex-M3 (Família LPC1700 da NXP)
Tipo de comunicação: 4bits.
Versão: v0.01
Data: 24/03/2011
Observação: Esta biblioteca requer a inclusão da biblioteca Systick_Lib.h.
============================================================================*/

#ifndef LCD_LIB_H_
#define LCD_LIB_H_

//Definições para configuração do sentido do fluxo de dados dos pinos de GPIO.
#define ENTRADA 0
#define SAIDA   1

/*---------------------------- LPC175x/6x ----------------------------------//
//--------------------------- Bit Banding ----------------------------------//
#define B7 (*(volatile unsigned int *)(0x23380680)) //P1[0]
#define B6 (*(volatile unsigned int *)(0x23380684)) //P1[1]
#define B5 (*(volatile unsigned int *)(0x23380690)) //P1[4]
#define B4 (*(volatile unsigned int *)(0x233806A0)) //P1[8]
#define E (*(volatile unsigned int *)(0x233806A4))  //P1[9]
#define RW (*(volatile unsigned int *)(0x233806A8)) //P1[10]
#define RS (*(volatile unsigned int *)(0x233806B8)) //P1[14]

#define D_B7(sentido) (*(volatile unsigned int *)(0x23380400))=sentido //P1[0]
#define D_B6(sentido) (*(volatile unsigned int *)(0x23380404))=sentido //P1[1]
#define D_B5(sentido) (*(volatile unsigned int *)(0x23380410))=sentido //P1[4]
#define D_B4(sentido) (*(volatile unsigned int *)(0x23380420))=sentido //P1[8]
#define D_E(sentido)  (*(volatile unsigned int *)(0x23380424))=sentido //P1[9]
#define D_RW(sentido) (*(volatile unsigned int *)(0x23380428))=sentido //P1[10]
#define D_RS(sentido) (*(volatile unsigned int *)(0x23380438))=sentido //P1[14]
//---------------------------------------------------------------------------
*/
//------------------ (LPCXpresso: target LPC1768/69) -----------------------//
//--------------------------- Bit Banding ----------------------------------//
#define B7 (*(volatile unsigned int *)(0x23380290)) //P0[4]
#define B6 (*(volatile unsigned int *)(0x23380294)) //P0[5]
#define B5 (*(volatile unsigned int *)(0x233802A8)) //P0[10]
#define B4 (*(volatile unsigned int *)(0x233802AC)) //P0[11]
#define E  (*(volatile unsigned int *)(0x23380A80)) //P2[0]
#define RW (*(volatile unsigned int *)(0x23380A84)) //P2[1]
#define RS (*(volatile unsigned int *)(0x23380A88)) //P2[2]

#define D_B7(sentido) (*(volatile unsigned int *)(0x23380010))=sentido //P0[4]
#define D_B6(sentido) (*(volatile unsigned int *)(0x23380014))=sentido //P0[5]
#define D_B5(sentido) (*(volatile unsigned int *)(0x23380028))=sentido //P0[10]
#define D_B4(sentido) (*(volatile unsigned int *)(0x2338002C))=sentido //P0[11]
#define D_E(sentido)  (*(volatile unsigned int *)(0x23380800))=sentido //P2[0]
#define D_RW(sentido) (*(volatile unsigned int *)(0x23380804))=sentido //P2[1]
#define D_RS(sentido) (*(volatile unsigned int *)(0x23380808))=sentido //P2[2]
//---------------------------------------------------------------------------//

 void Config_GPIO_LCD(void);
 void LCD_SETA_NIBBLE (unsigned char H_L, unsigned char dado);
 unsigned char LCD_LE_NIBBLES (void);
 unsigned char LCD_ENVIA_CONTROLE (unsigned char I_D, unsigned char E_L, unsigned char dado, unsigned int atraso_us);
 void LCD_INICIA( unsigned char conf1, unsigned char conf2, unsigned char conf3);
 void LCD_CONTROLE (unsigned char controle);
 unsigned char LCD_STATUS ( );
 void LCD_LIMPA_TELA (void);
 void LCD_CURSOR_HOME (void);
 void LCD_DESLOCA_CURSOR(unsigned char D_E);
 void LCD_DESLOCA_MENSAGEM(unsigned char D_E);
 void LCD_DESLOCA_POSICAO(unsigned char L, unsigned char C);
 unsigned char LCD_LE_POSICAO ( );
 void LCD_ESCREVE_DADO(unsigned char dado);
 unsigned char LCD_LE_DADO( );
void LCD_IMPRIME_STRING (const char *string);
void LCD_IMPRIME_BUFFER( unsigned char *buffer, unsigned char tamanho_buffer);


#endif /* LCD_LIB_H_ */
