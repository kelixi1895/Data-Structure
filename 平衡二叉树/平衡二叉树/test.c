#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int getHigh(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int leftHigh = getHigh(root->left);
	int rigHigh = getHigh(root->right);
	return leftHigh > rigHigh ? leftHigh + 1 : rigHigh + 1;
}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int leftHigh = getHigh(root->left);
	int rigHigh = getHigh(root->right);
	if (leftHigh - rigHigh > 1 || leftHigh - rigHigh < -1)
		return false;
	return isBalanced(root->left)
		&& isBalanced(root->right);

}