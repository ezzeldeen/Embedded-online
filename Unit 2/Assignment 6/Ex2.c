/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

struct SinDistance
{
	unsigned int feet;
	float inch;
};

struct SinDistance addinches (struct SinDistance a, struct SinDistance b);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct SinDistance a, b, sum;

	printf("Enter 1st distance\n");
	printf("Enter feet: ");
	scanf("%d", &a.feet);
	printf("Enter inches: ");
	scanf("%f", &a.inch);

	printf("Enter 2nd distance\n");
	printf("Enter feet: ");
	scanf("%d", &b.feet);
	printf("Enter inches: ");
	scanf("%f", &b.inch);

	sum = addinches(a, b);
	printf("\nsum distance: %d\' %.2f\"", sum.feet, sum.inch);

	return 0;
}

struct SinDistance addinches (struct SinDistance a, struct SinDistance b)
{
	struct SinDistance sum;
	sum.feet = a.feet + b.feet ;
	sum.inch = a.inch + b.inch;
	if (sum.inch >= 12)
	{
		sum.inch -= 12;
		sum.feet +=1;
	}
	return sum;

}
