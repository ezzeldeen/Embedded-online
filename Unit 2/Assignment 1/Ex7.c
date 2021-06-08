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

	float a=0, b=0;

	printf ("Enter value of a: ");
	scanf("%f",&a);
	printf ("Enter value of b: ");
	scanf("%f",&b);

	a = a+b;
	b = a-b;
	a = a-b;

	printf ("After swapping, value of a = %f\n",a);
	printf ("After swapping, value of b = %f",b);

	return 0;
}
