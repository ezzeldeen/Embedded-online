/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <string.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num=0, bit_position=0, result=0;

	printf("\nEnter a number : ");
	scanf("%d", &num);

	printf("\nEnter bit position: ");
	scanf("%d", &bit_position);

	result = (num &= ~(1 << bit_position));
	printf("\nResult = %d", result);

	return 0;
}
