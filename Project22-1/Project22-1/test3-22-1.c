#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()

{

	int a = 0;

	int count = 0;

	for (a = 1; a <= 100; a++)

	{
		if (a % 10 == 9)

		{

			count++;

		}


		else if (a / 10 == 9)

		{

			count++;
		}
	}
	printf("count=%d\n", count);

	return 0;
    
	
}


