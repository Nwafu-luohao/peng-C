#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int my_strlen(char * arr) {
	int length = 0;
	while (*arr++ != '\0')
	{
		length++;
	}
	return length;
}

int main() {
	char arr[] = "hello world";
	int length = 0;
	length = my_strlen(arr);
	printf("%s\n", arr);
	printf("字符串的长度为：%d\n", length);

	return 0;
}