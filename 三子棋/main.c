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
		printf("\n���������ѡ�� ");
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
			printf("����������������룡\n\n");
			Sleep(500);
			system("cls");
			menu();
			break;
		}
	}while (input);
	system("cls");
	printf("��ӭ�´����棡����\n");
	Sleep(500);
}

int main() {
	printf("��ӭ������������Ϸ^_^\n");
	test();
	return 0;
}