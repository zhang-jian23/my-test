#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int num1 = 14;
	int num2 = 35;
	printf("num1=%d num2=%d\n", num1, num2);
	num1 = num1^num2;
	num2 = num1^num2;
	num2 = num2^num1;
	printf("num1=%d  num2=%d\n", num1, num2);
	return 0;
}



