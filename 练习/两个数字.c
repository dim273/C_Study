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
	printf("��������������\n");
	scanf("%d %d",&a,&b);
	m = compare(a,b);
	printf("���������нϴ����%d\n",m);
	printf("���������ҽ���������������ֵ\n");
	printf("����ǰ������������ֵ�ֱ�Ϊa=%d,b=%d\n",a,b);
	change(&a,&b);
	printf("����������������ֵ�ֱ�Ϊa=%d,b=%d\n",a,b);
	return 0;
}