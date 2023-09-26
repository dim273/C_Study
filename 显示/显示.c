#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	char tro1[] = "On,how stupid a clown I am";
	char tro2[] = "AAAAAAAAAAAAAAAAAAAAAAAAAA";
	int sz = strlen(tro1);
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		printf("%s",tro2);
		Sleep(1000);
		tro2[left] = tro1[left];
		tro2[right] = tro1[right];
		system("cls");
		left++;
		right--;
	}
	if (left > right)
		printf("%s", tro2);
	return 0;
}