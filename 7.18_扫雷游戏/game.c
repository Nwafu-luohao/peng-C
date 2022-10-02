#include"head.h"

void game() {
	// 雷的信息存储
	// 1. 布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	// 2. 排查雷的信息
	char show[ROWS][COLS] = { 0 };
	// 初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	// 打印棋盘
	//DisplayBoard(mine, ROW, COL);
	// 布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	// 扫雷
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
		printf("-->    p. 排雷         \n");
		printf("-->    b. 标记         \n");
		printf("-->    e. 标记完成     \n");
		printf("-----------------------\n\n");
		Flag:
		printf("请输入您的操作： ");
		getchar();
		scanf("%c", &ch);
		switch (ch)
		{
		case 'p': 
			{	P_1:
				printf("请输入坐标： ");
				scanf("%d", &x);
				scanf("%d", &y);
				if (x <= row && x >= 1 && y <= col && y >= 1) {
					if (mine[x][y] == '1') // 踩雷 
					{
						system("cls");
						printf("\nT_T T_T T_T T_T T_T T_T\n");
						printf("很遗憾，你被炸死了！！！\n");
						printf("T_T T_T T_T T_T T_T T_T\n\n");
						DisplayBoard(mine, ROW, COL);
						printf("\n\n按任意键结束！\n\n");
						getchar();
						getchar();
						system("cls");
						goto End;
					}
					else // 不是雷
					{
						// 计算x,y 周围有几个雷？
						get_mine_count(mine, show, x, y);
						//DisplayBoard(show, ROW, COL);
						system("cls");
					}
				}
				else
				{
					printf("您输入坐标有误， 请重新输入^_^\n");
					goto P_1;
				}
			}
			break;
		case 'b':
		{	B_1:
			printf("请输入坐标： ");
			scanf("%d", &x);
			scanf("%d", &y);
			if (x <= row && x >= 1 && y <= col && y >= 1) {
				MarkMine(mine, show, x, y);
				system("cls");
			}
			else
			{
				printf("您输入坐标有误， 请重新输入^_^\n");
				goto B_1;
			}
		}
			break;
		case 'e':
			// 检查玩家的扫雷状态
			ck = judge(mine, show);
			if (ck == 1) {
				system("cls");
				printf("^_^^_^^_^^_^^_^^_^^_^^_^\n");
				printf("恭喜你，扫雷完成！！！\n");
				printf("^_^^_^^_^^_^^_^^_^^_^^_^\n");
				printf("\n\n按任意键结束！\n\n");
				getchar();
				getchar();
				system("cls");
				goto End;
			}
			else
			{
				system("cls");
				printf("\nT_T T_T T_T T_T T_T T_T\n");
				printf("很遗憾，扫雷失败！！！\n");
				printf("T_T T_T T_T T_T T_T T_T\n\n\n");
				DisplayBoard(mine, ROW, COL);
				printf("\n\n按任意键结束！\n\n");
				getchar();
				getchar();
				system("cls");
				goto End;
			}
			break;
		default:
			printf("您输入操作有误， 请重新输入^_^\n");
			goto Flag;
			break;
		}
	}
	End:
	;
}

// 展开功能的实现，递归
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