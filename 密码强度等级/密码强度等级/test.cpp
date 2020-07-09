#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	while (cin >> str) {
		int score = 0;
		// 密码长度
		int size = str.size();
		if (size <= 4)
			score += 5;
		else if (size <= 7)
			score += 10;
		else
			score += 25;

		//遍历字符串，统计字母、数字、符号的个数
		int lowerLetter = 0, bigerLetter,
			allLetter = 0, num = 0, other = 0; //分别为小写字母、大写字母、字母、数字、其他字符的个数
		for (int i = 0; i < size; i++) {
			if (str[i] >= '0' && str[i] <= '9')
				num++;
			else if ((str[i] >= 'a' && str[i] <= 'z') ||
				(str[i] >= 'A' && str[i] <= 'Z')) {
				if (str[i] <= 'Z')
					bigerLetter++;
				else
					lowerLetter++;
				allLetter++;
			}
			else {
				other++;
			}
		}

		if (lowerLetter) {
			score += 10;
		}
		if (bigerLetter) {
			score += 10;
		}
		if (num >= 1)
			score += 10;
		if (num > 1)
			score += 10;
		if (other >= 1)
			score += 10;
		if (other > 1)
			score += 15;
		if (lowerLetter && bigerLetter && num && other) {
			score += 5;
		}
		else if (allLetter && num && other)
			score += 3;
		else if (allLetter && num)
			score += 2;

		if (score >= 90)
			cout << "VERY_SECURE" << endl;
		else if (score >= 80)
			cout << "SECURE" << endl;
		else if (score >= 70)
			cout << "VERY_STRONG" << endl;
		else if (score >= 60)
			cout << "STRONG" << endl;
		else if (score >= 50)
			cout << "AVWEAGE" << endl;
		else if (score >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}
int main() {
	system("pause");
	return 0;
}