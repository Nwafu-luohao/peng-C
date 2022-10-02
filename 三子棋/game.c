#include "game.h"

void game() {
	char result = 'C'; // ����߳���������Ϣ
	char board[ROW][COL] = { 0 }; // ��������
	// ��ʼ������
	InitBoard(board,ROW, COL);
	// ��ӡ����
	DisplayBoard(board, ROW, COL);
	// ����
	while (1) {
		// �������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		// �ж�����Ƿ�Ӯ
		result = IsWin(board, ROW, COL);
		if (result != 'C') {
			break;
		}
		// ��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		// �жϵ����Ƿ�Ӯ
		result = IsWin(board, ROW, COL);
		if (result != 'C') {
			break;
		}
	}
	if (result == 'P') {
		printf("\nƽ��\n");
	}
	else if (result == 'o') {
		printf("\n��һ�ʤ��\n");
	}
	else{
		printf("\n���Ի�ʤ��\n");
	}
	Sleep(100);
	printf("\n������������\n");
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
		printf("\n������Ҫ���������: ->");
		scanf("%d", &x);
		scanf("%d", &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col)) {
			if (board[x-1][y-1] == ' ') {
				board[x-1][y-1] = 'o';
				break;
			}
			else {
				printf("\n�����������������\n");
				Sleep(300);
			}
		}
		else {
			printf("\n�����������������\n");
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