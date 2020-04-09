#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i;
	int num = 110;
	printf("奇数位");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d", ((num >> i) & 1));
	}
	printf("偶数位");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", ((num >> i) & 1));
	}
	return 0;
}
