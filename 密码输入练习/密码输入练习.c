#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char pass[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("������������룺\n");
		scanf("%s", pass);
		if (strcmp(pass, "abcdef")==0)
		{
			printf("������ȷ��");
			break;
		}
		else
			printf("�������\n");
	}
	if(i==3)
		printf("���Ѿ�������������ˣ����˳�����");
	return 0;
}