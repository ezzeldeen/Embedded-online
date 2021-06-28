/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>
#include <string.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char arr[20];
	char *pa;

	scanf("%s", &arr);
	//pa = arr + strlen(arr);

	for ( (pa = arr + strlen(arr)-1); pa >=arr; pa--)
	{
		printf("%c",*pa);
	}

	return 0;
}
