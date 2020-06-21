#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//int a[] = { 1, 2, 3, 4 };
//
//printf("%d\n", sizeof(a));
//
//printf("%d\n", sizeof(a + 0));
//
//printf("%d\n", sizeof(*a));
//
//printf("%d\n", sizeof(a + 1));
//
//printf("%d\n", sizeof(a[1]));
//
//printf("%d\n", sizeof(&a));
//
//printf("%d\n", sizeof(*&a));
//
//printf("%d\n", sizeof(&a + 1));
//
//printf("%d\n", sizeof(&a[0]));
//
//printf("%d\n", sizeof(&a[0] + 1));


////字符数组
//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//printf("%d\n", sizeof(arr));
//
//printf("%d\n", sizeof(arr + 0));
//
//printf("%d\n", sizeof(*arr));
//
//printf("%d\n", sizeof(arr[1]));

//int main() 
//{
//
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0; }

//struct Test
//{
//	int Num;
//    char *pcName; 
//    short sDate;
//    char cha[2]; 
//    short sBa[4];
//}*p; 
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
//int main()
//{
//	printf("%p\n", p + 0x1);
//	printf("%p\n", (unsigned long)p + 0x1);
//	printf("%p\n", (unsigned int*)p + 0x1);
//	return 0;
//}
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
	return 0;
}