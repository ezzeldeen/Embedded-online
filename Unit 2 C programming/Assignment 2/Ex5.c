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

	char n;

	printf ("Enter a character: ");
	scanf("%c",&n);

	if ( ((n <= 'z') && (n >= 'a')) || ((n <= 'Z') && (n >= 'A')))
		printf ("%c is an alphabet",n);
	else printf ("%c is not an alphabet",n);
	return 0;
}
