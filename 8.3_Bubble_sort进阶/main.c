#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
struct student
{
	char name[20];
	int age;
};

int compare1(void* e1, void* e2) { // int 型比较
	return *((int*)(e1)) - *((int*)(e2));
}

int compare2(void* e1, void* e2) { // char 型比较
	return *((char*)(e1)) - *((char*)(e2));
}

int compare3(void* e1, void* e2) { // double 型比较
	if (*((double*)(e1)) > *((double*)(e2))) {
		return 1;
	}
	else if (*((double*)(e1)) < *((double*)(e2))) {
		return -1;
	}
	return 0;
}

int compare4_1(void* e1, void* e2) { // 结构体字符串 型比较
	return ((struct student*)(e1))->age - ((struct student*)(e2))->age;
}

int compare4_2(void* e1, void* e2) { // 结构体int 型比较
	return strcmp(((struct student*)(e1))->name, ((struct student*)(e2))->name);
}

void swap(char* p1, char* p2, int width) {
	for (int i = 0; i < width; i++) {
		char tmp = *(p1 + i);
		*(p1 + i) = *(p2 + i);
		*(p2 + i) = tmp;
	}
}

void Bubble_Sort(void *base, int sz, int width, int (*cmp)(void *e1, void *e2)) {
	int count = 0;
	for (int i = 0; i < sz - 1; i++) {
		count = 0;
		for (int j = 0; j < sz - 1 - i; j++) {
			if (cmp(((char*)(base)+j * width), ((char*)(base)+(j + 1) * width)) > 0) {
				swap(((char*)(base)+j * width), ((char*)(base)+(j + 1) * width), width);
				count++;
			}
		}
		if (count == 0) {
			return;
		}
	}
}

void test1() {
	int arr[] = { 5,8,7,9,2,3,6,4,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, sz, sizeof(arr[0]), compare1);
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test2() {
	char arr[] = { 'a','5','r','b','d'};
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, sz, sizeof(arr[0]), compare2);
	for (int i = 0; i < sz; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
}

void test3() {
	double arr[] = { 2.15,3.14,3.03,4.99,3.56 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, sz, sizeof(arr[0]), compare3);
	for (int i = 0; i < sz; i++) {
		printf("%lf ", arr[i]);
	}
	printf("\n");
}

void test4() {
	struct student arr[] = { {"zhangsan", 45},{"lisi", 30},{"wangwu",18}};
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, sz, sizeof(arr[0]), compare4_1);
	for (int i = 0; i < sz; i++) {
		printf("%s ", arr[i].name);
		printf("%d\n", arr[i].age);
	}
	printf("\n");

	Bubble_Sort(arr, sz, sizeof(arr[0]), compare4_2);
	for (int i = 0; i < sz; i++) {
		printf("%s  ", arr[i].name);
		printf("%d\n", arr[i].age);
	}
	printf("\n");
}

int main() {
	test1();	// int 型数组排序
	test2();	// char 型数组排序
	test3();	// double 型数组排序
	test4();	// 结构体 型数组排序

	return 0;
}