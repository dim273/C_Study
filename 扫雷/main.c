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
	//初始化
	initialization(inner,ROWS,COLS,'0');
	initialization(show,ROWS,COLS,'#');
	wine(inner, ROWS, COLS);
	//显示
	display(show, ROW, COL);
	//display(inner, ROW, COL);
	//开始
	find(inner, show, ROWS, COLS);
	
}
int main()
{
	srand((unsigned int )time(NULL));
	int choose = 0;
	do
	{
		menu();
		printf("请选择，1或者0---->  ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("你已经退出游戏\n");
			break;
		default:
			printf("无效输入，请重新输入\n");
			break;
		}
	} while (choose);
	return 0;
}