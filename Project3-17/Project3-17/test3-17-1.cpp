#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int num1=0;
	int num2 =0;
	printf("��������������ֵ");
	scanf(" %d%d", &num1, &num2);
	int avg = num1 + (num2 - num1) / 2;
	printf("avg=%d\n", avg);
	return 0;
}
