#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

typedef struct SList {
	SListNode* head;
}SList;

//创建结点
SListNode* BuySListNode(SLTDateType x) {
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}
// 单链表打印
void SListPrint(SListNode* plist) {
	while (plist) {
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x) {
	SListNode* node = BuySListNode(x);
	//空表
	if (*pplist == NULL) {
		*pplist = node;
		return;
	}
	//非空
	node->next = *pplist;
	*pplist = node;
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x) {
	if (plist == NULL) {
		return NULL;
	}
	while (plist) {
		if (plist->data == x) {
			return plist;
		}
		plist = plist->next;
	}
	return NULL;
}

//删除当前结点
void deleteNode(SListNode** head, SListNode* tar) {
	if (head == NULL || *head == NULL) {
		return;
	}
	//当前结点为尾结点
	if (tar->next == NULL) {
		SListNode* pre = NULL;
		SListNode* cur = *head;
		while (cur != tar) {
			pre = cur;
			cur = cur->next;
		}
		//当前结点也是头结点
		if (pre == NULL) {
			free(*head);
			*head = NULL;
		} else {
			pre->next = NULL;
			free(cur);
		}
	} else {
		SListNode* next = tar->next;
	    //复制下一结点的data到当前结点，删除下一个结点
		tar->data = next->data;
		tar->next = next->next;
		free(next);
	}
}
// 单链表的销毁
void SListDestory(SList* sl) {
	if (sl == NULL || sl->head == NULL) {
		return;
	}
	SListNode* cur = sl->head;
	while (cur) {
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	sl->head = NULL;
	printf("销毁单链表成功！\n");
}

int main() {
	SList sl = { NULL };
	SListPushFront(&sl.head, 1);
	
	SListNode* pos = SListFind(sl.head, 1);
	deleteNode(&sl.head, pos);
	SListPrint(sl.head);
	SListDestory(&sl);

	system("pause");
	return 0;
}