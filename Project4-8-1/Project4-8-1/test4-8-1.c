#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int a = 0;
	int n = 0;
	int i = 0;
	int sum = 0;
	int ret = 0;
	printf("������a��ɵ�ǰn��ͣ�");
	scanf("%d%d", &a, &n);

	for (i = 0; i < n; i++)
	{
		ret = ret * 10 + a;
		sum += ret;
	}
	printf("sum=%d\n", sum);

	return 0;
}