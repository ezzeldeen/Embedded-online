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

	int m=29;
	printf("Address of m : 0x%p\nValue of m : %d",&m,m);

	int *pm =&m;
	printf("\nAddress of m : 0x%p\nValue of m : %d",pm,*pm);

	m = 34;
	printf("\nAddress of m : 0x%p\nValue of m : %d",pm,*pm);

	* pm =7;
	printf("\nAddress of m : 0x%p\nValue of m : %d",pm,*pm);

	return 0;
}
