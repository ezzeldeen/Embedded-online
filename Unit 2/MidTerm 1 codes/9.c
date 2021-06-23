/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>
#include <string.h>

void reverse(char a[], int len)
{
	int i;
	for (i=len; i>=0; i--)
	{
		if(a[i]==' ' || (i==0))
		{
			int j;
			if(a[i]==' ' )  j=i+1;
			if(i==0) j=i;

			for (; j<= len; j++)
			{
				if (a[j] == '\0' || a[j]==' ' ) break;
				else printf("%c", a[j]);
			}
			printf(" ");
		}
	}
}

int main()
{
  setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char arr[15];
	scanf("%[^\n]",&arr);
	int len = strlen(arr);
	reverse(arr, len);

	return 0;
}
