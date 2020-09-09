#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
void main()
{
	int m, n;
	int z, t = 1;
	int i;
	printf("please input two numbers:");
	scanf("%d%d", &m, &n);
	if (m < n)
	{
		z = m;
		m = n;
		n = z;
	}
	for (i = 2; i < n + 1; i++)

	{
		if ((m%i == 0) && (n%i == 0))
		{
			m /= i;
			n /= i;
			t *= i;
			i = 1;
			if (n == 1)
				break;
		}
	}
	if (((m%i != 0) || (n%i != 0)) || n ==1)
	{
		printf("最大公约数是%d\n", t);
		t = m*n*t;
		printf("最小公倍数是%d\n", t);
	}
}
