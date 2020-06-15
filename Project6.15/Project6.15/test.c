#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include<string.h>
int main()
{
	char s[100];
	int i, j, n;
	printf("输入字符串：\n");
	gets(s);
	n = strlen(s);
	for (i = 0, j = n - 1; i<j; i++, j--)
	if (s[i] != s[j]) 
		break;
	if (i >= j)
		printf("是回文串\n");
	else
		printf("不是回文串\n");
}
