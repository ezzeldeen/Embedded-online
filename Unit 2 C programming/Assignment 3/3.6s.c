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
	int n=0, i=0;
	char c;

	printf("Enter a string: number of elements: ");
	scanf("%[^\n]%*c", &a);

	printf("\nEnter a character to find freq: ");
	scanf("%c", &c);

	for (i=0; a[i]!=0;i++)
	{
		if (c == a[i]) n++;
	}

	printf("\nFreq of %c = %d: ",c ,n);

	return 0;
}
