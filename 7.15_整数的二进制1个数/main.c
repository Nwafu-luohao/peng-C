#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int n = 0; 
	int count = 0;
	printf("请输入一个整数：");
	scanf("%d", &n);
	for (int i = 0; i < 32; i++) {
		if (1 == ((n >> i) & 1)) {
			count++;
		}
	}
	printf("你输入的整数有 %d 个 0  ！！\n", count);

	return 0;
}