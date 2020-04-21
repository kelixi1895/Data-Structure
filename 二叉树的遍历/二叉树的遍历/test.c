#define _CRT_SECURE_NO_WARNINGS 1

//后序遍历
void postOrder(struct TreeNode* root, int* arr, int* idx) {
	if (root == NULL)
		return;

	postOrder(root->left, arr, idx);
	postOrder(root->right, arr, idx);
	arr[*idx] = root->val;
	++*idx;
}

int getSize(struct TreeNode* root) {
	if (!root) {
		return 0;
	}
	return getSize(root->left) + getSize(root->right) + 1;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int n = getSize(root);
	*returnSize = n;
	int* res = (int*)malloc(sizeof(int) * n);
	int idx = 0;
	postOrder(root, res, &idx);
	return res;

}

//中序遍历
void inOrder(struct TreeNode* root, int* arr, int* idx) {
	if (root == NULL)
		return;

	inOrder(root->left, arr, idx);
	arr[*idx] = root->val;
	++*idx;
	inOrder(root->right, arr, idx);
}

int getSize(struct TreeNode* root) {
	if (!root) {
		return 0;
	}
	return getSize(root->left) + getSize(root->right) + 1;
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int n = getSize(root);
	*returnSize = n;
	int* res = (int*)malloc(sizeof(int) * n);
	int idx = 0;
	inOrder(root, res, &idx);
	return res;
}
//先序遍历
void preOrder(struct TreeNode* root, int* arr, int* idx) {
	if (root == NULL)
		return;
	arr[*idx] = root->val;
	++*idx;
	preOrder(root->left, arr, idx);
	preOrder(root->right, arr, idx);
}

int getSize(struct TreeNode* root) {
	if (!root) {
		return 0;
	}
	return getSize(root->left) + getSize(root->right) + 1;
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int n = getSize(root);
	*returnSize = n;
	int* res = (int*)malloc(sizeof(int) * n);
	int idx = 0;
	preOrder(root, res, &idx);
	return res;
}