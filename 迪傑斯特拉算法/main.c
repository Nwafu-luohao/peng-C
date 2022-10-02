#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SIZE 20 // 定义数组的长度
#define MAX 999 // 假设距离为无穷远

struct mark {   // 用来记录每个点的状态
	int value;
	int pre_index;
	int Flag;
};

// 递归实现记录表
void create_list(int arr[SIZE][SIZE], struct mark list[SIZE], int n) {
	int min = MAX;
	int index = 0;
	int count = 0;
	// 找出路径最短的点
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
	// 将这个点标记
	list[index].Flag = 1;
	// 比较权值并赋值
	for (int j = 0; j < n; j++) {
		if (arr[index][j] < MAX) {
			if (list[j].value > (arr[index][j] + list[index].value)) {
				list[j].value = arr[index][j] + list[index].value;
				list[j].pre_index = index;
			}
		}
	}
	// 打印求解过程
	for (int i = 0; i < n; i++) {
		printf("%d: value: %d, pro: %d,  b: %d\n", i, list[i].value, list[i].pre_index, list[i].Flag);
	}
	printf("\n");
	create_list(arr, list, n);
}

// 打印起点到各个点的最短路径和路径权值之和
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
	// 初始化记录表
	for (int i = 0; i < n; i++) {
		list[i].Flag = 0;
		list[i].value = MAX;
		list[i].pre_index = -1;
	}
	int start = 0;
	printf("请输入起点：");
	scanf("%d", &start);
	list[start].value = 0;

	// 实现记录表
	create_list(arr, list, n);

	return 0;
}

int main() {
	int n = 0;
	int x = 0;
	int y = 0;
	int v = 0; 
	int bian = 0;

	printf("请输入点的个数： ");
	scanf("%d", &n);
	printf("请输入边的条数： ");
	scanf("%d", &bian);
	int arr[SIZE][SIZE] = { MAX };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = MAX;
		}
	}
	while (bian)
	{
		printf("请输入边的 端点 和 权值：\n");
		printf("端点 (从0开始) ： ");
		scanf("%d", &x);
		scanf("%d", &y);
		if (x > n || y > n || x < 0 || y < 0) {
			system("cls");
			printf("输入错误，请重新输入！！！\n");
			continue;
		}
		printf("权值： ");
		scanf("%d", &v);
		// 初始化图
			arr[y][x] = v;
			arr[x][y] = v;
		bian--;
	}
	// 创建记录表
	struct mark list[SIZE];

	// 调用算法
	dijkstra(arr, list,n);

	// 打印计算结果
	int index = -1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		print(list,i);
		printf("\n");
	}

	return 0;
}