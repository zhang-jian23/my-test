#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include <stdlib.h>

#include <time.h>

void menu()
{

	printf("******    猜数字游戏     ******\n");
	printf("**********  1.开始   **********\n");
	printf("**********  0.退出   **********\n");
}


void game()
{
	int a = 0;

	int b = 0;

	b = rand() % 100 + 1;

	while (1)
	{
		printf("猜数字:");
		scanf("%d", &a);
		if (a > b)
		{
			printf("猜大了\n");
		}
		else if (a  < b)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
}

int main()
{
	int input = 0;


	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);

	return 0;
}