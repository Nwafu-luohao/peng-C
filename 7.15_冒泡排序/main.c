#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Bubble_Sort(int arr[], int n) {
	int flag = 1;
	for (int i = 0; i < n - 1; i++) {
		flag = 1;
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1) {
			break;
		}
	}
}

int main() {
	int arr[30] = {0};
	int n = 0;
	printf("请输入数组的大小：\n");
	scanf("%d", &n);
	printf("依次输入各个元素：\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("\n原数组：");
	for (int i = 0; i < n; i++) {
		if (i == (n - 1)) {
			printf("%d\n", arr[i]);
			break;
		}
		printf("%d, ", arr[i]);
	}
	Bubble_Sort(arr, n);
	printf("\n排序后数组：");
	for (int i = 0; i < n; i++) {
		if (i == (n - 1)) {
			printf("%d\n", arr[i]);
			break;
		}
		printf("%d, ", arr[i]);
	}

	return 0;
}