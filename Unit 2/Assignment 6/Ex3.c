/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

struct Scomplex
{
	float real;
	float img;
};

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct Scomplex a, b, sum;

	printf("Enter 1st number\n");
	printf("Enter real & imaginary: ");
	scanf("%f %f", &a.real, &a.img);

	printf("Enter 2nd number\n");
	printf("Enter real & imaginary: ");
	scanf("%f %f", &b.real, &b.img);

	sum.real = a.real + b.real;
	sum.img = a.img + b.img;
	printf("\nsum = %.4f %.4fi", sum.real, sum.img);

	return 0;
}
