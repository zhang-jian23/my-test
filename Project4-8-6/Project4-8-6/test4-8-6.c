#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<assert.h>

char *strcpy(char *dest, char *scr)
{
	char *p = dest;
	assert(dest != NULL);
	assert(scr != NULL);
	while (*dest++ = *scr++)
	{
		;
	}
	return p;
}
int main()
{
	char arr[20] = { 0 };
	char *p = "hello word";
	printf("%s\n",strcpy(arr, p));
	return 0;
}