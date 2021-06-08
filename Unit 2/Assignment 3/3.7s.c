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

	char a[50];
	int i=0;

	printf("Enter a string: ");
	scanf("%[^\n]%*c", &a);

	for (i=0; a[i]!=0;i++);

	printf("\nLength of string: %d",i);

	return 0;
}
