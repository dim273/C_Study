#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void initialization(char arr[ROWS][COLS], int rows, int cols, char sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < cols; i++)
	{
		for (j = 0; j < rows; j++)
		{
			arr[i][j] = sz;
		}
	}
}
void wine(char arr[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	int count = 10;
	do
	{
		i = rand() % 9 + 1;
		j = rand() % 9 + 1;
		if (arr[i][j] == '0')
		{
			count--;
			arr[i][j] = '1';
		}

	} while (count);

}
void display(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------ɨ����Ϸ----------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
int close(char ch[ROWS][COLS], int x, int y)
{
	return ch[x - 1][y - 1] + ch[x - 1][y] + ch[x - 1][y + 1] + ch[x][y - 1] + 
		ch[x][y + 1] + ch[x + 1][y - 1] + ch[x + 1][y] + ch[x + 1][y + 1]-8*'0';
}
//int push(char inner[ROWS][COLS],char show[ROWS][COLS], int x, int y)
//{
//	int a = 0;
//
//	return a;
//}
void find(char inner[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
	
	int x = 0;
	int y = 0;
	int count = 0;
	while(1)
	{
		printf("��������Ҫ�Ų�ĵط�������\n");
		scanf("%d %d", &x, &y);
		if (show[x][y]=='#')
		{
			if (inner[x][y] == '1')
			{
				printf("�㱻ը���ˣ����ӣ�һ·�ߺ�,��Ϸ����\n");
				display(inner, ROW, COL);
				break;
			}
			else
			{
				int a = 0;
				a = close(inner,x,y);
				
				/*if (a == 0)
				{
					
					count=push(inner,show,x,y);
				}
				else
				{*/
					show[x][y] = '0' + a;
					count++;
				//}
			}
		}
		else
		{
			printf("���Ѿ�����������,���������롣\n");
		}
		if (count == 71)
		{
			display(inner, ROW, COL);
			printf("��Ϸ��������ϲ��Ӯ��");
			break;
		}
		display(show, ROW, COL);
	}
}