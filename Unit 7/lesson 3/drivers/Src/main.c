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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103c6.h"
#include "Stm32_F103C6_GPIO_driver.h"


void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN() ;
	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN() ;
}

void GPIO_init()
{
	GPIO_PinConfig_t pinCfg ;

	// PA1 input High Floating input (reset state)
	pinCfg.GPIO_PinNumber = GPIO_PIN_1;
	pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(GPIOA, &pinCfg);

	// PB1 (output PUSH pull Mode)
	//01: output mode, max speed 10 MHz.
	//CNF 00: output push pull
	pinCfg.GPIO_PinNumber = GPIO_PIN_1;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	pinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(GPIOB, &pinCfg);

	//PA13 input High Floating input
	pinCfg.GPIO_PinNumber = GPIO_PIN_13;
	pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(GPIOA, &pinCfg);

	// PB13 (output PUSH pull Mode)

	pinCfg.GPIO_PinNumber = GPIO_PIN_13;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	pinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(GPIOB, &pinCfg);

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
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0) // press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0); // single press.
		}

		// PA1 external Pull down resistant
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1) // Multi press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		my_wait(10);
	}

}










