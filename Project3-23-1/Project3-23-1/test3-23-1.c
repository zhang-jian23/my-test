#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int arr[10] = { 0 };

	int a = 0;

	int max = 0;

	for (a = 0; a < 10; a++)

	{
		scanf("%d", &arr[a]);
	}

	max = arr[0];

	for (a = 1; a < 10; a++)

	{

		if (arr[a]>max)
		{

			max = arr[a];

		}

	}

	printf("%d\n", max);

	return 0;

}