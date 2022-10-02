#ifndef __HEAD_H__
#define __HEAD_H__
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

void game();
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int get_mine_count(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int MarkMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int judge(char mine[ROWS][COLS], char show[ROWS][COLS]);

#endif // !__HEAD_H__
