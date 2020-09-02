#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	void getAllNum(TreeNode* root, vector<int>& nums) {
		if (root == nullptr)
			return;
		nums.push_back(root->val);
		getAllNum(root->left, nums);
		getAllNum(root->right, nums);
	}
	int kthLargest(TreeNode* root, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;
		vector<int> nums;
		getAllNum(root, nums);

		for (int i = 0; i < nums.size(); i++) {
			if (i < k)
				pq.push(nums[i]);
			else {
				int top = pq.top();
				if (top < nums[i]) {
					pq.pop();
					pq.push(nums[i]);
				}
			}
		}

		return pq.top();
	}
};