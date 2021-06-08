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

	float a[10][10], t[10][10];
	int r=0, c=0;

	printf("Enter rows and column of matrix: ");
	scanf("%d %d", &r, &c);

	for (int i=0; i<r ;i++)
	{
		for(int j=0; j<c; j++)
		{
			printf("Enter element a%d%d: ",i+1,j+1);
			scanf("%f", &a[i][j]);
		}
	}

	printf("Entered Matrix:\n");
	for (int i=0; i<r ;i++)
		{
			for(int j=0; j<c; j++)
			{
				printf("%1.1f   ",a[i][j]);
			}
			printf("\n");
		}

	for (int i=0; i<r ;i++)
		{
			for(int j=0; j<c; j++)
			{
				t[j][i] = a[i][j];
			}
		}

	printf("Transpose of Matrix:\n");
		for (int i=0; i<c ;i++)
			{
				for(int j=0; j<r; j++)
				{
					printf("%1.1f   ",t[i][j]);
				}
				printf("\n");
			}

	return 0;
}
