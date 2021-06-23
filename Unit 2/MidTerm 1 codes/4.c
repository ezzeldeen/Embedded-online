/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

void reverse(int a)
{
	if(a != 0)
	{
		printf("%d",(a%10));
		reverse(a/10);
	}
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a=0;
	printf("input: ");
	scanf("%d",&a);

	reverse(a);

	return 0;
}
