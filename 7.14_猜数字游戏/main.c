#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu() {
	system("cls");
	printf("****��ӭ�����������Ϸ****\n");
	printf("**************************\n");
	printf("******  1. play  *********\n");
	printf("******  0. exit  *********\n");
	printf("**************************\n");
}

void game() {
	system("cls");
	printf("������һ�������²��������\n");
	int num = 0;
	num = rand() % 100 + 1;
	int input = 0;
	printf("%d\n", num);
	do
	{
		scanf("%d", &input);
		printf("\n");
		if (input > num) {
			printf("�´���T_T\n");
			continue;
		}
		if (input < num) {
			printf("��С��T_T\n");
			continue;
		}
		if (input == num) {
			printf("��ϲ�㣬�¶���^_^\n");
		}
	} while (input != num);
	getchar();
	printf("������������");
	getchar();
}

int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("���������ѡ��");
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
	printf("��ӭ�´�����^_^");
	Sleep(500);

	return 0;
}