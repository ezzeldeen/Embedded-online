/*
 * CA.h
 *
 *  Created on: Sep 3, 2021
 *      Author: Ezz Eldeen
 */

#ifndef US_H_
#define US_H_

#include "state.h"
// Define States
enum
{
	US_busy
} US_state_id ;


// declare states function CA
STATE_define(US_busy);

void US_init();
// STATE Pointer to func.
extern void (*US_state)();

#endif /* US_H_ */
