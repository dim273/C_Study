#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("һ�죬������ѧϰ��ͻȻһ�������˹����������������ҵ��\n");
	printf("ֻ�����˳�������˵�ǹ�������Ҫ������ȸ����Ҫ˯��������Ӷӳ�С���ǿ�������浽����\n");
	printf("��ҪӮ�������ҵ���ͺ�����������ɣ���\n");
	printf("���ѡ���ǣ�1.ӭս�����������ܡ���\n");
	
}
void game()
{
	int ed = 0;
	char board[ROW][ARR] = { 0 };
	//���̵ĳ�ʼ����ӡ
	begin_board(board, ROW, ARR);
	while(1)
	{
		player(board, ROW, ARR);
		game_board(board, ROW, ARR);
		computer(board, ROW, ARR);
		game_board(board, ROW, ARR);
		//�ж�
		ed=end(board, ROW, ARR);
		if (ed == 1)
		{
			printf("��Ӯ���������ҵ");
			break;
		}
		if (ed == 2)
		{
			printf("С��Ӯ�ˣ������ҵ�ò����ˣ�����ѧ�ˣ���");
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	menu();
	int choose;
	scanf("%d", &choose);
	if (choose == 1)
	{
		game();
	}
	else
	{
		printf("С�������������ҵȥѧ������ǰé��������Ϊʧȥ����ҵֱ������ĩ�ҿ�");
	}
	return 0;
}