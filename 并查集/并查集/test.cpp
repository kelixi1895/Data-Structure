#include <iostream>
#include <vector>
using namespace std;

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

int main() {
	system("pause");
	return 0;
}