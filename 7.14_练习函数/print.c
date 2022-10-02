#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void print(char *arr, char * arr1) {
	strcpy(arr1, arr);
	printf("%s\n", arr1);
	memset(arr1, '@', 5);
	printf("%s\n", arr1);
}