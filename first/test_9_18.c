#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	struct Stu s={"birddim",19,"boy","play game"};
    printf("%s %d %s %s",s.name,s.age,s.sex,s.hobby);
	return 0;
}
struct Stu
{
    char name[20];
    int age;
    char sex;
    char hobby [30];
}