/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <string.h>

int power(int, int);

int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a=0, n=0;
	printf("Enter base number: ");
	scanf("%d", &a);
	printf("Enter power number: ");
	scanf("%d", &n);

	printf("%d ^ %d = %d", a, n, power(a,n));
	return 0;
}

int power(int a, int n)
{
	int result=1;
	if (n==0) return 1;
	result = a*power(a, n-1);
	return result;
}
