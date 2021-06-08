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

	int number =0;

	printf ("Enter an integer: ");
	scanf("%d",&number);
	printf ("You entered: %d",number);

return 0;
}
