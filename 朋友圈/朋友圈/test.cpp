#include <iostream>
#include <vector>
using namespace std;

/*
班上有 N 名学生。其中有些人是朋友，有些则不是。
他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，
那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。
给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，
表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
你必须输出所有学生中的已知的朋友圈总数。
*/
class UnionFindSet {
public:
	// 初始化并查集，每个元素作为一个集合
	UnionFindSet(int n) {
		_v.resize(n, -1);
	}

	// 获取节点的根
	int findRoot(int x) {
		while (_v[x] >= 0) {
			x = _v[x];
		}

		return x;
	}

	// 合并两个节点所在的集合
	bool Union(int x1, int x2) {
		// 找到两个节点的根
		int r1 = findRoot(x1);
		int r2 = findRoot(x2);
		// 来自同一个集合
		if (r1 == r2)
			return false;
		// 修改v1的节点个数，将v2的父节点修改为v1
		_v[r1] += _v[r2];
		_v[r2] = r1;

		return true;
	}

	size_t size() {
		int sz = 0;
		for (auto e : _v) {
			if (e < 0)
				sz++;
		}

		return sz;
	}
private:
	vector<int> _v;
};
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		UnionFindSet ufs(M.size());

		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < M[i].size(); j++) {
				if (M[i][j] == 1)
					ufs.Union(i, j);
			}
		}

		return ufs.size();
	}
};