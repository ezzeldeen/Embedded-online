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

	int n=0, c, sum=1;

	printf ("Enter an integer: ");
	scanf("%d",&n);

	if ( n == 0) printf ("Factorial = 1");
	else if ( n<0 ) printf ("Error!!! Factorial of negative number doesn't exist");
	else
	{
		for(c=1; c<=n ; c++)
		{
			sum *= c;
		}
		printf ("sum = %d",sum);
	}
	return 0;
}
