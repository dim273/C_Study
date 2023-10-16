#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void bubble_sort(int arr[], int x)
{
	int i = 0;
	int j = 0;
	int a = 0;
	for (i = 0; i < x-1; i++)
	{
		a = 0;
		for (j = 0;j<x-1-i;j++)
		{
			if (arr[j] < arr[j + 1])
			{
				a=arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = a;
			}
		}
	}
}
int main()
{
	int ch[] = { 1,3,45,12,65,35,97,56,43,26 };
	int size = sizeof(ch) / sizeof(ch[1]);
	bubble_sort(ch,size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", ch[i]);
	}
	return 0;
}