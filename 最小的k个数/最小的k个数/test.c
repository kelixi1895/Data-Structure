#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/

typedef struct heap {
	int* arr;
	int size;
	int capacity;
}heap;

void Swap(int*arr, int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
//一次向下调整
void shiftDown(int* arr, int n, int parent) {
	int child = 2 * parent + 1;
	while (child < n) {
		//child指向较大的孩子
		if (child + 1 < n && arr[child + 1] > arr[child]) {
			child++;
		}
		//若孩子大于父亲，交换
		if (arr[child] > arr[parent]) {
			Swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
void heapCreate(heap* hp, int* arr, int n) {
	//拷贝元素，初始化
	hp->arr = (int*)malloc(sizeof(int) * n);
	memcpy(hp->arr, arr, sizeof(int) * n);
	hp->size = hp->capacity = n;

	//从第一个非叶节点往前向下调整
	for (int parent = (n - 2) / 2; parent >= 0; parent--) {
		shiftDown(hp->arr, n, parent);
	}
}
int heapTop(heap* hp) {
	return hp->arr[0];
}
//向上调整
void shiftUp(int* arr, int child) {
	int parent = (child - 1) / 2;
	while (parent >= 0) {
		//孩子大于父亲，交换
		if (arr[child] > arr[parent]) {
			Swap(arr, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
//入堆
void heapPush(heap* hp, int val) {
	//检查容量
	if (hp->size == hp->capacity) {
		hp->capacity *= 2;
		hp->arr = (int*)realloc(hp->arr, sizeof(int) * hp->capacity);
	}
	//尾插
	hp->arr[hp->size++] = val;
	//向上调整
	shiftUp(hp->arr, hp->size - 1);
}
//堆的删除（删除堆顶之后重新调整）
void heapPop(heap* hp) {
	//交换首尾元素
	Swap(hp->arr, 0, hp->size - 1);
	//尾删
	hp->size--;
	//向下调整一次
	shiftDown(hp->arr, hp->size, 0);
}


//挖坑法根据基准值划分区间
int pation(int* arr, int start, int end) {
	int key = arr[start];
	while (start < end) {
		//从后往前找第一个小于基准值的元素
		while (start < end && arr[end] >= key) {
			end--;
		}
		//填入坑中
		arr[start] = arr[end];
		//从前往后找第一个大于基准值的元素
		while (start < end && arr[start] <= key) {
			start++;
		}
		//填入坑中
		arr[end] = arr[start];
	}
	//将基准值填入相遇的坑的位置
	arr[start] = key;
	//返回基准值位置
	return start;
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
	//根据快排的划分来逐渐确定位置为k的元素，前k个元素即为所求
	// *returnSize = k;
	// int* res = (int*)malloc(sizeof(int) * k);
	// if (k == 0) {
	//     return res;
	// }

	// //k和数组长度相等，直接拷贝元素
	// if (k == arrSize) {
	//     memcpy(res, arr, sizeof(int) * k);
	//     return res;
	// }
	// //不断地划分，直至划分后基准值的位置为k，则前k个元素一定是最好的k个数
	// int start = 0, end = arrSize - 1;
	// int idx = pation(arr, start, end);
	// while (idx != k) {
	//     //继续划分左半区间
	//     if (idx > k) {
	//         end = idx - 1;
	//         idx = pation(arr, start, end);
	//     } else {
	//         //划分右半区间
	//         start = idx + 1;
	//         idx = pation(arr, start, end);
	//     }
	// }

	// //拷贝前k个元素
	// memcpy(res, arr, sizeof(int) * k);

	// return res;

	//建大堆存放前k个数据，遍历后面的数据，根据堆顶元素和该元素的大小确定是否入堆，最终堆内的数据即为所求

	int* res = (int*)malloc(sizeof(int) * k);
	*returnSize = k;
	if (k == 0) {
		return res;
	}
	heap hp;
	//用前k个数创建堆
	heapCreate(&hp, arr, k);

	//遍历之后的元素
	for (int i = k; i < arrSize; i++) {
		int top = heapTop(&hp);
		if (arr[i] < top) {
			heapPop(&hp);
			heapPush(&hp, arr[i]);
		}
	}

	//拷贝堆中的元素
	memcpy(res, hp.arr, sizeof(int) * k);
	return res;
}
int main() {
	system("pause");
	return 0;
}