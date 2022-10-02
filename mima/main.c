#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main() {
	int i = 0;
	char pwd[] = "123456";
	char pwd1[10];
	for (i = 0; i < 3; i++) {
		printf("ÇëÊäÈëÃÜÂë£º");
		scanf("%s", pwd1);
		if (strcmp(pwd, pwd1) == 0) {
			printf("ÃÜÂëÊäÈëÕýÈ·!!!\n");
			break;
		}
		else {
			if(i != 2)
			printf("ÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë¡£\n");
		}
	}
	if (i == 3) {
		printf("Èý´ÎÃÜÂë¾ùÊäÈë´íÎó£¬³ÌÐòÍË³ö\n");
	}


	return 0;
}