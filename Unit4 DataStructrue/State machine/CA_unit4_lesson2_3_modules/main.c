/*
 * main.c
 *
 *  Created on: Sep 3, 2021
 *      Author: Ezz Eldeen
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	US_init();
	DC_init();
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

void main()
{
	volatile int d;
	printf("fsdf");

	setup();
	printf("fsdf");

	while (1)
	{
		printf("fsdf");

		//call state for each block
		US_state();
		CA_state();
		DC_state();

		for(d=0; d<=100000;d++);
	}

}




