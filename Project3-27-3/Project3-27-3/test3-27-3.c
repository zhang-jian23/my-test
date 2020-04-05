#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void find_num(int num)
{
	if (num<10)
	{
		printf("%d\n", num);
	}
	else
	{
		find_num(num / 10);
		
		printf("%d\n", num % 10);
	}
}

int main()
{
	int num = 0;
	
	printf("ÇëÊäÈëÊý×Ö£º\n");
	
	scanf("%d", &num);
	
	Find_num(num);
	
	return 0;
}