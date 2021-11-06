/*
 * RegFile.h
 *
 *  Created on: Nov 6, 2021
 *      Author: Ezz Eldeen
 */

#ifndef REGFILE_H_
#define REGFILE_H_

#define PORTA *((volatile unsigned char *) 0X3B)
#define DDRA *((volatile unsigned char *) 0X3A)
#define PINA *((volatile unsigned char *) 0X39)

#define PORTB *((volatile unsigned char *) 0X38)
#define DDRB *((volatile unsigned char *) 0X37)
#define PINB *((volatile unsigned char *) 0X36)

#define PORTC *((volatile unsigned char *) 0X35)
#define DDRC *((volatile unsigned char *) 0X34)
#define PINC *((volatile unsigned char *) 0X33)

#define PORTD *((volatile unsigned char *) 0X32)
#define DDRD *((volatile unsigned char *) 0X31)
#define PIND *((volatile unsigned char *) 0X30)


// CKSEL3..0 //0100 8mHz


#endif  REGFILE_H_
