#include"head.h"

void game() {
	// �׵���Ϣ�洢
	// 1. ���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	// 2. �Ų��׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	// ��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	// ��ӡ����
	//DisplayBoard(mine, ROW, COL);
	// ������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	// ɨ��
	FindMine(mine,show,ROW,COL);
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	for (int i = 0; i <= row; i++) {
		printf(" %d ",i);
		if(i < row)
			printf("|");
	}
	printf("\n");
	for (int i = 0; i <= row; i++) {
		printf("---");
		if (i < row)
			printf("|");
	}
	printf("\n");
	for (int i = 1; i <= row; i++) {
		printf(" %d |", i);
		for(int j = 1; j <= col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col) {
				printf("|");
			}	
		}
		printf("\n");
		if (i < row) {
			for (int j = 0; j <= row; j++) {
				printf("---");
				if (j < row)
					printf("|");
			}
			printf("\n");
		}
	}
	printf("\n");
}

void SetMine(char board[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int ck = 0;
	char ch = ' ';
	while (1) {
		DisplayBoard(show, ROW, COL);
		printf("-----------------------\n");
		printf("-->    p. ����         \n");
		printf("-->    b. ���         \n");
		printf("-->    e. ������     \n");
		printf("-----------------------\n\n");
		Flag:
		printf("���������Ĳ����� ");
		getchar();
		scanf("%c", &ch);
		switch (ch)
		{
		case 'p': 
			{	P_1:
				printf("���������꣺ ");
				scanf("%d", &x);
				scanf("%d", &y);
				if (x <= row && x >= 1 && y <= col && y >= 1) {
					if (mine[x][y] == '1') // ���� 
					{
						system("cls");
						printf("\nT_T T_T T_T T_T T_T T_T\n");
						printf("���ź����㱻ը���ˣ�����\n");
						printf("T_T T_T T_T T_T T_T T_T\n\n");
						DisplayBoard(mine, ROW, COL);
						printf("\n\n�������������\n\n");
						getchar();
						getchar();
						system("cls");
						goto End;
					}
					else // ������
					{
						// ����x,y ��Χ�м����ף�
						get_mine_count(mine, show, x, y);
						//DisplayBoard(show, ROW, COL);
						system("cls");
					}
				}
				else
				{
					printf("�������������� ����������^_^\n");
					goto P_1;
				}
			}
			break;
		case 'b':
		{	B_1:
			printf("���������꣺ ");
			scanf("%d", &x);
			scanf("%d", &y);
			if (x <= row && x >= 1 && y <= col && y >= 1) {
				MarkMine(mine, show, x, y);
				system("cls");
			}
			else
			{
				printf("�������������� ����������^_^\n");
				goto B_1;
			}
		}
			break;
		case 'e':
			// �����ҵ�ɨ��״̬
			ck = judge(mine, show);
			if (ck == 1) {
				system("cls");
				printf("^_^^_^^_^^_^^_^^_^^_^^_^\n");
				printf("��ϲ�㣬ɨ����ɣ�����\n");
				printf("^_^^_^^_^^_^^_^^_^^_^^_^\n");
				printf("\n\n�������������\n\n");
				getchar();
				getchar();
				system("cls");
				goto End;
			}
			else
			{
				system("cls");
				printf("\nT_T T_T T_T T_T T_T T_T\n");
				printf("���ź���ɨ��ʧ�ܣ�����\n");
				printf("T_T T_T T_T T_T T_T T_T\n\n\n");
				DisplayBoard(mine, ROW, COL);
				printf("\n\n�������������\n\n");
				getchar();
				getchar();
				system("cls");
				goto End;
			}
			break;
		default:
			printf("������������� ����������^_^\n");
			goto Flag;
			break;
		}
	}
	End:
	;
}

// չ�����ܵ�ʵ�֣��ݹ�
int get_mine_count(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{	
	if (x <= ROW && x >= 1 && y <= COL && y >= 1)
	{
		if (show[x][y] == ' ')
		{
			return 0;
		}
		int n = mine[x - 1][y] +
			mine[x - 1][y - 1] +
			mine[x - 1][y + 1] +
			mine[x][y - 1] +
			mine[x][y + 1] +
			mine[x + 1][y] +
			mine[x + 1][y - 1] +
			mine[x + 1][y + 1] - 8 * '0';
		if (n == 0) {
			show[x][y] = ' ';
			get_mine_count(mine, show, x - 1, y);
			get_mine_count(mine, show, x-1, y-1);
			get_mine_count(mine, show, x-1, y+1);
			get_mine_count(mine, show, x, y-1);
			get_mine_count(mine, show, x, y+1);
			get_mine_count(mine, show, x+1, y);
			get_mine_count(mine, show, x+1, y-1);
			get_mine_count(mine, show, x+1, y+1);
		}
		else
		{
			show[x][y] = '0' + n;
			return 0;
		}
	}
	return 0;
}

int MarkMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y) {
	if (show[x][y] == '$') {
		show[x][y] = '*';
	}
	else
	{
		show[x][y] = '$';
	}

	return 0;
}

int judge(char mine[ROWS][COLS], char show[ROWS][COLS]) {
	int count = 0;
	for (int i = 1; i <= ROW; i++) {
		for (int j = 1; j <= COL; j++) {
			if (show[i][j] == '$') {
				if (mine[i][j] == '1') {
					count++;
				}
			}
		}
	}
	if (count == EASY_COUNT) {
		return 1;
	}
	return 0;
}