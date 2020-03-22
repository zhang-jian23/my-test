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
	struct book bi = { "我的快乐生活", 56.33, "nju546541" };

	printf("书名：%s\n", bi.name);

	printf("定价：%lf\n", bi.price);

	printf("书号：%s\n", bi.id);

	return 0;
}

