#include "uart.h"

unsigned char string_buffer[100] = "learn-in-depth:Ezz Eldeen";
void main()
{
	Uart_send_string(string_buffer);
}