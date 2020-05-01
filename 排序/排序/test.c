#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

int main() {
	int arr[] = { 3, 2, 1, 6, 8, 4, 10, 5, 9, 7 };
	quickSort(arr, 0, 9);
	printArr(arr, 10);
	system("pause");
	return 0;
}