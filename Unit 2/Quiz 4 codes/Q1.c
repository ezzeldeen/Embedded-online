/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

// setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);
// fflush(stdin);fflush(stdout);

#include "stdio.h"
#include <string.h>

int compare(char a[], char b[]);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);
	char user[20]="ezz eldeen";
	char input [20];

	printf("Enter user name: ");
	scanf("%[^\n]%*c",input);
	compare(user, input)? printf("correct user") : printf("wrong user");

	return 0;
}

int compare(char a[], char b[])
{
	int i=0;
	while(a[i] == b[i])
	{
		if (a[i]=='\0' && b[i]=='\0') return 1;
		i++;
	}
	return 0;
}
