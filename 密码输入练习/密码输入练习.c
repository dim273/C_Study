#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char pass[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("请输入你的密码：\n");
		scanf("%s", pass);
		if (strcmp(pass, "abcdef")==0)
		{
			printf("输入正确！");
			break;
		}
		else
			printf("密码错误\n");
	}
	if(i==3)
		printf("你已经输入错误三次了，请退出程序");
	return 0;
}