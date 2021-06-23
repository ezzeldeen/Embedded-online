/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

int sum (int x)
{
	static int result=0;
	if(x == 0) return 0;
	else
	{
		result += (x%10);
		sum(x/10);
	}
	return result;
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a=0;
	printf("input: ");
	scanf("%d",&a);
	printf("output: %d",sum(a));
	return 0;
}
