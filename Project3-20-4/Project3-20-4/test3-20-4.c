#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()

{
	int a = 1000;

	for (a = 1000; a <= 2000; a++)
	{
		if (a %100 != 0 &&  a % 4 == 0 || a % 400==0)
	
		printf("  %d", a);
	}

	return 0;
}