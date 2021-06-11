/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <string.h>

void set_arr(int a[], int n);
void search_l_ndexint(int a[], int n, int snum);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int arr[10], arr_size=0, n=0;

	printf("\nEnter size of array: ");
	scanf("%d", &arr_size);

	printf("\nEnter the array numbers: ");
	set_arr(arr, arr_size);

	printf("\nEnter number to search: ");
	scanf("%d", &n);

	search_l_ndexint(arr, arr_size, n);
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

void search_l_ndexint (int a[], int n, int snum)
{
	int i=n-1;
	while(i>=0)
	{
		if (a[i]==snum)
		{
			printf("%d ",i);
			break;
		}
		else if (i == 0) printf("-1 ");
		i--;
	}
}

