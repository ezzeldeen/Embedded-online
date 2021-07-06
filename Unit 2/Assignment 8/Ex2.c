/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>
#include <string.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char arr[26];
	int i;
	char *parr = arr;

	for (i=0; i<26;i++)
	{
		*parr = 'A'+i;
		parr++;
	}

	parr = arr;
	for (i=0; i<26;i++)
	{
		printf("%c  ",*parr);
		parr++;
	}


	return 0;
}
