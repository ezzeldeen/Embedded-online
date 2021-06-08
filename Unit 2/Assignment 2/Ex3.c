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

	float n1=0, n2=0, n3=0;
	float max=0;

	printf ("Enter three numbers: ");
	scanf("%f %f %f", &n1, &n2, &n3);

	(n1 >= n2)? (max = n1) : (max = n2);
	(max >= n3)? : (max=n3);

	printf ("Largest number = %f", max);

	return 0;
}
