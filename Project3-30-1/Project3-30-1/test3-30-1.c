#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int difference(int a, int b)
{
	
	int count = 0;
	
	while (a != 0 || b != 0)
	{
		if ((a & 1) != (b & 1))
		{
			count++;
		}
		a = a >> 1;
		b = b >> 1;
	}
	return count;
}
int main()
{
	int a = 1999;
	int b = 2299;
	printf(" 不同bit位有：%d\n", difference(a, b));
	return 0;
}
