#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Jisuan(const int N);
int main()
{
	int N,K,L ;
	scanf("%d", &N);
	Jisuan(N);
	return 0;
}
void Jisuan(const int N)
{
	int ch[50000];
	ch[0] = 1;
	int every = 0;//每一位的结果
	int m = 0;//进位
	int d = 1;//总位数
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < d; j++)
		{
			every = ch[j] * i + m;
			ch[j] = every % 10;
			m = every / 10;
		}
		while (m!=0)
		{
			ch[d] = m % 10;
			m = m / 10;
			d++;
		}
	}
	for (int i = d - 1; i >= 0; i--)
		printf("%d\n", ch[i]);
}
