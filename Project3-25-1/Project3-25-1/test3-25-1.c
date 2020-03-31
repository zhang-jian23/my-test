#define _CRT_SECURE_NO_WARNINGS 1

int Fun(int n)
{
	if (n == 5)
		return 2;
	else
		return 2 * Fun(n + 1);
}