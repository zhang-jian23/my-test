#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//·ÇµÝ¹é
//
//int my_strlen(char *ch)
//{
//	int *a = ch;
//
//	while (*a != '\0')
//	{
//		a++;
//	}
//	return a-ch;
//}
//
//int main()
//{
//	char ch[]= "bit";
//	
//	printf("%d\n", my_strlen(ch));
//
//	return 0;
//}





//3.µÝ¹é


int  my_strlen(char*ch)
{
	if (*ch == '\0')
	{
		return 0;
	}
	else
	{
		return (1 + my_strlen(ch + 1));
	}
}

int main()
{
	char ch[] = "bit";

	printf("%d\n", my_strlen(ch));

	return 0;
}