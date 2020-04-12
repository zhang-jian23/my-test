#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<string.h>

void reverse(char* str)
{
	int len = strlen(str);
	char* left = str;
	char* right = str+len-1;
	char tmp = 0;

	while (left<right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}


int main()
{
	char arr[] = "abcdef";
	reverse(arr);
	
	printf("%s\n", arr);
	return 0;
}