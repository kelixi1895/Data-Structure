#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char val;
	struct Node* left;
	struct Node* right;
} Node;
Node* createTree(char* str, int* idx) {
	if (str[*idx] != '#') {
		Node* root = (Node*)malloc(sizeof(Node));
		root->val = str[*idx];
		++*idx;
		root->left = createTree(str, idx);
		++*idx;
		root->right = createTree(str, idx);
		return root;
	}
	else {
		return NULL;
	}
}

void inOrder(Node* root) {
	if (root) {
		inOrder(root->left);
		printf("%c ", root->val);
		inOrder(root->right);
	}
}
int main() {
	char str[101] = { 0 };
	scanf("%s", str);
	int idx = 0;
	Node* root = createTree(str, &idx);
	inOrder(root);
	printf("\n");
	return 0;
}