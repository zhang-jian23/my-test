#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a = 0;

	double sum = 0.0;

	int flag = 1;

	for (a = 1; a <= 100; a++)
	{
		sum += flag*(1.0 / a);
	 
		flag = -flag;
	
	}
	printf("sum=%lf\n", sum);

	return 0;
}