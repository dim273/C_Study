#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char password[20];
	printf("请输入你的密码：");
	scanf("%s",password );
	int ch = 0;
	while ((ch = getchar()) != '\n')
	{
		;
	}
	printf("请确认你的密码（输入Y或者N）：>");
	int check=getchar();
	if ('Y' == check)
		printf("Yes");
	else
		printf("No");
	return 0;
}