/*
 * lcd_keypad.c
 * Author : Ezz
 */

#include "Lcd.h"
#include "UART.h"
#include "Keypad.h"

#define F_CPU 8000000UL
	unsigned char x='p';

int main()
{

	LCD_INIT();
	UART_Init();
	//	Keypad_init();
	//	_delay_ms(50);

	//	unsigned char key_pressed;
//	LCD_WRITE_STRING("Ezz ");


	while (1)
	{
		UART_Send('1');
		LCD_WRITE_CHAR('1');
		x = UART_Receive();
		LCD_WRITE_CHAR(x);

	}
}


