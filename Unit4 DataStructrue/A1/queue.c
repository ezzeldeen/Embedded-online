/*
 * queue.c
 *
 *  Created on: Aug 24, 2021
 *      Author: Ezz Eldeen
 */
#include "queue.h"

bool Queue_Init( Queue* queue, Queue_type* ptr, unsigned int queue_capacity )
{
	if(ptr == NULL)
		return false ;
	else
	{
		queue->base = ptr ;
		queue->head = ptr ;
		queue->tail = ptr ;
		queue->length = queue_capacity ;
		queue->count = 0 ;
	}
	return true;
}

bool Queue_IsFull( Queue* queue)
{
	if (queue->count == queue->length)
		return true;
	else
	{
		return false;
	}
}

bool Queue_IsEmpty( Queue* queue)
{
	if (queue->count == 0)
		return true;
	else
	{
		return false;
	}
}

bool Queue_enqueue(Queue* queue, Queue_type item)
{
	if (Queue_IsFull(queue))
		return false;

	*(queue->head) = item;
	printf("%d pushed to queue\n", item);

	queue->count++;
	// circular queue
	if (queue->head == ( queue->base + queue->length -1))
	{
		queue->head = queue->base;
	}
	else
	{
		queue->head++;
	}
	return true;
}

Queue_type Queue_dequeue(Queue* queue)
{
	if (Queue_IsEmpty(queue))
		return NULL;

	Queue_type item = *(queue->tail);
	queue->count-- ;
	// circular queue
	if (queue->tail == ( queue->base + queue->length -1))
	{
		queue->tail = queue->base;
	}
	else
	{
		queue->tail++;
	}
	return item;
}

Queue_type Queue_head(Queue* queue)
{
	if (Queue_IsEmpty(queue))
		return NULL;

	Queue_type item = *(queue->head);
	return item;
}

Queue_type Queue_tail(Queue* queue)
{
	if (Queue_IsEmpty(queue))
		return NULL;

	Queue_type item = *(queue->tail);
	return item;
}

void Queue_Status (Queue* queue)
{
	if (Queue_IsFull(queue))
		printf("Queue is Full\n");
	else if (Queue_IsEmpty(queue))
		printf("Queue is Empty\n");
	else
		printf("Queue is partily\n");
}


