#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
	int a = 3;

	while (a  <= 100)
	{
		if (a % 3 == 0)

			printf("  %d", a);

		a++;
	}
	return 0;
}