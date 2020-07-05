#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


 struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isExit(TreeNode* root, TreeNode* tar) {
		if (root == NULL)
			return false;
		return tar == root || isExit(root->left, tar) || isExit(root->right, tar);
	}
	//获取两个节点的路径存放在栈中
	void getPath(TreeNode* root, stack<TreeNode*>& st, TreeNode* tar) {

	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;
		//其中一个为根节点
		if (root == p || root == q)
			return root;

		//都在左子树中
		if (isExit(root->left, p) && isExit(root->left, q))
			return lowestCommonAncestor(root->left, p, q);
		//都在右子树中
		if (isExit(root->right, p) && isExit(root->right, q))
			return lowestCommonAncestor(root->right, p, q);

		//分别在左右子树中
		return root;
	}
};
int main() {
	sytem("pause");
	return 0;
}