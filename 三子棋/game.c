#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void begin_board(char board[ROW][ARR], int row, int arr)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < arr; i++)
	{
		for (j = 0; j < row; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void game_board(char board[ROW][ARR], int row, int arr)
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < ARR; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < ARR - 1)
				printf("|");
		}
		printf("\n");
		if (i < ROW - 1)
		{
			int j = 0;
			for (j = 0; j < ARR; j++)
			{
				printf("---");
				if (j < ARR - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
void player(char board[ROW][ARR], int row, int arr)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入你走的步数的坐标 （以左上角为(1,1),左下角为(1,3)）\n");
		scanf("%d %d", &x, &y);
		if (x <= 3 && x >= 1 && y >= 1 && y <= 3)
		{
			if (board[y - 1][x - 1] == ' ')
			{
				board[y - 1][x - 1] = '#';
				break;
			}
			else
			{
				printf("这里已经被下了，换个位置吧\n");
			}
		}
		else
		{
			printf("位置已经超出了棋盘了哦\n");
		}
	}
}
void computer(char board[ROW][ARR], int row, int arr)
{
	printf("小鸟选择的妙手\n");
	while (1)
	{
		int x = 0;
		int y = 0;
		x = rand() % ROW;
		y = rand() % ARR;	
		if (board[y][x] == ' ')
		{
			board[y][x] = '*';
			break;
		}		
	}
}
int end(char board[ROW][ARR], int row, int arr)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == '#' && board[i][1] == '#' && board[i][2] == '#')
		{
			return 1;
		}
		if (board[i][0] == '*' && board[i][1] == '*' && board[i][2] == '*')
		{
			return 2;
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == '#' && board[1][i] == '#' && board[2][i] == '#')
		{
			return 1;
		}
		if (board[0][i] == '*' && board[1][i] == '*' && board[2][i] == '*')
		{
			return 2;
		}
	}
	if (board[0][0] == '#' && board[1][1] == '#' && board[2][2] == '#')
	{
		return 1;
	}
	if (board[0][0] == '*' && board[1][1] == '*' && board[2][2] == '*')
	{
		return 2;
	}
	if (board[0][2] == '#' && board[1][1] == '#' && board[2][0] == '#')
	{
		return 1;
	}
	if (board[0][2] == '*' && board[1][1] == '*' && board[2][0] == '*')
	{
		return 2;
	}
	return 0;
}

