#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void line(unsigned int x)
{
	if (x > 9)
	{
		line(x / 10);
	}
	printf("%d ",x%10);
}
int my_strlen(char*arr)
{
	if (*arr != '\0')
		return 1 + my_strlen(arr + 1);
	else
		return 0;
}
int main()
{
	unsigned int a = 0;
	scanf("%u", &a);
	line(a);
	char ch[] = { 0 };
	printf("\n");
	scanf("%s", ch);
	int b=my_strlen(ch);
	printf("%d", b);
	return 0;
}