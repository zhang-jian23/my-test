#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i;
	int num = 110;
	printf("����λ");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d", ((num >> i) & 1));
	}
	printf("ż��λ");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", ((num >> i) & 1));
	}
	return 0;
}
