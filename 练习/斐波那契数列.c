#include<stdio.h>
//递归的方法
//int fac(int x)
// {
//     if(x<=2)
//       return 1;
//     else
//       return fac(x-1)+fac(x-2);
// }


int fac(int x)//迭代的方法
{
	int a = 1;
	int b = 1;
	int c = 0;
	while (x >= 3)
	{
		c = a + b;
		a = b;
		b = c;
		x--;
	}
	return c;
}
int main()
{
	int n;
	scanf("%d", &n);
	int ret = fac(n);
	printf("%d", ret);
	return 0;
}