/*
 *  Stm32_F103C6_GPIO_driver.c
 *  Created on: Nov 15, 2021
 *  Author: Ezz Eldeen
 */


#include "Stm32_F103C6_GPIO_driver.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}

/**================================================================
 * @Fn				- MCAL_GPIO_Init
 * @brief			- Initializes the GPIOx Piny according to the specified parameters in the PinConfig
 * @param [in] 		- GPIOx: where x can be (A->E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinCongfig pointer to a GPIO_PinConfig_t structure that contains the configuration
 * 							information for the specified GPIO pin.
 * @retval 			- none
 * Note				- Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 					  		But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINs from the MCU
 */
void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PinConfig_t* PinConfig)
{
	// Port config reg Low (GPIOx_CRL) config PINs from 0 >>> 7
	// port config reg High (GPIOx_CRH) config PINs from 8 >>> 15
	volatile uint32_t* configregister = NULL;
	uint8_t PIN_Config = 0;
	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL: &GPIOx->CRH;
	// clear CNF8[1:0]	MODE8[1:0]
	(*configregister) &= ~(0xf << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	// if pin is output
	if ( (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
		// Set CNF[1:0] MODE8[1:0]
		PIN_Config = ((((PinConfig->GPIO_MODE -4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0f);
	}

	// if pin is input MODE = 00: Input mode (reset state)
	else
	{
		if ((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			// Set CNF8[1:0]  MODE8[1:0] 00
			PIN_Config = ((((PinConfig->GPIO_MODE) << 2)| 0x0 ) & 0x0f);
		}
		else if(PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT) // Consider it as input floating
		{
			// Set CNF8[1:0] MODE8[1:0]00
			PIN_Config = ((((GPIO_MODE_INPUT_FLO) << 2) | 0x0 ) & 0x0f);
		}
		else // PU PD Input
		{
			PIN_Config = ((((GPIO_MODE_INPUT_PU) << 2) | 0x0) & 0x0f);

			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				// PxODR = 1 Input pull-up :Table 20 Port bit configuration table
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber) ;
			}
			else
			{
				// PxODR = 0 Input pull-down :Table 20 Port bit configuration table
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber) ;
			}
		}
	}
	// write on CRL or CRH
	(*configregister) |= ((PIN_Config) << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

}

/**================================================================
 * @Fn				- MCAL_GPIO_DeInit
 * @brief			- reset all the GPIO Registers.
 * @param [in] 		- GPIOx: where x can be (A->E depending on device used) to select the GPIO peripheral
 * @retval 			- none
 * Note				- none
 */
void MCAL_GPIO_DeInit (GPIO_TypeDef *GPIOx)
{
	/*
	GPIOx->BRR = 0x00000000 ;
	GPIOx->BSRR = 0x00000000 ;
	GPIOx->CRH = 0x44444444 ;
	GPIOx->CRL = 0x44444444 ;
	// GPIOx->IDR = 0x00000000 ;	Read Only
	GPIOx->LCKR = 0x00000000 ;
	GPIOx->ODR = 0x00000000 ;
	 */

	// Using Reset Controller
	// APB2 peripheral reset register (RCC_APB2RSTR)
	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);	// bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);	// bit 3 IOPARST: IO port B reset
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);	// bit 2 IOPARST: IO port C reset
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);	// bit 2 IOPARST: IO port D reset
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);	// bit 2 IOPARST: IO port E reset
		RCC->APB2RSTR &= ~(1<<6);
	}

}

/**================================================================
 * @Fn				- MCAL_GPIO_ReadPin
 * @brief			- Read specific PIN.
 * @param [in] 		- GPIOx: where x can be (A->E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinNumber: Set pin number according GPIO_PINS_define
 * @retval 			- Input Pin value (two values based on @ref GPIO_PIN_state
 * Note				- none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	uint8_t bitStatus ;
	if (((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		bitStatus = GPIO_PIN_SET;
	}
	else
	{
		bitStatus = GPIO_PIN_RESET;
	}
	return bitStatus;
}

/**================================================================
 * @Fn				- MCAL_GPIO_ReadPort
 * @brief			- Read the input port value
 * @param [in] 		- GPIOx: where x can be (A->E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinNumber: Set pin number according GPIO_PINS_define
 * @retval 			- the input Port value
 * Note				- none
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	uint16_t portValue ;
	portValue = (uint16_t)(GPIOx->IDR);
	return portValue;
}

/**================================================================
 * @Fn				- MCAL_GPIO_WritePin
 * @brief			- Write on specific input pin
 * @param [in] 		- GPIOx: where x can be (A->E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinNumber: specifies the port bin to read set by @ref GPIO_PINS_define
 * @param [in] 		- Value: Pin Value
 * @retval			- none
 * Note				- none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value)
{
	if (Value != GPIO_PIN_RESET)
	{
		//	GPIOx->ODR |= GPIO_PIN_SET;
		GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else
	{
		GPIOx->BRR = (uint32_t)PinNumber;
	}
}

/**================================================================
 * @Fn				- MCAL_GPIO_WritePort
 * @brief			- Write on output port
 * @param [in] 		- GPIOx: where x can be (A->E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinNumber: specifies the port bin to read set by @ref GPIO_PINS_define
 * @retval			- none
 * Note				- none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;
}

/**================================================================
 * @Fn				- MCAL_GPIO_TogglePin
 * @brief			- Toggle the specified GPIO pin
 * @param [in] 		- GPIOx: where x can be (A->E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinNumber: specifies the port bin to toggle set by @ref GPIO_PINS_define
 * @retval			- none
 * Note				- none
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber);
}

/**================================================================
 * @Fn				- MCAL_GPIO_LockPin
 * @brief			- The locking mechanism allows the IO configuration to be frozen
 * @param [in] 		- GPIOx: where x can be (A->E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinNumber: specifies the port bin to read set by @ref GPIO_PINS_define
 * @retval			- OK if pin Config is locked or ERROR if pin is not locked (OK & ERROR are defined @ref GPIO_RETURN_LOCK
 * Note				- none
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read any time. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked.

	// Set LCKK[16]
	volatile uint32_t tmp = 1<<16;

	// Set the LCKy
	tmp |= PinNumber ;

	//	Write 1
	GPIOx->LCKR = tmp;
	//	Write 0
	GPIOx->LCKR = PinNumber;
	//	Write 1
	GPIOx->LCKR = tmp;

	//	Read 0
	tmp = GPIOx->LCKR ;
	//	Read 1 (this read is optional but confirms that the lock is active)
	if( (uint32_t) (GPIOx->LCKR & (1<<16)))
	{
		return GPIO_RETURN_LOCK_Enabled ;
	}
	else
	{
		return GPIO_RETURN_LOCK_ERROR ;
	}
}











