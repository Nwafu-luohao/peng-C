#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int  n = 0;
	int count = 0;
	printf("������һ�������� ");
	scanf("%d", &n);
	while (n)
	{
		n = n & (n - 1);
		printf("%d\n", n);
		count++;
	}
	printf("��������Ķ������� 1 �ĸ����� %d ��\n", count);
	return 0;
}