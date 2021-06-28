/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>
#include <string.h>

struct SEmployee
{
	char Name[20];
	int ID ;
};

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct SEmployee s1={"emp1",1001}, s2={"emp2",1002}, s3={"emp3,1003"};
	struct SEmployee *arr[]={&s1, &s2, &s3};
	struct SEmployee *(*ptr)[3] = &arr;


	//printf("%s",(**(*ptr+1)).Name);
	printf("%s",(*(*ptr+1))->Name);
	printf("\n%d",(*(*ptr+1))->ID);

	return 0;
}
