#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char password[20];
	printf("������������룺");
	scanf("%s",password );
	int ch = 0;
	while ((ch = getchar()) != '\n')
	{
		;
	}
	printf("��ȷ��������루����Y����N����>");
	int check=getchar();
	if ('Y' == check)
		printf("Yes");
	else
		printf("No");
	return 0;
}