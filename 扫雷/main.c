#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("-----------------------------\n");
	printf("-----------1.start-----------\n");
	printf("-----------0.exit------------\n");
	printf("-----------------------------\n");
}
game()
{
	char inner[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	initialization(inner,ROWS,COLS,'0');
	initialization(show,ROWS,COLS,'#');
	wine(inner, ROWS, COLS);
	//��ʾ
	display(show, ROW, COL);
	//display(inner, ROW, COL);
	//��ʼ
	find(inner, show, ROWS, COLS);
	
}
int main()
{
	srand((unsigned int )time(NULL));
	int choose = 0;
	do
	{
		menu();
		printf("��ѡ��1����0---->  ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("���Ѿ��˳���Ϸ\n");
			break;
		default:
			printf("��Ч���룬����������\n");
			break;
		}
	} while (choose);
	return 0;
}