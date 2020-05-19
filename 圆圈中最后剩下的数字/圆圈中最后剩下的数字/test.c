#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

//用循环链表实现
typedef struct Node {
	int val;
	struct Node* next;
	struct Node* pre;
}Node;

Node* createNode(int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = node->pre = NULL;

	return node;
}

typedef struct doubleList {
	Node* head;
}doubleList;
void doubleListInit(doubleList* list) {
	list->head = createNode(0);
	list->head->pre = list->head->next = list->head;
}
void doubleListPushBack(doubleList*list, int val) {
	Node* newNode = createNode(val);
	Node* last = list->head->pre;

	last->next = newNode;
	newNode->pre = last;
	newNode->next = list->head;
	list->head->pre = newNode;
}

void doubleListDelete(Node* node) {
	Node* next = node->next;
	node->pre->next = next;
	next->pre = node->pre;
	free(node);
}
void doubleListDestory(doubleList* list) {
	Node* cur = list->head->next;
	while (cur != list->head) {
		doubleListDelete(cur);
		cur = cur->next;
	}
}
int lastRemaining(int n, int m){
	if (n == 1) {
		return 0;
	}
	doubleList list;
	doubleListInit(&list);
	//创建循环链表
	for (int i = 0; i < n; i++) {
		doubleListPushBack(&list, i);
	}
	//删除数字
	m = m % n;
	Node* start = list.head->next;

	while (start->next->next != start) {
		Node* cur = start;
		int s = m;
		while (--s) {
			cur = cur->next;
			if (cur == list.head) {
				cur = cur->next;
			}
		}
		//更新起始位置
		start = cur->next;
		//删除当前结点
		doubleListDelete(cur);
	}
	return start->val;
}

int main() {
	int res = lastRemaining(5, 3);
	printf("%d\n", res);
	system("pause");
	return 0;
}