#define _CRT_SECURE_NO_WARNINGS 1

int max(int x , int y )
{
	int z = 0;

	z = x > y ? x : y;

	return z;
}
#include<stdio.h>
int main()
{
	int max(int a, int b);
	int a, b, c = 0;
	printf("请输入两个整数");
		scanf("%d%d", &a, &b);
	c = max(a, b);
	printf("max %d\n", c);
	return 0;
}