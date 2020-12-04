#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class UnionFindSet {
public:
	UnionFindSet(int n) {
		_v.resize(n, -1);
	}

	void Union(int x1, int x2) {
		int r1 = findRoot(x1);
		int r2 = findRoot(x2);
		if (r1 == r2)
			return;
		_v[r1] += _v[r2];
		_v[r2] = r1;
	}

	int findRoot(int x) {
		while (_v[x] >= 0)
			x = _v[x];
		return x;
	}

	size_t size() {
		int sz = 0;
		for (auto e : _v) {
			if (e < 0)
				sz++;
		}

		return sz;
	}
	// 获取所有的集合
	vector<vector<int>> getAllSet() {
		vector<vector<int>> res;
		res.resize(_v.size());

		// 将节点添加到对应集合中去
		for (int i = 0; i < _v.size(); i++) {
			if (_v[i] >= 0) {
				int r = findRoot(i);
				res[r].push_back(i);

			}
			else {
				res[i].push_back(i);
			}
		}

		return res;
	}
private:
	vector<int> _v;
};

class Solution {
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		UnionFindSet ufs(s.size());
		// 将互相可交换的索引合并到一个集合中
		for (int i = 0; i < pairs.size(); i++) {
			ufs.Union(pairs[i][0], pairs[i][1]);
		}

		// 分别对每个集合中索引对应的子串进行排序
		vector<vector<int>> allSet = ufs.getAllSet();
		for (int i = 0; i < allSet.size(); i++) {
			sortForPartOfString(s, allSet[i]);
		}

		return s;
	}

	// 对由每个集合中索引构成的子串进行排序
	void sortForPartOfString(string& str, vector<int>& pos) {
		// 拷贝一份临时子串
		string tmp;
		for (auto e : pos) {
			tmp += str[e];
		}
		mySort(tmp);
		// 排序之后拷贝回原串位置
		int j = 0;
		for (auto e : pos) {
			str[e] = tmp[j++];
		}
	}

	void mySort(string& str) {
		vector<int> book(26, 0);
		for (auto ch : str) {
			book[ch - 'a']++;
		}
		int i = 0;
		for (int j = 0; j < 26; j++) {
			while (book[j] > 0) {
				str[i++] = j + 'a';
				book[j]--;
			}
		}
	}
};
int main() {
	string str("qdwyt");
	vector<vector<int>> ve = {
	{2, 3}, { 3, 2 }, { 0, 1 }, { 4, 0 }, { 3, 2 } };
	Solution sol;
	string res = sol.smallestStringWithSwaps(str, ve);

	system("pause");
	return 0;
}