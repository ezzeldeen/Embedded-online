/*
 * main.c
 *
 *  Created on: Nov 6, 2021
 *      Author: Ezz Eldeen
 */

#include "util/delay.h"
#include "RegFile.h"
#define F_CPU 8000000UL

int main(void)
{
	DDRD |=  ((1<<4) | (1<<5) | (1<<6) | (1<<7)); // 3 pins output for 3 LEDs.

	while (1)
	{
	//	PORTD =0X00;
	//	_delay_ms(500);

		PORTD |= (1<<5);
		_delay_ms(500);
		PORTD &=~ (1<<5);
		_delay_ms(500);

		PORTD |= (1<<6);
		_delay_ms(500);
		PORTD &=~ (1<<6);
		_delay_ms(500);

		PORTD |= (1<<7);
		_delay_ms(500);
		PORTD &=~ (1<<7);
		_delay_ms(500);

		PORTD |= (1<<4);
		_delay_ms(500);
		PORTD &=~ (1<<4);
		_delay_ms(500);

	}
	return 0;
}


