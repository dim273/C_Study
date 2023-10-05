#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	printf("请输入一个值\n");
	int n = 0;
	scanf("%d", &n);
	if (prime(n))
		printf("是素数");
	else
		printf("不是素数");
	return 0;
}
int prime(int x)
{
	int i = 0;
		for (i = 2; i <= sqrt(x); i += 2)
		{
			if (x % i == 0)
			{
				return 0;
			}
	    }
		return 1;
}