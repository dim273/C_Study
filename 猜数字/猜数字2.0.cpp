#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int player,computer,sum;
	srand(time(NULL));	
    printf("��ӭ������������!\n"); 
	printf("������ϲ�������֣�Ҫ�������������������ƣ��������Сһ��!\n"); 
	scanf("%d",&player);
	computer=rand()%10;
	sum=player+computer;
	printf("��������������ѡ������ĺ�Ϊ%d\n",sum);
	if(sum==6||sum==12)
	{printf("���������Ƕ���˧�磬��������\n"); 
	}else if(sum<6){
	printf("On no,����һ���˱�\n");
	}else{
	printf("�ҵ��죬��TM��Ϲ����ʲô��\n");
	}
		return 0;
}
