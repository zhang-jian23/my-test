#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 

int main()
{
 
	int a = 0;
	   
    int b = 0;

	for (a = 1; a <= 9; a++)
	{
		for (b = 1; b <= a; b++)
		{
			printf("%dx%d=%d\t", b, a, a*b);
		}
		  
		printf("\n");
	}

	return 0;

}