#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

char* my_strcpy(char * dest, const char * src) {
	char* ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main() {
	char arr1[] = "##############";
	char arr2[] = "hello world";
	printf("%s\n",arr1);
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}