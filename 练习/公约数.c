#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = 0;
	while (c = a % b)
	{
		a = b;
		b = c;
	}
	printf("%d", b);
	return 0;
}