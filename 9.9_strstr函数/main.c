/*
题目描述：
字符串旋转结果
题目内容：
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。

例如： 给定 s1 = AABCD 和 s2 = BCDAA, 返回1
	   给定 s2 = abcd 和 s2 = ABCD， 返回0

	   AABCD 左旋一个字符得到 ABCDA
	   AABCD 左旋两个字符得到 BCDAA
	   AABCD 右旋两个字符得到 DAABC
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
	// 1. 在str1 字符串中追加一个str1字符串
	// strcat
	// strncat
	// 2. 判断str2指向的字符串是否是str1指向的字符串的子串
	strcat(str1, str1);
	// strstr——查找对应的子串
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