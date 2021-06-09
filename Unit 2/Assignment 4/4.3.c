/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <string.h>

void reverse();

int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter a sentence: ");

	reverse();
	return 0;
}

void reverse()
{
	char c;
	scanf("%c",&c);
	if(c != '\n')
		{
		reverse();
		printf("%c", c);
		}

}
