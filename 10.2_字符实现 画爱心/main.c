#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
	float x, y, a;
	for (y = 1.5; y > -1.5; y -= 0.1) {
		for (x = -1.5; x < 1.5; x += 0.05) {
			a = x * x + y * y - 1;
			putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
		}
		system("color 0c");
		putchar('\n');
	}
	printf(" 丫头，\n");
	printf("    永远开心快乐！\n\n\n");
	system("pause");

	return 0;；
}