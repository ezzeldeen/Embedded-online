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
#include "Stm32_F103C6_EXTI_driver.h"
#include "Stm32_F103C6_USART_driver.h"
#include "keypad.h"
#include "lcd.h"

void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN() ;
	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN() ;
	RCC_AFIO_CLK_EN();
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

unsigned int IRQ_Flag;

void EXTI9_Callback ()
{
	IRQ_Flag = 1;
	LCD_WRITE_STRING("IRQ EXTI9 is happening _|-");
}

unsigned char ch;

void EEE_UART_IRQ_CallBack (void)
{
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);

}

int main(void)
{

	UART_Config uartCFG;
	clock_init();

	uartCFG.BaudRate = UART_BaudRate_115200;
	uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE;
	uartCFG.IRQ_Enable = UART_IRQ_Enable_RXNEIE;  //UART_IRQ_Enable_NONE;
	uartCFG.P_IRQ_CallBack = EEE_UART_IRQ_CallBack; // NULL;
	uartCFG.Parity = UART_Parity_NONE;
	uartCFG.Payload_Length = UART_Payload_Legth_8B;
	uartCFG.StopBits = UART_StopBits_1;
	uartCFG.USART_Mode = UART_Mode_TX_RX;
	MCAL_UART_Init(USART1, &uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART1);

	while (1)
	{

	}
}



/*
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
 */
/*

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10

void clock_init() {
	//Enable clock GPIOA
	RCC_GPIOA_CLK_EN();
	//Enable clock GPIOB Bit 3 IOPBEN: IO port B clock enable
	RCC_GPIOB_CLK_EN();
}
void GPIO_init() {

	GPIO_PinConfig_t PinCfg;

	//PA1 input HighZ Floating input (reset state)
//	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
//	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(GPIOA, &PinCfg);

//PB1 (output PUSH pull Mode)
//01: Output mode, max speed 10 MHz.
//CNF 00: General purpose output push-pull
	PinCfg.GPIO_PinNumber = GPIO_PIN_9;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_10;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_11;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//============================

	//PA13 input HighZ Floating input (reset state)
	PinCfg.GPIO_PinNumber = GPIO_PIN_14;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB13 (output PUSH pull Mode)
	PinCfg.GPIO_PinNumber = GPIO_PIN_15;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}
void wait_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}
int main(void) {

	clock_init();
	LCD_INIT();
	unsigned char key_pressed;
	LCD_WRITE_STRING("HEY");
	wait_ms(30);
	LCD_clear_screen();
	GPIO_init();
	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (unsigned char i = 0; i < 11; i++) {
		LCD_WRITE_CHAR(LCD_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, DISPLAY[i] << 9);//  write data on to the LED port
		wait_ms(100);
		// wait for 1 second
	}
//	MCAL_GPIO_WritePort(GPIOB, 0xDE);
//	wait_ms(100);
	LCD_clear_screen();
	Keypad_init();
	LCD_WRITE_STRING("Keypad is ready");
	wait_ms(30);
	LCD_clear_screen();

	while (1) {

		key_pressed = Keypad_getkey();
		switch (key_pressed) {
		case 'A':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_CHAR(key_pressed);
			break;
		}
//		//PA1 >>>Connected external PUR
//
//		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0) // press
//		{
//			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
//			while  (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)  ; //Single Pressing
//		}
//		//PA13 >>>Connected external PDR
//		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1) //Multi Pressing
//		{
//			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
//		}
//		LCD_WRITE_STRING("HEY");
//		wait_ms(30);
//		LCD_clear_screen();
	}
}



 */






