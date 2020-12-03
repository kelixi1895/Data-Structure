/*
给定一个由表示变量之间关系的字符串方程组成的数组每个字符串方程 equations[i] 的长度为 4
，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同）
，表示单字母变量名。
只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 
*/

class UnionFindSet {
public:
	UnionFindSet(int n) {
		_v.resize(n, -1);
	}

	int findRoot(int x) {
		while (_v[x] >= 0) {
			x = _v[x];
		}

		return x;
	}

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

private:
	vector<int> _v;
};
class Solution {
public:
	bool equationsPossible(vector<string>& equations) {
		UnionFindSet ufs(26);
		for (auto str : equations) {
			// 将相等的字符合并到一个集合中
			if (str[1] == '=') {
				ufs.Union(str[0] - 'a', str[3] - 'a');
			}
		}

		for (auto str : equations) {
			// 判断不相等的字符是否在同一个集合
			if (str[1] == '!') {
				int r1 = ufs.findRoot(str[0] - 'a');
				int r2 = ufs.findRoot(str[3] - 'a');
				if (r1 == r2)
					return false;
			}
		}

		return true;
	}
};