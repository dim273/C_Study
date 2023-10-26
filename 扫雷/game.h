#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define COL 9
#define ROW 9
#define COLS COL+2
#define ROWS ROW+2
void initialization(char arr[ROWS][COLS], int rows, int cols, char sz);
void display(char arr[ROW][COL], int row, int col);
void wine(char arr[ROWS][COLS], int rows, int cols);
void find(char inner[ROWS][COLS], char show[ROWS][COLS], int x, int y);