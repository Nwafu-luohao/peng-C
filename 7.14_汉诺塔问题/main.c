#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Hanoi(int n, char* left, char* mid, char* right,int* p) {
	if (n == 1) {
		printf("%s  移动到  %s\n", left, right);
		(*p) += 1;
	 }
	else {
		han_nuo(n-1, left, right, mid, p);
		printf("%s  移动到  %s\n", left, right);
		(*p)++;
		han_nuo(n-1, mid, left, right, p);
	}
}


int main() {
	int n = 0;
	int count = 0;
	char arr[][5] = { "塔一","塔二","塔三" };
	printf("请输入汉诺塔的层数：");
	scanf("%d", &n);
	Hanoi(n,arr[0], arr[1], arr[2], &count);
	printf("一共要搬动 %d 次\n", count);

	return 0;
}