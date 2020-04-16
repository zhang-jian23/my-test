#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
void main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	int a[100][100] = { 0 };
	while (n <= 0 || n >= 100)
	{
		printf("请输入要打印的数：");
		scanf("%d", &n);
	}

	for (i = 0; i <= n; i++)
	{
		a[i][0] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
			printf("%6d", a[i][j]);
		printf("\n");
	}
	printf("\n");
	return 0;
}