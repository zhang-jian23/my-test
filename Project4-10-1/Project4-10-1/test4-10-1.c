#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

int main()
{
	int killer;
	for (killer = 'A'; killer < 'D'; killer++)
	{
		if ((killer != 'A') || (killer == 'C') || (killer == 'D') || (killer != 'D') == 3)

		{
			printf("killer is %c\n", killer);
			break;
		}
	}

	return 0;
}