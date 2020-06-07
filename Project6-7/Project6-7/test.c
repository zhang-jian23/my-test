#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int checkmodel() 
{ 
	int i = 1; 
     return (*(char *)&i);
}   
int main()
{
	int ret = checkmodel();
	if (ret == 1)
	{
		printf("Ð¡¶Ë\n");
	}
	else
	{
		printf("´ó¶Ë\n");
	}
	return 0;
}