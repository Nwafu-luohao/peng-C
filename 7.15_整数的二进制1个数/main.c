#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int n = 0; 
	int count = 0;
	printf("������һ��������");
	scanf("%d", &n);
	for (int i = 0; i < 32; i++) {
		if (1 == ((n >> i) & 1)) {
			count++;
		}
	}
	printf("������������� %d �� 0  ����\n", count);

	return 0;
}