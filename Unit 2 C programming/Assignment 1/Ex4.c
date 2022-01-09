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

	float num1=0,num2 =0;

	printf ("Enter two numbers: ");
	scanf("%f %f",&num1, &num2);
	printf ("Product: %f",num1 * num2);

return 0;
}
