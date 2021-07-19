/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>
#define PI 3.14
#define area(r) (PI*(r)*(r))

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float r =0;
	printf("Enter the radius: ");
	scanf("%f", &r);
	printf("Area = %.2f",area(r));
	return 0;
}
