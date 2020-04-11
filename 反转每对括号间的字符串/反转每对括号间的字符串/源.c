#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;
// 初始化栈 
void StackInit(Stack* ps) {
	ps->_capacity = 10;
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
	ps->_top = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data) {
	if (ps->_top == ps->_capacity) {
		ps->_capacity *= 2;
		ps->_a = (STDataType *)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
	}
	ps->_a[ps->_top++] = data;
}
// 出栈 
void StackPop(Stack* ps) {
	if (ps->_top) {
		ps->_top--;
	}
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps) {
	if (ps->_top == 0) {
		return (STDataType)0;
	}
	return ps->_a[ps->_top - 1];
}
// 销毁栈 
void StackDestroy(Stack* ps) {
	free(ps->_a);
	ps->_top = ps->_capacity = 0;
	ps->_a = NULL;
}

void reverse(char* s, int start, int end) {
	while (start < end) {
		char tmp = *(s + start);
		*(s + start) = *(s + end);
		*(s + end) = tmp;
		start++;
		end--;
	}
}
char * reverseParentheses(char * s){
	Stack st;
	StackInit(&st);
	if (strlen(s) <= 1) {
		return s;
	}
	int size = strlen(s);
	for (int i = 0; i < size; i++) {
		if (*(s + i) == '(') {
			//记录左括号的位置
			StackPush(&st, i);
		}
		else if (*(s + i) == ')') {
			int start = StackTop(&st);
			StackPop(&st);
			int end = i;
			//翻转括号中间的内容
			reverse(s, start + 1, end - 1);
			//删除这对括号,括号中间的内容左移一位，右括号后面的内容左移两位
			for (int i = start + 1; i < end; i++) {
				*(s + i - 1) = *(s + i);
			}
			for (int i = end + 1; i <= strlen(s); i++) {
				*(s + i - 2) = *(s + i);
			}
			//更新字符串长度和索引i
			size -= 2;
			i -= 2;
		}
	}
	StackDestroy(&st);
	return s;
}