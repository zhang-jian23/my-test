#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 9;
	
	int count = 0;

	while (a< 100)
	{

			printf("  %d\n", a);
		    
	    	a = a + 10;

			count++;

	}
	
	printf("count=%d\n", count);

	return 0;
		
}