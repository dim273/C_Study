#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
// 
//	if (n >= 85)
//		printf("A");
//	else if (n >= 70&& n < 85)
//		printf("B");
//	else if (n >= 60&&n<70)
//		printf("C");
//	else
//		printf("D");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	float x = 0.0;
//	float y = 0.0;
//	scanf("%f", &x);
//	if (x < 1)
//		y = x;
//	else if (x < 10 && x >= 1)
//		y = 2 * x - 1;
//	else
//		y = 3 * x - 11;
//	printf("%.2f", y);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char ch;
//	scanf("%c", &ch);
//	if (ch >= 'A' && ch <= 'Z')
//		ch = ch + ('a' - 'A');
//	printf("%c", ch);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	double x = 0.0;
//	double y = 0.0;
//	scanf("%lf", &x);
//	if (x >= 10000.0)
//		y = x * 5.00 * 0.01;
//	else if (x < 10000.0 && x >= 5000.0)
//		y = x * 3.00 * 0.01;
//	else if (x < 5000.0 && x >= 1000.0)
//		y = x * 2.00 * 0.01;
//	else
//		y = 0;
//	printf("Tax=%.2lfyuan", y);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	char ch[] = "January";
//	switch (n)
//	{
//	case 1:
//		printf("%s",ch);
//		break;
//	case 2:
//		printf("February");
//		break;
//	case 3:
//		printf("March");
//		break;
//	case 4:
//		printf("April");
//		break;
//	case 5:
//		printf("May");
//		break;
//	case 6:
//		printf("June");
//		break;
//	case 7:
//		printf("July");
//		break;
//	case 8:
//		printf("August");
//		break;
//	case 9:
//		printf("September");
//		break;
//	case 10:
//		printf("October");
//		break;
//	case 11:
//		printf("November");
//		break;
//	case 12:
//		printf("December");
//		break;
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//double fac(int x)
//{
//	double a;
//	a=pow(2, x-1);
//	return a;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	double sum=0;
//	int i;
//	if (n != 64)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			sum = sum + fac(i);
//		}
//		printf("%.lf", sum);
//	}
//	else
//	{
//		printf("18446744073709551615");
//	}
//	return 0;
//}
//#include<stdio.h>
//double abc(int x)
//{
//	double a=1;
//	int j = 0;
//	for (j = 1; j <= x; j++)
//	{
//		a *= j;
//	}
//	return 1 / a;
//}
//int main()
//{
//	double a=0;
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		a += abc(i);
//	}
//	printf("%.5lf", a);
//	return 0;
//}
//#include <stdio.h>  
//
//int main() {
//    int count = 0;
//    int i, j, k, l;
//
//    for (i = 1; i <= 10; i++) { 
//        for (j = 1; j <= 20; j++) {   
//            for (k = 1; k <= 50; k++) {  
//                for (l = 1; l <= 100; l++) {   
//                    if (i * 10 + j * 5 + k * 2 + l == 100 &&   
//                        i + j + k + l == 40) {   
//                        count++;
//                    }
//                }
//            }
//        }
//    }
//
//    printf("%d\n", count);
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char sss;
//	
//	while((sss=getchar())!='.')
//	{
//		if (sss>= 'a' && sss <= 'z')
//			printf("%d", sss - 'a' + 1);
//		else if (sss >= 'A' && sss <= 'Z')
//			printf("%d", sss - 'A' + 1);
//		else if (sss == ' ')
//			printf("*");
//		else
//			printf("");
//	}
//	return 0;
//}
//85185*1185*191514719*208120*315135*61855*6181513*2085*212215*
//85185*1185*191514719*208120*315135*61855*6181513*2085*212215***
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i,n;
//	double a = 0;
//	double length = 100.0;
//	double high = 0.0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		a = pow(2, i);
//		a = 1 / a;
//		if (i != n)
//			length += 2 * 100.0 * a;
//		else
//			length += 0;
//	}
//	high = 100 * pow(0.5, n);
//	printf("length=%.4lf\n", length);
//	printf("high=%.4lf", high);
//	return 0;
//}
#include<stdio.h>
#include<math.h>
int main()
{
	double a, b, c;
	double d, r1,r2;
	scanf("%lf %lf %lf", &a, &b, &c);
	d = b * b - 4 * a * c;
	if (d >= 0)
	{
		r1 = (b - sqrt(d)) / 2 * a;
		r2 = (b + sqrt(d)) / 2 * a;
		printf("r1=%7.2lf\n",r1);
		printf("r2=%7.2lf",r2);
	}
	else
	{
		printf("No real roots!");
	}
	return 0;
}