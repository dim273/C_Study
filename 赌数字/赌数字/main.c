#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int player, computer, sum;
	srand(time(NULL));
	printf("欢迎来到快乐星球!\n");
	printf("给出你喜欢的数字，要是整数，不能用坤进制，而且最好小一点!\n");
	scanf("%d", &player);
	computer = rand() % 10;
	sum = player + computer;
	printf("哈，我们两个人选择的数的和为%d\n", sum);
	if (sum == 6 || sum == 12)
	{
		printf("哇塞，我们都是帅哥，哈哈哈哈\n");
	}
	else if (sum < 6) {
		printf("On no,你不行啊\n");
	}
	else {
		printf("我的天，你在瞎输入了个什么鬼！\n");
	}
	return 0;
}
