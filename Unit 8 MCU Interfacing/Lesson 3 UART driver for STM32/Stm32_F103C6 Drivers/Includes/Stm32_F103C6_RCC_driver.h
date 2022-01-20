/*
 * Stm32_F103C6_RCC_driver.h
 *
 *  Created on: Nov 15, 2021
 *      Author: Ezz Eldeen
 */

#ifndef STM32_F103C6_RCC_DRIVER_H_
#define STM32_F103C6_RCC_DRIVER_H_

// Includes
#include "stm32f103c6.h"
#include "Stm32_F103C6_GPIO_driver.h"

#define HSE_Clock		(uint32_t)16000000
#define HSI_RC_Clk		(uint32_t)8000000

uint32_t MCAL_RCC_GetHCLKFreq (void) ;
uint32_t MCAL_RCC_GetPCLK1Freq (void) ;
uint32_t MCAL_RCC_GetPCLK2Freq (void) ;
uint32_t MCAL_RCC_GetSYS_CLKFreq (void) ;

#endif /* INCLUDES_STM32_F103C6_RCC_DRIVER_H_ */
