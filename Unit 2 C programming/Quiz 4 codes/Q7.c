/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

int check(int n);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int n=0;

	printf("\nEnter a number: ");
	scanf("%d", &n);

	check(n)? printf("0") : printf("1");
	return 0;
}

int check(int n)
{
	if (n==3 || n==1) return 1;
	else if (n<=0 || n %3 != 0) return 0;
	else check(n/3);
}
