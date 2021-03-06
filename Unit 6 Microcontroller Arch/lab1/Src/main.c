/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>

typedef volatile unsigned int vuint32_t ;

// register address
// RCC
#define RCC_BASE     0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *) (RCC_BASE + 0x18) // pointer to volatile uint32 = address
#define RCC_IOPAEN  (1<<2)

// GPIO
#define GPIOA_BASE   0x40010800
#define GPIOA_CRH     *(volatile uint32_t *) (GPIOA_BASE + 0x04)
#define GPIOA_ODR     *(volatile uint32_t *) (GPIOA_BASE + 0x0c)
#define GPIOA13 (1UL<<13)
#define GPIOA_CRL     *(volatile uint32_t *) (GPIOA_BASE + 0x04)

// EXTI
#define EXTI_BASE   0x40010400
#define EXTI_IMR     *(volatile uint32_t *) (EXTI_BASE + 0x00)
#define EXTI_RTSR     *(volatile uint32_t *) (EXTI_BASE + 0x08)
#define EXTI_PR     *(volatile uint32_t *) (EXTI_BASE + 0x14)

// AFIO
#define AFIO_BASE   0x40010000
#define AFIO_EXTICR1     *(volatile uint32_t *) (AFIO_BASE + 0x08)

#define NVIC_EXTIE0     *(volatile uint32_t *) (0xE000E100)

void clock_init()
{
	// Enable clock GPIOA
	RCC_APB2ENR |= RCC_IOPAEN;
	// Enable clock for alternative func IO bit 0 AFIOEN
	RCC_APB2ENR |= (1<<0);
}

void GPIO_init()
{
	// pin 13 port A output
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	// pin A0 input floating
	GPIOA_CRL |= (1<<2);
}

int main(void)
{
	clock_init();
	GPIO_init();

	// EXTI0 config x=0 to port A0
	AFIO_EXTICR1 =0;
	// Enable EXTI Line 0 (Mask 1)
	EXTI_IMR |= (1<<0);
	// Enable Rising Trigger
	EXTI_RTSR |= (1<<0);

	// Enable NVIC Irq6 EXTI0
	NVIC_EXTIE0 |= (1<<6);

	while (1);
	return 0;
}

void EXTI0_IRQHandler(void)
{
	// IRQ is happening EXTIO >>> PORTA pin 0 rising edge
	// toggle led pin A 13
	GPIOA_ODR ^= (1<<13);
	// Clear pending request for line 0
	EXTI_PR |= (1<<0);
}



