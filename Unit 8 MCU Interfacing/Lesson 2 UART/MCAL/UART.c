/*
 * UART.c
 *
 *  Created on: Jan 9, 2022
 *      Author: Ezz Eldeen
 */

#include "UART.h"

void UART_Init(void)
{
	// bauderate
	UBRRL = 51;

	// normal mode
	CLEAR_BIT(UCSRA, U2X);
	// frame

	// no barity
	// 8 bit data init value by default

	//enable
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}

void UART_Send(unsigned char data )
{
	while(! READ_BIT(UCSRA,UDRE));
		UDR = data ;
}

unsigned char UART_Receive(void)
{
	while(!( READ_BIT(UCSRA,RXC)));
		return UDR ;
}


void UART_SendNumberU32(unsigned int num)
{

	// UART_Send(num);
	// UART_Send(num>>8);
	// UART_Send(num>>16);
	// UART_Send(num>>24);

	unsigned char  *ptr = &num;
	UART_Send(ptr[0]);
	UART_Send(ptr[1]);
	UART_Send(ptr[2]);
	UART_Send(ptr[3]);

}

unsigned int UART_ReceiveNumberU32(void)
{

	//u8 b1= UART_Receive();
	//u8 b2= UART_Receive();
	//u8 b3= UART_Receive();
	//u8 b4= UART_Receive();

	//u32 num1=0;
	// num = b1| (u32)b2<<8 | (u32)b3<<16 | (u32)b4<<24;

	unsigned int num;
	unsigned char *p = &num;
	p[0] = UART_Receive();
	p[1] = UART_Receive();
	p[2] = UART_Receive();
	p[3] = UART_Receive();
return num;
}

void UART_Send_String (char* str)
{
	unsigned char counter = 0 ;
	while (str[counter] != 0)
	{
		UART_Send(str[counter]) ;
		counter ++ ;
	}
}


char* UART_Receive_String (void)
{
	char data_ch = 0 ;
	char data_str[50] = {0} ;
	char* p_str = data_str ;
	unsigned char counter = 0 ;
	unsigned char i = 0 ;

	while ((data_ch != 32) && (counter < 50))
	{
		data_ch = UART_Receive() ;
		data_str[counter] = data_ch ;
		counter ++ ;
	}
	counter = 0 ;
	return p_str ;
}
