/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

void countones(int a)
{
	static int c=0;

	while(a != 0)
	{
		if (a & 1) c++;
		a = a>>1;
	}
	printf("%d",c);
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a=0;
	printf("input: ");
	scanf("%d",&a);

	countones(a);

	return 0;
}
