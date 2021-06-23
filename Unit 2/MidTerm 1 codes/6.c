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

	int arr[7]={4,2,5,2,5,7,4};
	int x=0,i;

	for (i=0; i<7;i++)
	{

		x ^=arr[i];
	}

	printf("%d",x);
	return 0;
}
