#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int ch[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int size = sizeof(ch) / sizeof(ch[0]);
	int left = 0;
	int right = size - 1;
	int a = 0;
	printf("请输入你想查找的数（0到20之内）\n");
	scanf("%d", &a);
	while (left <= right)
	{
		int mid = (left + right)/2;
		if (ch[mid] < a)
		{
			left = mid + 1;
		}
		else if (ch[mid] > a)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到了，其下标为%d", mid);
			break;
		}
	}
	if (left > right)
		printf("没找到");
	return 0;
}