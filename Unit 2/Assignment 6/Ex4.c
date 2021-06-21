/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

struct Sstudent
{
	char name[50];
	int roll;
	float marks;
};

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct Sstudent s1[10];

	int i=0;
	for (; i<10; i++)
	{
		printf("Enter student %d name: ", i);
		scanf("%s", &s1[i].name);
		printf("Enter student %d marks: ", i);
		scanf("%f", &s1[i].marks);
		s1[i].roll = i;
	}

	printf("Display info for all students\n ");
	for (i=0; i<10; i++)
		{
			printf("student #%d name: ", i+1);
			printf("Name: %s\nMarks\n : %.1f", s1[i].name, s1[i].marks);
			s1[i].roll = i;
		}

	return 0;
}
