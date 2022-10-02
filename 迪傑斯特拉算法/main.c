#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SIZE 20 // ��������ĳ���
#define MAX 999 // �������Ϊ����Զ

struct mark {   // ������¼ÿ�����״̬
	int value;
	int pre_index;
	int Flag;
};

// �ݹ�ʵ�ּ�¼��
void create_list(int arr[SIZE][SIZE], struct mark list[SIZE], int n) {
	int min = MAX;
	int index = 0;
	int count = 0;
	// �ҳ�·����̵ĵ�
	for (int i = 0; i < n; i++) {
		if (list[i].Flag != 1) {
			if (min > list[i].value) {
				min = list[i].value;
				index = i;
			}
			count++;
		}
	}
	if (count == 0) {
		return;
	}
	// ���������
	list[index].Flag = 1;
	// �Ƚ�Ȩֵ����ֵ
	for (int j = 0; j < n; j++) {
		if (arr[index][j] < MAX) {
			if (list[j].value > (arr[index][j] + list[index].value)) {
				list[j].value = arr[index][j] + list[index].value;
				list[j].pre_index = index;
			}
		}
	}
	// ��ӡ������
	for (int i = 0; i < n; i++) {
		printf("%d: value: %d, pro: %d,  b: %d\n", i, list[i].value, list[i].pre_index, list[i].Flag);
	}
	printf("\n");
	create_list(arr, list, n);
}

// ��ӡ��㵽����������·����·��Ȩֵ֮��
void print(struct mark list[SIZE], int n) {
	int value = list[n].value;
	int index = n;
	for (;;) {
		printf("%d - ", index);
		index = list[index].pre_index;
		if (index == -1) {

			break;
		}
	}
	printf("\n");
	printf("value: %d\n", value);
}


int dijkstra(int arr[SIZE][SIZE], struct mark list[SIZE], int n) {
	// ��ʼ����¼��
	for (int i = 0; i < n; i++) {
		list[i].Flag = 0;
		list[i].value = MAX;
		list[i].pre_index = -1;
	}
	int start = 0;
	printf("��������㣺");
	scanf("%d", &start);
	list[start].value = 0;

	// ʵ�ּ�¼��
	create_list(arr, list, n);

	return 0;
}

int main() {
	int n = 0;
	int x = 0;
	int y = 0;
	int v = 0; 
	int bian = 0;

	printf("�������ĸ����� ");
	scanf("%d", &n);
	printf("������ߵ������� ");
	scanf("%d", &bian);
	int arr[SIZE][SIZE] = { MAX };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = MAX;
		}
	}
	while (bian)
	{
		printf("������ߵ� �˵� �� Ȩֵ��\n");
		printf("�˵� (��0��ʼ) �� ");
		scanf("%d", &x);
		scanf("%d", &y);
		if (x > n || y > n || x < 0 || y < 0) {
			system("cls");
			printf("����������������룡����\n");
			continue;
		}
		printf("Ȩֵ�� ");
		scanf("%d", &v);
		// ��ʼ��ͼ
			arr[y][x] = v;
			arr[x][y] = v;
		bian--;
	}
	// ������¼��
	struct mark list[SIZE];

	// �����㷨
	dijkstra(arr, list,n);

	// ��ӡ������
	int index = -1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		print(list,i);
		printf("\n");
	}

	return 0;
}