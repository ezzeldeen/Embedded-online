/*
 * main.c
 *
 *  Created on: Nov 5, 2021
 *      Author: Ezz Eldeen
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "Ezz"
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address
// RCC
#define RCC_BASE     0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *) (RCC_BASE + 0x18) // pointer to volatile uint32 = address
#define RCC_IOPAEN  (1<<2)

// GPIO
#define GPIOA_BASE   0x40010800
#define GPIOA_CRL     *(volatile uint32_t *) (GPIOA_BASE + 0x00)
#define GPIOA_CRH     *(volatile uint32_t *) (GPIOA_BASE + 0x04)
#define GPIOA_ODR     *(volatile uint32_t *) (GPIOA_BASE + 0x0c)
#define GPIOA_IDR     *(volatile uint32_t *) (GPIOA_BASE + 0x08)
#define GPIOA13 (1UL<<13)

#define GPIOB_BASE   0x40010C00
#define GPIOB_CRL     *(volatile uint32_t *) (GPIOB_BASE + 0x00)
#define GPIOB_CRH     *(volatile uint32_t *) (GPIOB_BASE + 0x04)
#define GPIOB_ODR     *(volatile uint32_t *) (GPIOB_BASE + 0x0c)
#define GPIOB_IDR     *(volatile uint32_t *) (GPIOB_BASE + 0x08)


void clock_init()
{
	// Enable clock GPIOA
	RCC_APB2ENR |= RCC_IOPAEN;
	// Enable clock GPIOB
	RCC_APB2ENR |= (1<<3);
}

void GPIO_init()
{
	GPIOA_ODR=0;
		GPIOA_CRL &=0xffffff0f;  // clear bits of PA1
		GPIOA_CRL |=(1<<6);  // PA1 in input floating
		GPIOA_CRH &=0xff0fffff; // clear bits of PA13
		GPIOA_CRH |=(1<<22); // PA13 in input flaoting

		GPIOB_CRL &=0xffffff0f;  // clear bits of PB1
		GPIOB_CRL |=(1<<4);  // PB1 output pull-push and 10MHZ max Speed
		GPIOB_CRH &=0xff0fffff; // clear bits of PB13
		GPIOB_CRH |=(1<<20); // PB13 output pull-push  10MHZ max Speed
}

void my_wait(int x)
{
	unsigned int i,j;
	for ( i=0 ; i<x ; i++)
		for( j=0 ; j<255 ; j++);
}

int main(void)
{
	clock_init();
	GPIO_init();

	while (1)
	{
		// PA1 external Pullup resistant
		if (((GPIOA_IDR & (1<<1)) >> 1) == 0) // press
		{
			GPIOB_ODR ^= (1<<1) ;
			while(((GPIOA_IDR & (1<<1)) >> 1) == 0); // single press.
		}

		// PA1 external Pulldown resistant
		if (((GPIOA_IDR & (1<<13)) >> 13) == 1) // Multi press
		{
			GPIOB_ODR ^= (1<<13) ;
		}
		my_wait(1);
	}

	return 0;
}




