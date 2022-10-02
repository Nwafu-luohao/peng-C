#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Hanoi(int n, char* left, char* mid, char* right,int* p) {
	if (n == 1) {
		printf("%s  �ƶ���  %s\n", left, right);
		(*p) += 1;
	 }
	else {
		han_nuo(n-1, left, right, mid, p);
		printf("%s  �ƶ���  %s\n", left, right);
		(*p)++;
		han_nuo(n-1, mid, left, right, p);
	}
}


int main() {
	int n = 0;
	int count = 0;
	char arr[][5] = { "��һ","����","����" };
	printf("�����뺺ŵ���Ĳ�����");
	scanf("%d", &n);
	Hanoi(n,arr[0], arr[1], arr[2], &count);
	printf("һ��Ҫ�ᶯ %d ��\n", count);

	return 0;
}