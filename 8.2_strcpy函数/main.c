#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char * my_strcpy1(char * dest, const char * src) {
	char* ret = dest;
	assert(dest != NULL); // 断言
	assert(src != NULL); // 断言
	// 把 src 指向的字符串复制到 dest 指向的空间，包含 '\0' 字符。
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
char* my_strcpy2(char* dest, const char* src) {
	char* ret = dest;
	assert(dest != NULL); // 断言
	assert(src != NULL); // 断言
	// 把 src 指向的字符串复制到 dest 指向的空间，包含 '\0' 字符。
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
char* my_strcpy3(char* dest, const char* src) {
	char* ret = dest;
	assert(dest != NULL); // 断言
	assert(src != NULL); // 断言
	// 把 src 指向的字符串复制到 dest 指向的空间，包含 '\0' 字符。
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
char* my_strcpy4(char* dest, const char* src) {
	char* ret = dest;
	assert(dest != NULL); // 断言
	assert(src != NULL); // 断言
	// 把 src 指向的字符串复制到 dest 指向的空间，包含 '\0' 字符。
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main() {
	char arr1[] = "######################";
	char arr2[] = "Hello, world!";
	char* (*pfArr[4])(char*, const char*) = { my_strcpy1, my_strcpy2, my_strcpy3, my_strcpy4}; // 初始化指针数组
	for (int i = 0; i < 4; i++) {
		printf("%s\n", pfArr[i](arr1, arr2));
	}

	return 0;
}