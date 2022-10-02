#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

char* my_strcat(char* dest, const char* src) {
	char* ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main() {
	char arr1[] = "#######\0##############";
	char arr2[] = "hello world";
	printf("%s\n", arr1);
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}