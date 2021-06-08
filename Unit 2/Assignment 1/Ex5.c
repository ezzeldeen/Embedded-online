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

	char c1;

	printf ("Enter a character: ");
	scanf("%c",&c1);
	printf ("ASCII value of %c = %d",c1 , c1);

return 0;
}
