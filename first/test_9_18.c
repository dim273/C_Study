#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	srand(time(NULL));
	int a,b,sum;
	printf("������һ��һ��ʮ���ڵ����֣�\n");
	scanf("%d", &a);
	b = rand() % 10;
	sum = a + b;
	switch (sum)
	{
	case 3:
		printf("��Ϊ%d,��һ�Ƚ�", sum);
		break;
	case 9:
		printf("��Ϊ%d,�Ƕ��Ƚ�", sum);
		break;
	case 12:
		printf("��Ϊ%d,�Ƕ��Ƚ�", sum);
		break;
	case 18:
		printf("��Ϊ%d,�����Ƚ�", sum);
		break;
	case 6:
		printf("��Ϊ%d,�����Ƚ�", sum);
		break;
	case 1:
		printf("��Ϊ%d,�����Ƚ�", sum);
		break;
	default:
		printf("��Ϊ%d�����ź�����û�н���", sum);
		break;
	}
	return 0;
}