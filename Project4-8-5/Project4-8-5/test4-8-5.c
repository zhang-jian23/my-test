#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<assert.h>

 int  my_strlen(const char* string)
{
	
	int count = 0;
	assert(NULL != string);
	while (*string)
	{
		count++;
		string++;
	}

	return count;
}
 int main()
 {
	 char arr[] = "hello world";
	 int ret = my_strlen(arr);
	 printf("%d\n", ret);
	 return 0;
 }