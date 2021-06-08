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
	int n=0, elements=0, i=0;

	printf("Enter number of elements: ");
	scanf("%d", &elements);

	for (i=0; i<elements ;i++)
	{
		scanf("%d", &a[i]);
	}

	printf("\nEnter the element to be searched: ");
	scanf("%d", &n);

	i=0;
	while(i<elements && n != a[i])
	{
		i++;
	}

	if(i<= elements)
		printf("Number found at location = %d", i+1);

	else printf("Number Not found");

	return 0;
}
