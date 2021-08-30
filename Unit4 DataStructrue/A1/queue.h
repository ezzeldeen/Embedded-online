/*
 *  queue.h
 *  Created on: Aug 24, 2021
 *  Author: Ezz Eldeen
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "includes.h"

// Configuration of Queue data_type.
#define Queue_type int

typedef struct
{
	unsigned int length;
	unsigned int count;
	Queue_type* base;
	Queue_type* head;
	Queue_type* tail;
} Queue;

// APIs
// 1. Create the stack & init it.
bool Queue_Init( Queue* queue, Queue_type* ptr, unsigned int queue_capacity );
bool Queue_IsFull( Queue* queue);
bool Queue_IsEmpty( Queue* queue);
bool Queue_enqueue(Queue* queue, Queue_type item);
Queue_type Queue_dequeue(Queue* queue);
Queue_type Queue_head(Queue* queue);
Queue_type Queue_tail(Queue* queue);
void Queue_Status (Queue* queue);

#endif /* QUEUE_H_ */
