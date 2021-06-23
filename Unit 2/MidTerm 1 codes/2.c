/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>


int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a=0;
	double b=0;
	printf("input: ");
	scanf("%d",&a);
	b = sqrt(a);
	printf("output: %f", b);
	return 0;
}
