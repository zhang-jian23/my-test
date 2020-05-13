#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void reverse(int* nums, int begin, int end)
{
	while (begin < end)
	{
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;

		++begin;
		--end;
	}
}


int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	int* addRet = (int*)malloc(10001 * sizeof(int));
	
	int reti = 0;
	
	int ai = ASize - 1;
	int next = 0; 
	while (ai >= 0 || K > 0)
	{

		int x1 = 0;
		
		if (ai >= 0)
		{
			x1 = A[ai];
			--ai;
		}

		int x2 = 0;
		
		if (K > 0)
		{
			x2 = K % 10;
			K /= 10;
		}
		
		int ret = x1 + x2 + next;
		
		if (ret > 9)
		{
			ret %= 10;
			next = 1;
		}
		else
		{
			next = 0;
		}
		
		addRet[reti++] = ret;
	}
	
	if (next == 1)
	{
		addRet[reti++] = 1;
	}

	reverse(addRet, 0, reti - 1);
	*returnSize = reti;

	return addRet;
}