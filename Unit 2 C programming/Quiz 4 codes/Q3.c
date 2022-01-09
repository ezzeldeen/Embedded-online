/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <string.h>

void set_arr (int a[], int n);
void print_arr(int a[], int n);
void reverse (int a[], int n);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a[50];
	int s=0;

	printf("Enter size of array: ");
	scanf("%d", &s);

	printf("\nEnter %d elements in array 1: ", s);
	set_arr(a, s);
	printf("\nthe array before: ");
	print_arr(a, s);
	reverse (a, s);
	printf("\nthe array after: ");
	print_arr(a, s);

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

void reverse(int a[], int n)
{
	int i=0, j=0, temp=0;
	for(i=0,j=n-1 ; i<=j ; i++,j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
