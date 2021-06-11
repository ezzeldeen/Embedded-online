/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <string.h>

// max of 4 byte int 4,294,967,295
// 10 element array

int convert (int a[], int n);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a[10], len=0, result=0;

	printf("\nEnter number length: ");
	scanf("%d", &len);

	printf("\nEnter ascii of each number in hexa: ");
	int count=0;
	while(count<len)
	{
		scanf("%x",&a[count]);
		count++;
	}

	result = convert (a, len);
	printf("\nThe number is: %d", result);

	return 0;
}

int convert(int a[], int n)
{
	int i=0, result=0;
	for (;i<n;i++)
	{
		result = (result)*(10) + (a[i]-'0');
	}
	return result;
}

