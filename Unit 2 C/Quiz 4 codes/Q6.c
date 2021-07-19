/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <string.h>

void print_binary(int);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num=0;

	printf("\nEnter a number : ");
	scanf("%d", &num);

	print_binary(num);

	printf("\n%d", num&(1<<3)?1:0);
	return 0;
}

void print_binary(int n)
{
	if (n>1)
		print_binary(n>> 1);

	(n&1)? printf("1"):printf("0");
}
