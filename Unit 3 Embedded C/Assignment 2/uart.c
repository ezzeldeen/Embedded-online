#include "uart.h"

#define UART0DR *((volatile unsigned int * const)((unsigned int*)0x101f1000))

void Uart_send_string (unsigned char* txt)
{
	while(*txt != '\0')
	{
		UART0DR = (unsigned int)(* txt);
		txt++;
	}
	
}