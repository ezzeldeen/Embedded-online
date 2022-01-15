/*
 * keypad.h
 *  Author: Ezz
 */


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include<util/delay.h>
#include "MemMap32.h"

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT PORTD
#define DataDir_KEYPAD_PORT DDRD
#define keypadPIN PIND

void Keypad_init();
char Keypad_getkey();

#endif /* KEYPAD_H_ */
