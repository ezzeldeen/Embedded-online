/*
 *  main.c
 *  Created on: Aug 24, 2021
 *  Author: Ezz Eldeen
 */

#include "includes.h"

int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct Sdata data1, data2, data3, data4;
	data1.ID=1;
	data1.height=171;
	data1.name[0]='A';
	data1.name[1]='\0';
	data2.ID=2;
	data2.height=172;
	data2.name[0]='B';
	data2.name[1]='\0';
	data3.ID=3;
	data3.height=173;
	data3.name[0]='C';
	data3.name[1]='\0';
	data4.ID=4;
	data4.height=174;
	data4.name[0]='D';
	data4.name[1]='\0';


	struct Node* school= NULL;
	LinkedList_AddNode (&school, data1);
	LinkedList_AddNode (&school, data2);
	LinkedList_AddNode (&school, data3);
	LinkedList_AddNode (&school, data4);
	LinkedList_Print(school);
	printf("\n===================\n");


	//Sdata_Print(LinkedList_get_nth_fromEnd(school, 4));
	//Sdata_Print(LinkedList_middle_node(school));

	//LinkedList_make_circular(school);
	//printf("%d\n", LinkedList_detect_loop (school));

	reverse(&school);
	LinkedList_Print(school);







	/*
	Queue Ezz_q ;
	Queue_type arr[10];
	Queue_Init(&Ezz_q, arr, 10);
	Queue_enqueue(&Ezz_q, 10);
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	Queue_enqueue(&Ezz_q, 20);
	Queue_enqueue(&Ezz_q, 30);
	Queue_enqueue(&Ezz_q, 40);
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	Queue_enqueue(&Ezz_q, 50);
	Queue_enqueue(&Ezz_q, 60);
	Queue_enqueue(&Ezz_q, 70);
	Queue_enqueue(&Ezz_q, 80);
	Queue_enqueue(&Ezz_q, 90);
	Queue_enqueue(&Ezz_q, 100);
	Queue_enqueue(&Ezz_q, 140);
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	Queue_enqueue(&Ezz_q, 150);
	Queue_enqueue(&Ezz_q, 160);
	Queue_enqueue(&Ezz_q, 170);
	Queue_enqueue(&Ezz_q, 180);
	Queue_enqueue(&Ezz_q, 190);
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	printf("%d poped out of queue\n",Queue_dequeue(&Ezz_q));
	 */



	/*
	Stack Ezz;
	// Stack_type arr[10];
	// Stack_Init( (Stack*)&Ezz, (Stack_type*)&arr, (unsigned int)10);
	Stack_type* arr = (Stack_type*) calloc(10,sizeof(Stack_type));
	Stack_Init( (Stack*)&Ezz, (Stack_type*)arr, (unsigned int)10);
	Stack_Status(&Ezz);
	Stack_push(&Ezz, 10);
	Stack_push(&Ezz, 20);
	Stack_push(&Ezz, 30);
	Stack_push(&Ezz, 40);
	Stack_push(&Ezz, 50);
	Stack_Status(&Ezz);
	Stack_push(&Ezz, 60);
	Stack_Status(&Ezz);
	Stack_push(&Ezz, 70);
	Stack_push(&Ezz, 80);
	Stack_push(&Ezz, 90);
	Stack_push(&Ezz, 100);
	Stack_push(&Ezz, 140);
	Stack_Status(&Ezz);
    printf("%d peek of the stack\n", Stack_peek(&Ezz));
    printf("%d popped from stack\n", Stack_pop(&Ezz));
    printf("%d popped from stack\n", Stack_pop(&Ezz));
    printf("%d popped from stack\n", Stack_pop(&Ezz));
	Stack_Status(&Ezz);
    printf("%d popped from stack\n", Stack_pop(&Ezz));
    printf("%d popped from stack\n", Stack_pop(&Ezz));
    printf("%d popped from stack\n", Stack_pop(&Ezz));
    printf("%d popped from stack\n", Stack_pop(&Ezz));
    printf("%d popped from stack\n", Stack_pop(&Ezz));
    printf("%d popped from stack\n", Stack_pop(&Ezz));
	Stack_Status(&Ezz);
    printf("%d popped from stack\n", Stack_pop(&Ezz));
	Stack_Status(&Ezz);
    printf("%d popped from stack\n", Stack_pop(&Ezz));
    printf("%d popped from stack\n", Stack_pop(&Ezz));
    printf("%d popped from stack\n", Stack_pop(&Ezz));
	 */

	return 0;
}
