#define _CRT_SECURE_NO_WARNINGS 

//非递归

//#include <stdio.h>
//
//int fac(int a)
//{
//	int x = 1;
//	int y = 0;
//	for (y = 1; y <= a; y++)
//	{
//		x = x*y;
//	} 
//
//	return x;
//}
//
//int main()
//{
//
//	int a = 0;
//
//	int fun(a);
//	
//	printf("输入一个数：");
//	
//	scanf("%d", &a);
//
//	printf("%d\n", fac(a));
//
//	return 0;
//}





//递归

#include <stdio.h>


int fac(int a)
{
	if (a <= 1)
	{
		return 1;
	}
	else
	{
		return a*fac(a - 1);
	}

}
int main()
{
	int a = 0;
	
	printf("输入一个数：");
	
	scanf("%d", &a);
	
	int fac(a);
	
	printf("%d\n", fac(a));
	
	return 0;
}
