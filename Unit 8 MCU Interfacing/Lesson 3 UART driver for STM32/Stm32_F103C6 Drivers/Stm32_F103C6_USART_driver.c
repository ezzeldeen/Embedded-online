/*
 *  Stm32_F103C6_USART_driver.c
 *  Created on: Nov 15, 2021
 *  Author: Ezz Eldeen
 */

#include "Stm32_F103C6_USART_driver.h"


/*
 * ================================================================
 *                      Generic Variables
 * ================================================================
 */

UART_Config* Global_UART_Config;


/*
 * ================================================================
 *                      Generic Functions
 * ================================================================
 */


/*
 * ================================================================
 *                            APIs
 * ================================================================
 */




/**================================================================
 * @Fn				- MCAL_UART_Init
 * @brief			- Init UART Asynch only
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @param [in] 		- UART_Config: All UART config
 * @retval 			- none
 * Note				- support for now Asynch mode & clock 8 MHz
 */
void MCAL_UART_Init (USART_TypeDef* USARTx, UART_Config* UART_Config)
{
	uint32_t pclk, BRR;
	Global_UART_Config = UART_Config;

	// enable the clock for given USART peripheral
	if(USARTx == USART1)
		RCC_USART1_CLK_EN();

	else if (USARTx == USART2)
		RCC_USART2_CLK_EN();

	else if (USARTx == USART3)
		RCC_USART3_CLK_EN();

	// Enable USART Module
	// bit 13 UE: USART enable
	USARTx->CR1 |= 1<<13;

	// Enable USART Tx Rx engines according to the USART_Mode config item
	// USART_CR1 bit 3 TE: transmitter enable & bit 2 RE: receiver enable
	USARTx->CR1 |= UART_Config->USART_Mode;

	// Payload width
	// USARTx->CR1 bit 12 M: word length
	USARTx->CR1 |= UART_Config->Payload_Length;

	// config of parity control bit field
	// USARTx->CR1 bit 10 PCE: Parity Control enable bit 9 PS: Parity selection
	USARTx->CR1 |= UART_Config->Parity;

	// config the no. of stop bits
	// USART_CR2 bits 13:12 STOP: stop bits
	USARTx->CR2 |= UART_Config->StopBits;

	// USART hw flow control
	// USART_CR3 bit 9 CTSE: CTS enable bit 8 RTSE: RTS  enable
	USARTx->CR3 |= UART_Config->HwFlowCtl;

	// config of BRR (baudrate reg)
	// PCLK1 for USART2, 3
	// PCLK2 for USART1

	if (USARTx == USART1)
	{
		pclk = MCAL_RCC_GetPCLK2Freq();
	}
	else
	{
		pclk = MCAL_RCC_GetPCLK1Freq();
	}

	BRR = UART_BRR_Register(pclk, UART_Config->BaudRate);
	USARTx->BRR = BRR;

	// ENABLE / DISABLE Interrupt
	// USART_CR1
	if (UART_Config->IRQ_Enable != UART_IRQ_Enable_NONE)
	{
		USARTx->CR1 |= (UART_Config->IRQ_Enable);

		// Enable NVIC for USARTx IRQ
		if (USARTx == USART1)
			NVIC_IRQ37_USART1_Enable;

		else if (USARTx == USART2)
			NVIC_IRQ38_USART2_Enable;

		else if (USARTx == USART3)
			NVIC_IRQ39_USART3_Enable;


	}


}

/**================================================================
 * @Fn				- MCAL_UART_DEInit
 * @brief			- DEInit UART Asynch only
 * @param [in] 		- USARTx where x can be (1..3 depending on device used)
 * @param [in] 		- pTxBuffer buffer
 * @param [in] 		- Polling Enable or disable
 * @retval 			- none
 * Note				- init UART first
 */
void MCAL_UART_DeInit (USART_TypeDef* USARTx)
{

	if (USARTx == USART1)
	{
		RCC_USART1_Reset();
		NVIC_IRQ37_USART1_Disable;
	}

	else if (USARTx == USART3)
	{
		RCC_USART3_Reset();
		NVIC_IRQ39_USART3_Disable;
	}

	else if (USARTx == USART2)
	{
		RCC_USART2_Reset();
		NVIC_IRQ38_USART2_Disable;
	}
}

/**================================================================
 * @Fn				- MCAL_UART_SendData
 * @brief			- Send buffer on UART
 * @param [in] 		- USARTx where x can be (1..3 depending on device used)
 * @param [in] 		- pTxBuffer buffer
 * @param [in] 		- Polling Enable or disable
 * @retval 			- none
 * Note				- init UART first
 * 					- when transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register)
 * 					- the value written in the MSB ( bit 7 or bit 8 depending on the data length ) has no effect
 * 					- because it is replaced by the parity
 * 					- when receiving with the parity enabled the value read in the MSB bit is the received parity bit
 */
void MCAL_UART_SendData(USART_TypeDef* USARTx, uint16_t* pTxBuffer, enum Polling_mechanism PollingEn)
{

	// wait until TXE flag is set in the SR
	if (PollingEn == enable)
		while(! (USARTx->SR & 1<<7 ) );

	// Check the USART_WordLength item for 9BIT or 8BIT in a frame
	// when transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register)
	// the value written in the MSB ( bit 7 or bit 8 depending on the data length ) has no effect
	// because it is replaced by the parity
	// when receiving with the parity enabled the value read in the MSB bit is the received parity bit

	if (Global_UART_Config->Payload_Length == UART_Payload_Legth_9B)
	{
		USARTx->DR = (*pTxBuffer & (uint16_t) 0x01FF);
	}
	else
	{
		// this is 8bit data transfer
		USARTx->DR = (*pTxBuffer & (uint16_t) 0xFF);
	}
}

void MCAL_UART_ReceiveData(USART_TypeDef* USARTx, uint16_t* pRxBuffer, enum Polling_mechanism PollingEn)
{
	// wait until RXNE flag is set in the SR
	if (PollingEn == enable)
	{
		while (!(USARTx->SR & 1<<5 ));
	}

	// check the USART_WordLength item for 9Bit or 8Bit in a frame
	if (Global_UART_Config->Payload_Length == UART_Payload_Legth_9B)
	{
		if (Global_UART_Config->Parity == UART_Parity_NONE)
		{
			// no parity so all 9bit are considered data
			*((uint16_t*) pRxBuffer ) = USARTx->DR;
		}
		else
		{
			// Parity is used so 8bits will be of user data and 1 bit is parity
			*((uint16_t*) pRxBuffer ) = ( USARTx->DR & (uint8_t)0xFF );
		}
	}
	else
	{
		// this is 8bit data
		if(Global_UART_Config->Parity == UART_Parity_NONE)
		{
			// no parity so all 8bits are considered data
			*((uint16_t*) pRxBuffer) = (USARTx->DR & (uint8_t)0xFF );
		}
		else
		{
			// parity is used so 7 bits will be data and 1 bit is parity
			*((uint16_t*) pRxBuffer) = (USARTx->DR & (uint8_t)0x7F );
		}
	}

}

void MCAL_UART_WAIT_TC (USART_TypeDef* USARTx)
{
	// wait till TC flag is set in the SR
	while (!(USARTx->SR & 1<<6 ));
}

void MCAL_UART_GPIO_Set_Pins (USART_TypeDef* USARTx)
{
	GPIO_PinConfig_t PinCfg ;

	if (USARTx == USART1)
	{

		// PA9 TX
		// PA10 RX
		// PA11 CTS
		// PA12 RTS

		// PA9 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_9;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		// PA10 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		if (Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			// PA11 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_11;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}

		if (Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			// PA12 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_12;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}


	}



	if (USARTx == USART2)
	{

		// PA2 TX
		// PA3 RX
		// PA0 CTS
		// PA1 RTS

		// PA2 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_2;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		// PA3 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_3;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		if (Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			// PA0 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_0;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}

		if (Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			// PA1 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_1;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}


	}




	if (USARTx == USART3)
	{

		// PB10 TX
		// PB11 RX
		// PB13 CTS
		// PB14 RTS

		// PB10 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		// PB11 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_11;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		if (Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			// PB13 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

		}

		if (Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			// PB14 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

		}


	}
}




// ISR
void USART1_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();
}

void USART2_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();

}

void USART3_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();

}
