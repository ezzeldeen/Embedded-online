/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <string.h>

int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int factorial(int n);
	int a=0;
	printf("Enter a positive integer: ");
	scanf("%d",&a);

	printf("Factorial of %d: = %d", a, factorial(a));
	return 0;
}

int factorial(int n)
{
	if (n==0 || n==1)	{return 1;}
	else  return  (n* (factorial(n-1)));
}
