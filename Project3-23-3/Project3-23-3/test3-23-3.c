#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int j, a, b;
	
	printf("��������������:\n");
	
	scanf("%d%d", &a, &b);
	
	while (a%b != 0)
	{
		j = a%b;
		
		a = b;

		b = j;
	}
	printf("%d\n", b);

	return 0;
}