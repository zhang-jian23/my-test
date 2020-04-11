#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

int main()
{
	int m = 1999;
	int n = 2299;
	int num = 0;
	int count = 0;
	num = m^n;
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num = num / 2;
	}
	printf("%d\n", count);
	return 0;
}