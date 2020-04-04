#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

mul_table(int *n)
{
	int a = 1, b = 0;

	for (a; a <= *n; a++) 
	{         
		b = 1;

		for (b; b <= *n; b++) 
		{     

			if (a >= b)
				printf("%3d*%3d=%3d ", b, a, (b)*(a));
		}
		printf("\n");
	}
}
int main() {

	int n;

	printf("请输入想打印的口诀表的最大行列数：\n");
 
	scanf("%d", &n);

	mul_table(&n);
 
	return 0;
}
