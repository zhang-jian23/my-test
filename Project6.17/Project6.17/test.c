#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	char s1[6] = "thisis"; char s2[5] = "is";
	printf("%d\n", search(s1, s2));
	system("pause");
}
int search(char s1[], char s2[])
{
	int i = 0, j, len = strlen(s2);
	while (s1[i]){
		for (j = 0; j<len; j++)
		if (s1[i + j] != s2[j]) break;
		if (j >= len)return i;
		else i++;
	}
	return -1;
}
