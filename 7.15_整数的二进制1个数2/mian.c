#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int n = 0;
	int count = 0;
	printf("������һ�������� ");
	scanf("%d", &n);
	while (n != 0) {
		if (n % 2 == 1) {
			count++;
		}
		n /= 2;
	}
	printf("��������� 1 �ĸ���Ϊ�� %d\n", count);

	return 0;
}