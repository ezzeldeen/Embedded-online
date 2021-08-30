/*
 *  stack.h
 *  Created on: Aug 24, 2021
 *  Author: Ezz Eldeen
 */

#ifndef STACK_H_
#define STACK_H_

#include "stdlib.h"
#include "stdio.h"

// Configuration of Stack data_type.
#define Stack_type int

// Stack Structure.
typedef struct
{
	int top;
	unsigned int capacity;
	Stack_type* array;
} Stack ;

// APIs
// 1. Create the stack & init it.
int Stack_Init( Stack* stack, Stack_type* ptr, unsigned int stack_capacity );
int Stack_IsFull( Stack* stack);
int Stack_IsEmpty( Stack* stack);
int Stack_push(Stack* stack,Stack_type item);
Stack_type Stack_pop(Stack* stack);
Stack_type Stack_peek(Stack* stack);
void Stack_Status (Stack* stack);

#endif // STACK_H_
