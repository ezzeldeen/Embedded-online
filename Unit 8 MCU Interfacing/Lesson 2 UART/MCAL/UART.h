/*
 * UART.h
 *
 *  Created on: Jan 9, 2022
 *      Author: Ezz Eldeen
 */

#ifndef UART_H_
#define UART_H_

#include "MemMap32.h"
#include "macros.h"

void UART_Init(void);
void UART_Send(unsigned char data );
unsigned char UART_Receive(void);

void UART_SendNumberU32(unsigned int num);
unsigned int UART_ReceiveNumberU32(void);

void UART_Send_String (char* str) ;
char* UART_Receive_String (void) ;

#endif /* UART_H_ */
