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

	float n1=0, n2=0;
	char c;

	printf ("Enter operator either + or - or * or / : ");
	scanf("%c",&c);
	printf ("Enter two operands: ");
	scanf("%f %f", &n1, &n2);

	switch(c)
	{
	case '+':
		printf("%f + %f = %f", n1, n2, n1+n2 );
		break;
	case '-':
		printf("%f - %f = %f", n1, n2, n1-n2 );
		break;
	case '*':
		printf("%f * %f = %f", n1, n2, n1*n2 );
		break;
	case '/':
		printf("%f / %f = %f", n1, n2, n1/n2 );
		break;

	default :
		printf("Error! operator is not correct");
		break;

	}
	return 0;
}
