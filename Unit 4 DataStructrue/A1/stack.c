/*
 *  stack.c
 *  Created on: Aug 24, 2021
 *  Author: Ezz Eldeen
 */

#include "stack.h"

int Stack_Init( Stack* stack, Stack_type* ptr_arr, unsigned int stack_capacity )
{
	if (ptr_arr == NULL )
		return 0;
	if (stack == NULL )
		return 0;

	stack->capacity = stack_capacity;
	stack->top = -1;
	stack->array = ptr_arr;
	return 1;
}

int Stack_IsFull( Stack* stack)
{
	if (stack->top == stack->capacity-1)
		return 1;
	return 0;
}

int Stack_IsEmpty( Stack* stack)
{
	if (stack->top == -1)
		return 1;
	return 0;
}

int Stack_push(Stack* stack,Stack_type item)
{
	if(Stack_IsFull(stack))
		return 0;

	stack->array[(++stack->top)] = item;
	printf("%d pushed to stack\n", item);

	return 1;
}

Stack_type Stack_pop(Stack* stack)
{
	if (Stack_IsEmpty(stack))
		return NULL;

	return stack->array[(stack->top--)];
}

Stack_type Stack_peek(Stack* stack)
{
	if (Stack_IsEmpty(stack))
		return NULL;

	return stack->array[stack->top];
}

void Stack_Status (Stack* stack)
{
	if (Stack_IsFull(stack))
		printf("Stack is Full\n");
	else if (Stack_IsEmpty(stack))
		printf("Stack is Empty\n");
	else
		printf("Stack is partily\n");
}
