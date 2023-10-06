#include<stdio.h>
int main()
{
	int x = 0;
	int y = 0;
	int sum = 0;
	scanf("%d %d", &x, &y);
	while (1)
	{
		if (x > y)
		{
			sum = sum + y;
			x = x - y;
		}
		else if (x < y)
		{
			sum = sum + x;
			y = y - x;
		}
		else
		{
			sum = sum + x;
			break;
		}
	}
	printf("%d", sum);
	return 0;
}
