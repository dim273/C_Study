#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	srand(time(NULL));
	int a,b,sum;
	printf("请输入一个一到十以内的数字！\n");
	scanf("%d", &a);
	b = rand() % 10;
	sum = a + b;
	switch (sum)
	{
	case 3:
		printf("和为%d,是一等奖", sum);
		break;
	case 9:
		printf("和为%d,是二等奖", sum);
		break;
	case 12:
		printf("和为%d,是二等奖", sum);
		break;
	case 18:
		printf("和为%d,是三等奖", sum);
		break;
	case 6:
		printf("和为%d,是三等奖", sum);
		break;
	case 1:
		printf("和为%d,是三等奖", sum);
		break;
	default:
		printf("和为%d，很遗憾，你没中奖。", sum);
		break;
	}
	return 0;
}