#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int n = 0;
	int count = 0;
	printf("请输入一个整数： ");
	scanf("%d", &n);
	while (n != 0) {
		if (n % 2 == 1) {
			count++;
		}
		n /= 2;
	}
	printf("这个整数中 1 的个数为： %d\n", count);

	return 0;
}