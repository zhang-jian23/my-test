#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<vld.h>
#include<assert.h> 

//char * mystrncat(char * dst, const char * src, size_t n)
//{
//	char * tmp = dst;
//
//	while (*dst)
//	{
//		dst++;
//	}
//
//	int i;
//	for (i = 0; src[i] && i <  n; i++)
//	{
//		dst[i] = src[i];
//	}
//
//	dst[i] = 0;
//	return tmp;
//}
char * mystrncpy(char * dst, const char * src, size_t n)
{
	int i;
	for (i = 0; src[i] && i < n; i++)
	{
		dst[i] = src[i];
	}

	if (i < n)
	{
		dst[i] = 0;
	}
	return dst;
}