#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>  

int main()

{

	int a = 0;

	int	b = 0;

	printf("请输入两个整数值");

	scanf("%d%d", &a, &b);

	printf("%d\n", a>b ? a : b);

	return 0;

}