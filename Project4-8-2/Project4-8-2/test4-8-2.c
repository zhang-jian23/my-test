#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<math.h>

int main()
{
	int i = 0;
	for (i = 0 ; i < 100000; i++)
	{
		int sum = 0;
		int count = 1;
		int tmp = i;
		while (tmp/=10)
		{
			count++;
		}
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, count);
			tmp /=10;
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}