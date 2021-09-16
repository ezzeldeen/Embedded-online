/*
 * DC.c
 *
 *  Created on: Sep 3, 2021
 *      Author: Ezz Eldeen
 */

#include "DC.h"

int DC_speed =0;

// STATE Pointer to func.
void (*DC_state)();

void DC_init ()
{
	printf("DC_init \n");

}

void DC_motor (int s)
{
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA ------speed = %d ---------> DC \n",DC_speed);

}


STATE_define(DC_idle)
{
	//state_name
	DC_state_id = DC_idle ;
	printf("DC_idle State: Speed= %d \n", DC_speed);

}

STATE_define(DC_busy)
{
	//state_name
	DC_state_id = DC_busy ;
	DC_state = STATE(DC_idle);
	printf("DC_busy State: Speed= %d \n", DC_speed);

}





