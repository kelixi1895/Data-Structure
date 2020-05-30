#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
给两个序列，第一个序列是入栈的顺序，判断第二个序列是否为弹出顺序
*/

#define true 1
#define false 0
#define bool int

typedef struct stack{
	int* arr;
	int size;
	int capacity;
}stack;

void stackInit(stack* st) {
	st->arr = (int*)malloc(sizeof(int) * 10);
	st->size = 0;
	st->capacity = 10;
}

void stackPush(stack* st, int val) {
	if (st->size == st->capacity) {
		st->capacity *= 2;
		st->arr = (int*)realloc(st->arr, sizeof(int) * st->capacity);
	}
	st->arr[st->size++] = val;
}
void stackPop(stack* st) {
	st->size--;
}

bool stackEmpty(stack* st) {
	return st->size == 0;
}

int stackTop(stack* st) {
	return st->arr[st->size - 1];
}
void stackDestory(stack* st) {
	free(st->arr);
	st->size = st->capacity = 0;
}


bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
	if (pushedSize == 0)
		return true;

	stack st;
	stackInit(&st);
	int idx1 = 0, idx2 = 0;

	while (idx1 < pushedSize) {
		//两序列当前元素相等
		if (pushed[idx1] == popped[idx2]) {
			idx1++;
			idx2++;
		}
		else if (stackEmpty(&st)) {
			//当前元素不相等且栈为空
			stackPush(&st, pushed[idx1++]);
		}
		else if (stackTop(&st) == popped[idx2]) {
			//序列2当前元素与栈顶元素相等
			stackPop(&st);
			idx2++;
		}
		else {
			//序列2当前元素与栈顶和1中当前元素均不相等
			stackPush(&st, pushed[idx1++]);
		}
	}
	if (idx2 == poppedSize)
		return true;
	while (!stackEmpty(&st)) {
		int top = stackTop(&st);
		if (top == popped[idx2]) {
			stackPop(&st);
			idx2++;
		}
		else {
			return false;
		}
	}

	return true;
}
int main() {
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 4, 5, 3, 2, 1 };
	bool ret = validateStackSequences(arr1, 5, arr2, 5);
	printf("%d\n", ret);

	system("pause");
	return 0;
}