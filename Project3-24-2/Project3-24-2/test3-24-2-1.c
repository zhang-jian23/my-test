#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include <stdlib.h>

#include <time.h>

void menu()
{

	printf("******    ��������Ϸ     ******\n");
	printf("**********  1.��ʼ   **********\n");
	printf("**********  0.�˳�   **********\n");
}


void game()
{
	int a = 0;

	int b = 0;

	b = rand() % 100 + 1;

	while (1)
	{
		printf("������:");
		scanf("%d", &a);
		if (a > b)
		{
			printf("�´���\n");
		}
		else if (a  < b)
		{
			printf("��С��\n");
		}
		else
		{
			printf("�¶���\n");
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
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}

	} while (input);

	return 0;
}