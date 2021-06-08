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

	float a[100];
	int c=0;
	float total=0;

	printf("Enter ther number of data: ");
	scanf("%d", &c);

	for (int i=0; i<c ;i++)
	{
		printf("Enter number: ");
		scanf("%f", &a[i]);
		total += a[i];
	}

	printf("Average = %f", (total/c));

	return 0;
}
