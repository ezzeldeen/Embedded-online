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

	float a1[2][2], a2[2][2];

	printf("Enter the elements of 1st matrix\n");
	for (int i=0; i<2 ;i++)
	{
		for (int j=0; j<2; j++)
		{
			printf("Enter a%d%d: ", i+1, j+1);
			scanf("%f", &a1[i][j]);
		}
	}

	printf("Enter the elements of 2nd matrix\n");
	for (int i=0; i<2 ;i++)
	{
		for (int j=0; j<2; j++)
		{
			printf("Enter b%d%d: ", i+1, j+1);
			scanf("%f", &a2[i][j]);
		}
	}

	printf("Sum of matrix:\n");
	for (int i=0; i<2 ;i++)
	{
		for (int j=0; j<2; j++)
		{
			printf("%2.2f\t", a1[i][j]+a2[i][j]);

		}
		printf("\n");
	}

	return 0;
}
