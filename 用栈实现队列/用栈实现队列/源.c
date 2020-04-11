#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0
typedef int bool;

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* head;
	Node* rear;
}Queue;

void queueInit(Queue* q) {
	q->head = q->rear = NULL;
}

void queuePush(Queue* q, int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = x;
	if (q->head == NULL) {
		q->head = q->rear = newNode;
	}
	else {
		q->rear->next = newNode;
		q->rear = newNode;
	}
}
void queuePop(Queue* q) {
	if (q->head == NULL) {
		return;
	}
	Node* next = q->head->next;
	free(q->head);
	q->head = next;
	//队列中只有一个元素，出队以后将rear置为NULL
	if (next == NULL) {
		q->rear == NULL;
	}
}

int queueFront(Queue* q) {
	return q->head->data;
}
int queueBack(Queue* q) {
	return q->rear->data;
}

bool queueEmpty(Queue* q) {
	return q->head == NULL;
}

typedef struct {
	Queue q;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	queueInit(&st->q);
	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	queuePush(&obj->q, x);
}
/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	//先记录开始时队尾的位置
	Node* cur = obj->q.head, *rear = obj->q.rear;
	//将除了队尾外的元素依次出队然后入队,然后将开始时的最后一个元素出队
	while (cur != rear) {
		cur = cur->next;
		int tmp = queueFront(&obj->q);
		queuePop(&obj->q);
		queuePush(&obj->q, tmp);
	}
	int top = queueFront(&obj->q);
	queuePop(&obj->q);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return queueBack(&obj->q);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return  queueEmpty(&obj->q);
}

void myStackFree(MyStack* obj) {
	free(obj->q.head);
	free(obj);
}

int main() {
	system("pause");
	return 0;
}