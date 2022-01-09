/*
 * DC.h
 *
 *  Created on: Sep 3, 2021
 *      Author: Ezz Eldeen
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
// Define States
enum
{
	DC_idle,
	DC_busy
} DC_state_id ;


// declare states function CA
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

// STATE Pointer to func.
extern void (*DC_state)();

#endif /* DC_H_ */
