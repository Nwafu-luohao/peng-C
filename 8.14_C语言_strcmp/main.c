#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int my_strcmp(const char* arr1, const char* arr2) {
	while (*arr1 == *arr2) {
		if (*arr1 == '\n') // �����ͬ���򷵻�0
			return 0;
		arr1++;
		arr2++;
	} 
	return (*arr1 - *arr2); // �������ͬ���򷵻ض�Ӧ�ַ�ASCII��ֵ����Ժ��ֵ
}

int main() {
	char* arr1 = "abcd";
	char* arr2 = "abcf";
	int ret = 0;
	ret = my_strcmp(arr1, arr2);
	printf("ret = %d\n", ret);
	return 0;
}