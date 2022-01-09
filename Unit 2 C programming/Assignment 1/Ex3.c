/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */


#include "stdio.h"

int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num1=0,num2 =0;

	printf ("Enter two integers: ");
	scanf("%d %d",&num1, &num2);
	printf ("Sum: %d",num1 + num2);

return 0;
}
