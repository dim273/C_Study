#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void reverse(char z[],int x,int y)
{
	char tem;
	if (x < y)
	{
		tem = z[x];
		z[x] = z[y];
		z[y] = tem;
		reverse(z, x + 1, y - 1);
	}
}
int main()
{
	char z[] = { 0 };
	printf("ÇëÊäÈëÒ»´®×Ö·û\n");
	scanf("%s", z);
	int left = 0;
	int right = strlen(z) - 1;
	reverse(z,left,right);
	printf("%s", z);
	return 0;
}