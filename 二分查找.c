#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int ch[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int size = sizeof(ch) / sizeof(ch[0]);
	int left = 0;
	int right = size - 1;
	int a = 0;
	printf("������������ҵ�����0��20֮�ڣ�\n");
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
			printf("�ҵ��ˣ����±�Ϊ%d", mid);
			break;
		}
	}
	if (left > right)
		printf("û�ҵ�");
	return 0;
}