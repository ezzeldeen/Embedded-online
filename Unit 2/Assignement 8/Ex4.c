/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>
#include <string.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int arr[15];
	int size =0, i=0;
	int *p;

	printf("Enter the number of elements to store in an array max 15: ");
	scanf("%d",&size);

	for (i=0; i<size; i++)
	{
		printf("\nelement %d: ",i+1);
		scanf("%d",&arr[i]);
	}

	p = arr+size-1;
	for (i=size; i>0; i--)
	{
		printf("\nelement %d: %d",i, *p);
		p--;
	}

	return 0;
}
