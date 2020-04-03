#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Swap(int* x, int* y)
{
	int temp;

	temp = *x;

	*x = *y;

	*y = temp;
}

int main()
{
	int a, b;

	printf("请输入两个整数值：");

	scanf("%d %d", &a, &b);

	Swap(&a, &b);

	printf("a=%d b=%d\n", a, b);

	return 0;
}
