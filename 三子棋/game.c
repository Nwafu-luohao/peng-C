#include "game.h"

void game() {
	char result = 'C'; // 存放走出的棋盘信息
	char board[ROW][COL] = { 0 }; // 创建棋盘
	// 初始化棋盘
	InitBoard(board,ROW, COL);
	// 打印棋盘
	DisplayBoard(board, ROW, COL);
	// 下棋
	while (1) {
		// 玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		// 判断玩家是否赢
		result = IsWin(board, ROW, COL);
		if (result != 'C') {
			break;
		}
		// 电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		// 判断电脑是否赢
		result = IsWin(board, ROW, COL);
		if (result != 'C') {
			break;
		}
	}
	if (result == 'P') {
		printf("\n平局\n");
	}
	else if (result == 'o') {
		printf("\n玩家获胜！\n");
	}
	else{
		printf("\n电脑获胜！\n");
	}
	Sleep(100);
	printf("\n点击任意键继续\n");
	getchar();
	getchar();
	system("cls");
}

void InitBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col) {
	system("cls");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
			else {
				printf("\n");
			}
		}
		if(i<row-1)
			for (int j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1)
					printf("|");
				else {
					printf("\n");
				}
			}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;

	do
	{
		printf("\n请输入要下棋的坐标: ->");
		scanf("%d", &x);
		scanf("%d", &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col)) {
			if (board[x-1][y-1] == ' ') {
				board[x-1][y-1] = 'o';
				break;
			}
			else {
				printf("\n输入错误，请重新输入\n");
				Sleep(300);
			}
		}
		else {
			printf("\n输入错误，请重新输入\n");
			Sleep(300);
		}
	} while (1);
}

void ComputerMove(char board[ROW][COL], int row, int col) {
	Sleep(400);
	int x = 0;
	int y = 0;

	do
	{
		x = rand() % 3;
		y = rand() % 3;
		if ((x > -1 && x < row) && (y > -1 && y < col)) {
			if (board[x][y] == ' ') {
				board[x][y] = 'x';
				break;
			}
		}
	} while (1);
}

char IsWin(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
			return  board[i][0];
		}
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
			return  board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
		return  board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[1][1] != ' ') {
		return  board[1][1];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 'C';
			}
		}
	}
	return 'P';
}