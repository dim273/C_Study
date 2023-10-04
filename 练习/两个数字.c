#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int compare(int x, int y)
{
	return(x > y ? x : y);
}
change(int* x, int* y)
{
	int z = *x;
	*x = *y;
	*y = z;

}
int main()
{
	int a = 0;
	int b = 0;
	int m = 0;
	printf("请输入两个数字\n");
	scanf("%d %d",&a,&b);
	m = compare(a,b);
	printf("两个数字中较大的是%d\n",m);
	printf("接下来，我将交换这两个数的值\n");
	printf("交换前，这两个数的值分别为a=%d,b=%d\n",a,b);
	change(&a,&b);
	printf("交换后，这两个数的值分别为a=%d,b=%d\n",a,b);
	return 0;
}