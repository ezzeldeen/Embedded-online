/*
 * CA.c
 *
 *  Created on: Sep 3, 2021
 *      Author: Ezz Eldeen
 */

#include "CA.h"

int CA_speed =0;
int CA_distance =0;
int CA_threshold =50;

// STATE Pointer to func.
void (*CA_state)();

void US_Set_distance (int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US ------distance = %d ---------> CA \n",CA_distance);
}


STATE_define(CA_waiting)
{
	//state_name
	CA_state_id = CA_waiting ;
	printf("US ------distance=%d speed=%d ---------> CA",CA_distance, CA_speed);

	//state_action
	//DC_motor(speed)
	CA_speed = 0;
	DC_motor (CA_speed);

	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("CA_Waiting State: distance =%d Speed= %d \n", CA_distance, CA_speed);
}

STATE_define(CA_driving)
{
	//state_name
	CA_state_id = CA_driving ;
	printf("CA_driving State: distance =%d Speed= %d \n", CA_distance, CA_speed);

	//state_action
	//DC_motor(speed)
	CA_speed = 30;

	DC_motor (CA_speed);
}
/*
int UltraSonic_distance_random(int l, int r, int count)
{
	int i;
	for(i=0; i<count; i++)
	{
		int rand_num = (rand() % (r-l+1))+l;
		return rand_num;
	}
}
*/





