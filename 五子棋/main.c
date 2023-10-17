#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("一天，你正在学习，突然一个人跑了过来，抢走了你的作业。\n");
	printf("只听那人唱道“都说那公鸡白天要早起，团雀晚上要睡觉，我鸟队队长小鸟，那可是随叫随到。”\n");
	printf("想要赢回你的作业，就和我下三子棋吧！”\n");
	printf("你的选择是（1.迎战。其它，逃跑。）\n");
	
}
void game()
{
	int ed = 0;
	char board[ROW][ARR] = { 0 };
	//棋盘的初始化打印
	begin_board(board, ROW, ARR);
	while(1)
	{
		player(board, ROW, ARR);
		game_board(board, ROW, ARR);
		computer(board, ROW, ARR);
		game_board(board, ROW, ARR);
		//判断
		ed=end(board, ROW, ARR);
		if (ed == 1)
		{
			printf("你赢回了你的作业");
			break;
		}
		if (ed == 2)
		{
			printf("小鸟赢了，你的作业拿不回了，别想学了，卷狗");
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
		printf("小鸟拿走了你的作业去学，名列前茅，而你因为失去了作业直接在期末挂科");
	}
	return 0;
}