#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
	}
	return res;
}

void Swap(char* s, char* t) {
	char tmp = *s;
	*s = *t;
	*t = tmp;
}
//递归实现求字符串的排列
void permu(char* s, char* start, int n, char** res, int* idx) {
	if (strlen(s) == 1) {
		//查重
		for (int i = 0; i < *idx; i++) {
			if (!strcmp(res[i], start)) {
				return;
			}
		}
		//拷贝字符串
		char* tmp = (char*)malloc(sizeof(char) * (n + 1));
		memcpy(tmp, start, (n + 1));
		res[*idx] = tmp;
		(*idx)++;
		return;
	}
	for (int i = 0; i < strlen(s); i++) {
		//交换当前字符和后面的字符然后求子字符串的排列
		Swap(s, s + i);
		permu(s + 1, start, n, res, idx);
		//再一次交换字符
		Swap(s, s + i);
	}
}
char** permutation(char* s, int* returnSize){
	int len = strlen(s);
	char** res = (char**)malloc(sizeof(char*) * fact(len));
	int idx = 0;
	permu(s, s, len, res, &idx);
	*returnSize = idx;

	return res;
}
int main() {
	char s[] = "dkjphedy";
	int size = 0;
	char** res = permutation(s, &size);
	for (int i = 0; i < size; i++) {
		printf("%s\n", res[i]);
	}

	system("pause");
	return 0;
}