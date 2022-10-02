#include "head.h"

void menu() {
	printf("*************************\n");
	printf("******   1. play    *****\n");
	printf("******   0. exit    *****\n");
	printf("*************************\n\n");
}

void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	menu();

	do
	{
		printf("请输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
			menu();
			break;
		case 0:
			break;
		default:
			printf("您的输入有误，请重新输入");
			Sleep(200);
			system("cls");
			menu();
			break;
		}
	} while (input);
	system("cls");
	printf("欢迎下次使用！！！\n\n");
	Sleep(300);
}

int main() {
	test();

	return 0;
}