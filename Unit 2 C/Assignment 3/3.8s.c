/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <string.h>

int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char a[50]="pritesh", temp;
	int i=0, len=0;

	printf("Enter a string: ");
	//scanf("%[^\n]%*c", &a);
	gets(a);
	len = strlen(a)-1;

	for (i=0; i<=(len/2) ;i++)
	{
		temp = a[i];
		a[i]=a[len-i];
		a[len-i]=temp;

	}
	printf("Reverse string is: %s",a);
	return 0;
}
