#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main() {
	short a = 3;
	int b = 10;
	printf("%d\n", sizeof(a = a + b)); // sizeof ����ı��ʽ����������
	printf("%d\n", a);
	printf("%d\n", sizeof(a = 12)); // sizeof ����ı��ʽ����������
	printf("%d\n", a);

	return 0;
}