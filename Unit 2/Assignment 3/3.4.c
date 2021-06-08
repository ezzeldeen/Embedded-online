/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"

int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a[10];
	int location=0, number=0, elements=0, i=0;

	printf("Enter number of elements: ");
	scanf("%d", &elements);

	for (i=0; i<elements ;i++)
	{
		scanf("%d", &a[i]);
	}

	printf("\nEnter the element to be inserted: ");
	scanf("%d", &number);

	printf("\nEnter the location: ");
	scanf("%d", &location);

	for(i=elements; i>=location ;i--)
	{
		a[i] = a [i-1];
	}

	elements++;
	a[location-1]=number;

	for ( i=0; i<elements ;i++)
	{
		printf("%d   ",a[i]);
	}

	return 0;
}
