#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
void adjust(int arr[], int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		while ((left < right) && (arr[left] % 2 != 0))
		{
			left++;
		}
		while ((left < right) && (arr[right] % 2) == 0)
		{
			right--;
		}
		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
}
int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	adjust(arr, len);
	for (i = 0; i<len; i++)
	{
		printf("%3d", arr[i]);
	}
	return 0;
}
