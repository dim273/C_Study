#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define ARR 3
void begin_board(char board[ROW][ARR], int row, int arr);
void game_board(char board[ROW][ARR],int row, int arr);
void player(char board[ROW][ARR], int row, int arr);
void computer(char board[ROW][ARR], int row, int arr);
int end(char board[ROW][ARR], int row, int arr);
