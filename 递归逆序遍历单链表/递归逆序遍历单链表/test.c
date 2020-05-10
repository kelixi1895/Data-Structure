#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

void reversePrintList(struct ListNode* head, int* arr, int* idx) {
	if (head == NULL) {
		return;
	}
	if (head->next == NULL) {
		arr[*idx] = head->val;
		++(*idx);
		return;
	}
	reversePrintList(head->next, arr, idx);
	arr[*idx] = head->val;
	++(*idx);
}
int* reversePrint(struct ListNode* head, int* returnSize){
	int size = 0;
	//统计结点个数
	struct ListNode* cur = head;
	while (cur) {
		size++;
		cur = cur->next;
	}

	//开空间
	int* res = (int*)malloc(sizeof(int) * size);
	*returnSize = size;
	if (size == 0) {
		return res;
	}
	//递归实现逆序遍历
	int idx = 0;
	reversePrintList(head, res, &idx);

	return res;
}

int main() {
	system("pause");
	return 0;
}