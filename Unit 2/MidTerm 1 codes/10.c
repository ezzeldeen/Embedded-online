/*
 * main.c
 *
 *      Author: Ezz Eldeen
 */

#include "stdio.h"
#include <math.h>

int maxone(int x)
{
	int max1=0, max2=0;
	while (x!=0)
	{
		if ( (x&(1<<1))== 2 )
		{
			max1=0;
			x= x>>1;
			while (x&1)
			{
				max1++;
				x=x>>1;
			}
			max2 = (max2>max1)?max2:max1;
		}
		else x=x>>1;
	}

	return max2;
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int n=110;
	//scanf("%d", &n);

	printf("%d",maxone(n));

	return 0;
}
