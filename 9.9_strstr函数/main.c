/*
��Ŀ������
�ַ�����ת���
��Ŀ���ݣ�
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����

���磺 ���� s1 = AABCD �� s2 = BCDAA, ����1
	   ���� s2 = abcd �� s2 = ABCD�� ����0

	   AABCD ����һ���ַ��õ� ABCDA
	   AABCD ���������ַ��õ� BCDAA
	   AABCD ���������ַ��õ� DAABC
*/


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int is_left_move(char* str1, char* str2) {
	int len = strlen(str1);
	int len2 = strlen(str2);
	if (len != len2) {
		return 0;
	}
	// 1. ��str1 �ַ�����׷��һ��str1�ַ���
	// strcat
	// strncat
	// 2. �ж�str2ָ����ַ����Ƿ���str1ָ����ַ������Ӵ�
	strcat(str1, str1);
	// strstr�������Ҷ�Ӧ���Ӵ�
	char* ret = strstr(str1, str2);
	if (ret == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	char arr1[30] = "abcdef";
	char arr2[] = "cdeab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}