#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	float sn = 100.0, hn = sn / 2;
	int n;
	for (n = 2; n <= 10; n++)
	{
		sn = sn + 2 * hn;/*��n�����ʱ������������*/
		hn = hn / 2; /*��n�η����߶�*/
	}
	printf("the total of road is %f\n", sn);
	printf("the tenth is %f meter\n", hn);
}
