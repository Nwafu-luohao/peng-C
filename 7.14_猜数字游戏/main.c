#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu() {
	system("cls");
	printf("****欢迎进入猜数字游戏****\n");
	printf("**************************\n");
	printf("******  1. play  *********\n");
	printf("******  0. exit  *********\n");
	printf("**************************\n");
}

void game() {
	system("cls");
	printf("生成了一个数，猜猜这个数。\n");
	int num = 0;
	num = rand() % 100 + 1;
	int input = 0;
	printf("%d\n", num);
	do
	{
		scanf("%d", &input);
		printf("\n");
		if (input > num) {
			printf("猜大了T_T\n");
			continue;
		}
		if (input < num) {
			printf("猜小了T_T\n");
			continue;
		}
		if (input == num) {
			printf("恭喜你，猜对了^_^\n");
		}
	} while (input != num);
	getchar();
	printf("点击任意键结束");
	getchar();
}

int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			system("cls");
			break;
		default:
			break;
		}
	} while (input);
	printf("欢迎下次再来^_^");
	Sleep(500);

	return 0;
}