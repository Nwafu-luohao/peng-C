#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int my_strcmp(const char* arr1, const char* arr2) {
	while (*arr1 == *arr2) {
		if (*arr1 == '\n') // 如果相同，则返回0
			return 0;
		arr1++;
		arr2++;
	} 
	return (*arr1 - *arr2); // 如果不相同，则返回对应字符ASCII码值相减自后的值
}

int main() {
	char* arr1 = "abcd";
	char* arr2 = "abcf";
	int ret = 0;
	ret = my_strcmp(arr1, arr2);
	printf("ret = %d\n", ret);
	return 0;
}