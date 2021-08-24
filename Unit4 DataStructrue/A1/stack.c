/*
 * stack.c
 *
 *  Created on: Aug 24, 2021
 *      Author: Ezz Eldeen
 */

#define Stack_type int

#include "stack.h"
int v[10]={0,};
Stack* Stack_dynamic_Create( unsigned int stack_capacity )
{
	Stack* stack ;
	stack->capacity = stack_capacity;
	stack->top = -1;
	stack->array = (Stack_type*)calloc(stack->capacity , sizeof(Stack_type));
	return stack;
}

Stack* Stack_static_Create( unsigned int stack_capacity )
{
	Stack* stack ;
	stack->capacity = stack_capacity;
	stack->top = -1;
	Stack_type arr[stack_capacity];
	stack->array = arr;
	return stack;
}

int Stack_IsFull( Stack* stack_Obj)
{
	if (stack_Obj->top == stack_Obj->capacity-1)
		return 1;
	return 0;
}

int Stack_IsEmpty( Stack* stack_Obj)
{
	if (stack_Obj->top == -1)
		return 1;
	return 0;
}

int Stack_push(Stack* stack_Obj,Stack_type item)
{
	if(Stack_IsFull(stack_Obj))
		return 0;
	else
	{
		stack_Obj->array[(++stack_Obj->top)] = item;
		printf("%d pushed to stack\n", item);

	}
	return 1;
}

Stack_type Stack_pop(Stack* stack_Obj)
{
	if (Stack_IsEmpty(stack_Obj))
		return NULL;
	else
	{
		return stack_Obj->array[(stack_Obj->top--)];
	}
}

Stack_type Stack_peek(Stack* stack_Obj)
{
	if (Stack_IsEmpty(stack_Obj))
		return NULL;
	else
	{
		return stack_Obj->array[stack_Obj->top];
	}
}

void Stack_Status (Stack* stack_Obj)
{
	if (Stack_IsFull(stack_Obj))
		printf(" Stack is Full\n");
	else if (Stack_IsEmpty(stack_Obj))
		printf(" Stack is Empty\n");
	else
		printf(" Stack is partily \n");
}
