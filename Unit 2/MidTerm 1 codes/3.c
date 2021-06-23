/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

int checkPrime(int n)
{
	if (n==0 || n==1) return 0;
	if (n==2 || n==3) return 1;
	if (n%2==0 || n%3==0) return 0;

	for (int i=5; (i*i)<=n; i+=2)
	{
		if (n%i==0) return 0;
	}
	return 1;
}

void primeRange(int a, int b)
{
	int i;
	for (i=a; i<=b; i++)
	{
		if (checkPrime(i)==1) printf("%d ",i);
		else {};
	}
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a=0,b=0;
	printf("n1: ");
	scanf("%d",&a);
	printf("n2: ");
	scanf("%d",&b);

	primeRange(a, b);

	return 0;
}
