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
		printf("���������ѡ��");
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
			printf("����������������������");
			Sleep(200);
			system("cls");
			menu();
			break;
		}
	} while (input);
	system("cls");
	printf("��ӭ�´�ʹ�ã�����\n\n");
	Sleep(300);
}

int main() {
	test();

	return 0;
}