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

	char c;

	printf ("Enter an alphabet: ");
	scanf("%c",&c);

	if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||  c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
		printf ("%c is a vowel", c);
	else printf ("%c is a", c);

	return 0;
}
