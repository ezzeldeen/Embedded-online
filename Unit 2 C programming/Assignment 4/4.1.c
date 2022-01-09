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

	int check_prime(int a);
	int a=0, b=0, f=0;
	printf("%s","Enter two numbers(intervals): ");
	scanf("%d %d",&a,&b);
	printf("prime numbers between %d and %d are: ", a, b);

	for (int i=a+1; i<=b; i++)
	{
		f =	check_prime(i);
		if (f==1) printf("%d ", i);
	}

	return 0;
}

int check_prime(int n)
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






