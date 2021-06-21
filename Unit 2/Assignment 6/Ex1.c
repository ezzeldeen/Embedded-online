/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

struct Sstudent
{
	char name[10];
	unsigned int roll;
	float marks;
};

struct Sstudent s1;

struct Sstudent inSstudent ();
void displaySstudent (struct Sstudent);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	s1 = inSstudent();
	displaySstudent(s1);

	return 0;
}

void displaySstudent (struct Sstudent s)
{
	printf("name: %s\nRoll: %d\nMarks: %2.2f", s.name, s.roll, s.marks);
}

struct Sstudent inSstudent (struct Sstudent s)
{
	printf("Enter name:");
	scanf("%s", &s.name);

	printf("Enter name:");
	scanf("%d", &s.roll);

	printf("Enter name:");
	scanf("%f", &s.marks);

	return s;
}
