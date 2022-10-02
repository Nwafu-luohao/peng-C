#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main() {
	short a = 3;
	int b = 10;
	printf("%d\n", sizeof(a = a + b)); // sizeof 里面的表达式不参与运算
	printf("%d\n", a);
	printf("%d\n", sizeof(a = 12)); // sizeof 里面的表达式不参与运算
	printf("%d\n", a);

	return 0;
}