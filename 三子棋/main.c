#include "game.h"


void menu() {
	printf("***********************\n");
	printf("******  1. play  ******\n");
	printf("******  0. exit  ******\n");
	printf("***********************\n");
}

void test() {
	int input = 0;
	menu();
	srand((unsigned int)time(NULL));

	do
	{
		printf("\n请输入你的选择： ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			menu();
			break;
		case 0:
			break;
		default:
			system("cls");
			printf("输入错误，请重新输入！\n\n");
			Sleep(500);
			system("cls");
			menu();
			break;
		}
	}while (input);
	system("cls");
	printf("欢迎下次再玩！！！\n");
	Sleep(500);
}

int main() {
	printf("欢迎进入三子棋游戏^_^\n");
	test();
	return 0;
}