#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int fac(int n, int k)
{
	if (k <= 0)
		return 1;
	else
		return n*fac(n, k - 1);
}

int main()
{
	int n = 0;
	int k = 0;
	printf("输入n和k的值：");
	scanf("%d%d", &n, &k);
	int ret = fac(n, k);
	printf("%d\n", ret);
	return 0;

}