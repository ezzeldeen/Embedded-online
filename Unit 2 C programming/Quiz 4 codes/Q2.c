/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <string.h>

void set_arr (int a[], int n);
void print_arr(int a[], int n);
void swap (int a[], int b[]);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a[50], b[50];
	int s1=0, s2=0;

	printf("Enter size of array1: ");
	scanf("%d", &s1);

	printf("\nEnter size of array2: ");
	scanf("%d", &s2);

	printf("\nEnter %d elements in array 1: ", s1);
	set_arr(a, s1);

	printf("\nEnter %d elements in array 2: ", s2);
	set_arr(b, s2);

	print_arr(a, s1);
	print_arr(b, s2);

	swap (a, b);

	print_arr(a, s2);
	print_arr(b, s1);

	return 0;
}

void set_arr (int a[], int n)
{
	int i=0;
	while(i<n)
	{
		scanf("%d",&a[i]);
		i++;
	}
}

void print_arr(int a[], int n)
{
	printf("\n");
	int i=0;
	while(i<n)
	{
		printf("%d ",a[i]);
		i++;
	}
}

void swap(int a[], int b[])
{
	int i=0;
	while (i<50)
	{
		a[i] ^= b[i];
		b[i] ^= a[i];
		a[i] ^= b[i];
		i++;
	}
}
