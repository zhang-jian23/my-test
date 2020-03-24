#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>     

int  main()
{
	int a=100;

	int b = 0;

	for (a = 100; a <= 200; a++)              
	{
		for (b = 2; b<a; b++)         
		{
			if (a%b == 0)
				
				break;        
		}
		if (b >= a)

			printf("  %d", a);   

	}
	return 0;
}
