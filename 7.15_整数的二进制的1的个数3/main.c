#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int  n = 0;
	int count = 0;
	printf("请输入一个整数： ");
	scanf("%d", &n);
	while (n)
	{
		n = n & (n - 1);
		printf("%d\n", n);
		count++;
	}
	printf("这个整数的二进制中 1 的个数有 %d 个\n", count);
	return 0;
}