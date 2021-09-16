/*
 * US.c
 *
 *  Created on: Sep 3, 2021
 *      Author: Ezz Eldeen
 */

#include "US.h"

int US_distance =0;

// STATE Pointer to func.
void (*US_state)();
int UltraSonic_distance_random(int l, int r, int count);

void US_init()
{
	printf("US_init \n");
}

STATE_define(US_busy)
{
	//state_name
	US_state_id = US_busy ;

	//state_action
	US_distance = UltraSonic_distance_random(45,55,1);
	printf("US_Waiting State: distance =%d\n", US_distance);
	US_Set_distance(US_distance);
	US_state = STATE(US_busy);
}

int UltraSonic_distance_random(int l, int r, int count)
{
	int i;
	for(i=0; i<count; i++)
	{
		int rand_num = (rand() % (r-l+1))+l;
		return rand_num;
	}
}






