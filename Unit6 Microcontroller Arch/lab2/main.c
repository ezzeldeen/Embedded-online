/*
 * main.c
 * Created on: Nov 2, 2021
 * Author: Ezz Eldeen
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//#define RCC_BASE     0x40021000
//#define RCC_APB2ENR  *(volatile uint32_t *) (RCC_BASE + 0x18) // pointer to volatile uint32 = address
//#define RCC_IOPAEN  (1<<2)

ISR(INT0_vect) // to store ISR at address of INT0
{
	PORTD |= (1<<5);
	_delay_ms(1000);
	PORTD &= ~(1<<5);
	_delay_ms(1000);
}

ISR(INT1_vect) // to store ISR at address of INT1
{
	PORTD |= (1<<6);
	_delay_ms(1000);
	PORTD &= ~(1<<6);
	_delay_ms(100);
}

ISR(INT2_vect) // to store ISR at address of INT2
{
	PORTD |= (1<<7);
	_delay_ms(1000);
	PORTD &= ~(1<<7);
	_delay_ms(100);
}

int main()
{
	DDRD |=  ((1<<5) | (1<<6) | (1<<7)); // 3 pins output for 3 LEDs.
	DDRD &= ~((1<<2) | (1<<3) ); // 3 pins input for 3 Buttons PortD2,3.
	DDRB &= ~(1<<2); // pin input for Button PortB2.

	SREG |= 0x80; // Enable global interrupt
	GICR |= 0x40; // Enable INT0
	GICR |= 0x80; // Enable INT1
	GICR |= 0x20; // Enable INT2

	MCUCR |= 0x01; // logical change level trigger for INT0
	MCUCR |= 0x0C; // rising edge trigger for INT1
	MCUCSR &= ~(1<<6); // INT2 falling edge trigger

	while (1){}
}
