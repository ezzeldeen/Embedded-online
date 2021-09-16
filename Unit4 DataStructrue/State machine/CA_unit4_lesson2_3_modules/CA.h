/*
 * CA.h
 *
 *  Created on: Sep 3, 2021
 *      Author: Ezz Eldeen
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"
// Define States
enum
{
	CA_waiting,
	CA_driving
} CA_state_id ;


// declare states function CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

// STATE Pointer to func.
extern void (*CA_state)();

#endif /* CA_H_ */
