#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
int main()
{
	int arr[10];
	int i = 0;
	int* p = arr;
	printf("请输入十个整数：");
	for (i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	for (p = arr;p<(arr+10);p++)	
	printf("%d", *p);
	printf("\n");
	return 0;



}