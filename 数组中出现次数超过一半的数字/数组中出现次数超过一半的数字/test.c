#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#includ <stdio.h>

void Swap(int* arr, int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
//前后指针法根据基准值划分区间
int pation(int* arr, int start, int end) {
	//选取基准值
	int key = arr[start];
	int cur = start + 1;
	int pre = start;//最后一个小于key的位置
	while (cur <= end) {
		if (arr[cur] < key && ++pre != cur) {
			Swap(arr, pre, cur);
		}
		cur++;
	}
	Swap(arr, pre, start);

	//返回基准值所在位置
	return pre;
}
int majorityElement(int* nums, int numsSize){
	//遍历数组，保留两个值，一个是数组中的数字，一个是其次数
	//遍历的时候，若当前元素与保留的数字相同，次数加1，否则次数-1，如果减到0，则
	//修改保留的数字为当前元素，次数为1
	// int key = nums[0], n = 1;
	// for (int i = 1; i < numsSize; i++) {
	//     if (nums[i] == key) {
	//         n++;
	//     } else {
	//         n--;
	//         if (n == 0) {
	//             key = nums[i];
	//             n = 1;
	//         }
	//     }
	// }

	// return key;


	//通过不断的进行划分找到中位数，而中位数即一定是所求的数字
	int start = 0, end = numsSize - 1;
	int mid = (numsSize - 1) / 2;
	int idx = pation(nums, start, end);
	while (idx != mid) {
		if (idx < mid) {
			start = idx + 1;
			idx = pation(nums, start, end);
		}
		else {
			end = idx - 1;
			idx = pation(nums, start, end);
		}
	}

	return nums[mid];
}

int main() {
	system("pause");
	return 0;
}