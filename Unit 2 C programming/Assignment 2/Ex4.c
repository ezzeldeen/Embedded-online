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

	float n=0;

	printf ("Enter a number: ");
	scanf("%f",&n);

	if (n == 0 )		printf ("You entered zero");
	else if ( n > 0 ) printf ("%f is positive", n);
	else printf ("%f is negative", n);
	return 0;
}
