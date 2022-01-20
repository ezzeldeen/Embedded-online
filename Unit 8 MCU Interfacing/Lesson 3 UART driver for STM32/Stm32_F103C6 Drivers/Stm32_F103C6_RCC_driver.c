/*
 *  Stm32_F103C6_RCC_driver.c
 *  Created on: Nov 15, 2021
 *  Author: Ezz Eldeen
 */

#include "Stm32_F103C6_RCC_driver.h"




// Bits 10:8 ppre1 APB low speed prescaler (APB1)
//set and cleared by software to control the division factor of the APB low speed clock (PCLK1)
// warning: the SW has to be set correctly these bits to not exceed 36 MHz on this domain
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
const uint8_t APBPrescTable[8U] = {0,0,0,0,1,2,3,4}; // shift 1 right == multiply by 2


// Bits 10:8 ppre1 APB low speed prescaler (APB1)
//set and cleared by software to control the division factor of the APB low speed clock (PCLK1)
// warning: the SW has to be set correctly these bits to not exceed 36 MHz on this domain
//0xxx: HCLK not divided
//1000: HCLK divided by 2
//1001: HCLK divided by 4
//1010: HCLK divided by 8
//1011: HCLK divided by 16
//1100: HCLK divided by 64
//1101: HCLK divided by 128
//1110: HCLK divided by 256
//1111: HCLK divided by 512
const uint8_t AHBPrescTable[16U] = {0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9}; // shift 1 right == multiply by 2



uint32_t MCAL_RCC_GetHCLKFreq (void)
{
	// bits 7:4 HPRE: AHB prescaler
	return (MCAL_RCC_GetSYS_CLKFreq () >> AHBPrescTable[((RCC->CFGR >> 4) & 0xF)]);
}

uint32_t MCAL_RCC_GetPCLK1Freq (void)
{
	return (MCAL_RCC_GetHCLKFreq () >> APBPrescTable[((RCC->CFGR >> 8) & 0b111)]);
}

uint32_t MCAL_RCC_GetPCLK2Freq (void)
{
	// bits 13:11 PPRE2: APB high speed prescaler (APB2)
	return (MCAL_RCC_GetHCLKFreq () >> APBPrescTable[((RCC->CFGR >> 11) & 0b111)]);
}

uint32_t MCAL_RCC_GetSYS_CLKFreq (void)
{
	// bits 3:2 SWS: system clock switch status
	// set and cleared by hardware to indicate which clock source is used as system clock
	// 00: HSI oscillator used as system clock
	// 01: HSE oscillator used as system clock
	// 10: PLL used as system clock
	// 11: not applicable
	switch ((RCC->CFGR >> 2) & 0b11)
	{
	case 0:
		return HSI_RC_Clk;
		break;
	case 1:
			return HSE_Clock;
			break;
	case 2:
			return 16000000;
			break;
	}
}
