#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 }; // �������������Ϊ��������
	int sz = sizeof(arr) / sizeof(arr[0]); // ��������ĳ���
	int left = 0; //���±�
	int right = sz - 1; // ���±�
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
			printf("���ҵ�Ԫ�ش��ڣ������±�Ϊ%d\n", mid);
			break;
		}
	}
	if (left > right) {
		printf("���ҵ�Ԫ�ز�����\n");
	}

	return 0;
}