#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

int main()
{
	int i = 0;
	int money = 0;
	int empty = 0;

	printf("«Î ‰»Î«Æ ˝£∫");

	scanf("%d", &money);

	if (money <= 0)
	{
	     i = 0;
	}
	else
	{
		i = money * 2 - 1;
	}
	printf("i = %d\n", i);
	return 0;
}
	