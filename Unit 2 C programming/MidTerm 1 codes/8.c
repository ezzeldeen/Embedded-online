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

	int i, temp;
	int arr[7]= {1,2,3,4,5,6,7};

	int s = sizeof(arr)/sizeof(int);

	for (i=0; i<=(s/2); i++)
	{
		temp = arr[i];
		arr[i] = arr[s-i-1];
		arr[s-i-1] = temp;
	}

	for (i=0; i<s; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
