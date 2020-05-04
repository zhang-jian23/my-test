#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

int main()
{
	int n;
	int count = 0;
	scanf("%d", &n);
	while (n != 0)
	{
		count += n & 1;
		n >>= 1;
	}
	printf("%d\n", count);
	return 0;
}