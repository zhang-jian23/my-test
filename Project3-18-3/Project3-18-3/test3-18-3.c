#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
struct book
{ 
	char name[30];

     double price;

      char id[30];
};
 int  main()
{
	struct book bi = { "�ҵĿ�������", 56.33, "nju546541" };

	printf("������%s\n", bi.name);

	printf("���ۣ�%lf\n", bi.price);

	printf("��ţ�%s\n", bi.id);

	return 0;
}

