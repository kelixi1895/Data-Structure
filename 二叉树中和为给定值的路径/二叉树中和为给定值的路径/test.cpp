#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	void dfs(TreeNode* root, vector<int>& path, int tar, int curSum, vector<vector<int>>& res) {
		if (root->left == nullptr && root->right == nullptr) {
			if (curSum + root->val == tar) {
				path.push_back(root->val);
				res.push_back(path);
				path.pop_back();
			}
			return;
		}

		path.push_back(root->val);
		if (root->left)
			dfs(root->left, path, tar, curSum + root->val, res);
		if (root->right)
			dfs(root->right, path, tar, curSum + root->val, res);

		// »ØÍË
		path.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> path;
		if (root == nullptr)
			return res;
		dfs(root, path, sum, 0, res);

		return res;
	}
};