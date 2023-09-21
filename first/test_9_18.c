#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Person
{
	char name[20];
	int age;
	char sex[10];
	char city[20];
	char like[20];
};
int main()
{
	struct Person s = { "DIM",19,"boy","guangxi","play computer"};
	printf ( "%s %d %s %s %s\n", s.name, s.age, s.sex, s.city, s.like );
	printf("Hello,world");
	
	return 0;
}