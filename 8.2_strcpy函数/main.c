#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char * my_strcpy1(char * dest, const char * src) {
	char* ret = dest;
	assert(dest != NULL); // ����
	assert(src != NULL); // ����
	// �� src ָ����ַ������Ƶ� dest ָ��Ŀռ䣬���� '\0' �ַ���
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
char* my_strcpy2(char* dest, const char* src) {
	char* ret = dest;
	assert(dest != NULL); // ����
	assert(src != NULL); // ����
	// �� src ָ����ַ������Ƶ� dest ָ��Ŀռ䣬���� '\0' �ַ���
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
char* my_strcpy3(char* dest, const char* src) {
	char* ret = dest;
	assert(dest != NULL); // ����
	assert(src != NULL); // ����
	// �� src ָ����ַ������Ƶ� dest ָ��Ŀռ䣬���� '\0' �ַ���
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
char* my_strcpy4(char* dest, const char* src) {
	char* ret = dest;
	assert(dest != NULL); // ����
	assert(src != NULL); // ����
	// �� src ָ����ַ������Ƶ� dest ָ��Ŀռ䣬���� '\0' �ַ���
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main() {
	char arr1[] = "######################";
	char arr2[] = "Hello, world!";
	char* (*pfArr[4])(char*, const char*) = { my_strcpy1, my_strcpy2, my_strcpy3, my_strcpy4}; // ��ʼ��ָ������
	for (int i = 0; i < 4; i++) {
		printf("%s\n", pfArr[i](arr1, arr2));
	}

	return 0;
}