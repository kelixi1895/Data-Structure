#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//在数组中找到两个不相等的数字并都从数组中删除，之前个数超过一半的数字的个数仍然大于数组长度的一半
//当数组的个数只有原来的一半的时候，剩下的就都为所求
int getMornThanHalfNum(vector<int>& v) {
	int size = v.size();
	if (v.size() == 1)
		return v.front();
	while (v.size() > size / 2) {
		auto it = ++v.begin();
		while (it != v.end()) {
			if (*it != v.front()) {
				v.erase(it);
				v.erase(v.begin());
				break;
			}
		}
	}

	return v.front();

}
int main() {
	int arr[] = { 1, 4, 4, 1, 6, 4 , 4};
	vector<int> v(arr, arr + sizeof(arr));
	int ret = getMornThanHalfNum(v);

	cout << ret << endl;
	system("pause");
	return 0;
}