/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

int sum(int x)
{
	static int res= 0;
	res +=x;
	x--;
	if (x !=0) sum(x);
	return res;
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("%d",sum(100));

	return 0;
}
