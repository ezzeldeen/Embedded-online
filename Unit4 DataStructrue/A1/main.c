/*
 *  main.c
 *  Created on: Aug 24, 2021
 *  Author: Ezz Eldeen
 */

#include "includes.h"

int main ()
{
	//Stack* Ezz = Stack_dynamic_Create(10);

	Stack* Ezz = Stack_static_Create(10);
	Stack_Status(Ezz);

	Stack_push(Ezz, 10);
	Stack_push(Ezz, 20);
	Stack_push(Ezz, 30);
	Stack_push(Ezz, 40);
	Stack_push(Ezz, 50);
	Stack_Status(Ezz);
	Stack_push(Ezz, 60);
	Stack_Status(Ezz);
	Stack_push(Ezz, 70);
	Stack_push(Ezz, 80);
	Stack_push(Ezz, 90);
	Stack_push(Ezz, 100);
	Stack_push(Ezz, 140);
	Stack_Status(Ezz);

    printf("%d peek of the stack\n", Stack_peek(Ezz));
    printf("%d popped from stack\n", Stack_pop(Ezz));
    printf("%d popped from stack\n", Stack_pop(Ezz));
    printf("%d popped from stack\n", Stack_pop(Ezz));
	Stack_Status(Ezz);

    printf("%d popped from stack\n", Stack_pop(Ezz));
    printf("%d popped from stack\n", Stack_pop(Ezz));
    printf("%d popped from stack\n", Stack_pop(Ezz));
    printf("%d popped from stack\n", Stack_pop(Ezz));
    printf("%d popped from stack\n", Stack_pop(Ezz));
    printf("%d popped from stack\n", Stack_pop(Ezz));
	Stack_Status(Ezz);

    printf("%d popped from stack\n", Stack_pop(Ezz));
	Stack_Status(Ezz);
    printf("%d popped from stack\n", Stack_pop(Ezz));

	return 0;
}
