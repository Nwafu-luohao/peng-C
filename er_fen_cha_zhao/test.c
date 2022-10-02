#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 }; // 所给的数组必须为有序数组
	int sz = sizeof(arr) / sizeof(arr[0]); // 计算数组的长度
	int left = 0; //左下标
	int right = sz - 1; // 右下标
	int  k = 0;
	scanf("%d", &k);

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] > k) {
			right = mid - 1;
		}
		else if (arr[mid] < k) {
			left = mid + 1;
		}
		else {
			printf("查找的元素存在，它的下标为%d\n", mid);
			break;
		}
	}
	if (left > right) {
		printf("查找的元素不存在\n");
	}

	return 0;
}