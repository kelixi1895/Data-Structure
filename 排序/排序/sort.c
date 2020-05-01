#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

//打印数组
void printArr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//交换数据
void Swap(int* arr, int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
//插入排序
void insertSort(int* arr, int n) {
	//从未排序的位置开始向前寻找可插入的位置
	for (int bound = 0; bound < n - 1; bound++) {
		//寻找合适位置
		int key = arr[bound + 1], i = bound;
		for (; i >= 0; i--) {
			if (key < arr[i]) {
				arr[i + 1] = arr[i];
			} else {
				break;
			}
		}
		//插入数据
		arr[i + 1] = key;
	}
}
//希尔排序
void shellSort(int* arr, int n) {
	int gap = n;
	while (gap > 1) {
		gap /= 2;
		//从未排序的位置开始向前寻找可插入的位置
		for (int bound = 0; bound < n - gap; bound++) {
			//寻找合适位置
			int key = arr[bound + gap], i = bound;
			for (; i >= 0; i -= gap) {
				if (key < arr[i]) {
					arr[i + gap] = arr[i];
				} else {
					break;
				}
			}
			//插入数据
			arr[i + gap] = key;
		}
	}
}

//选择排序
void selectSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		//记录未排序中最值的索引
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		Swap(arr, min, i);
	}
}
//堆排序
void shiftDown(int* arr, int n, int parent) {
	int child = 2 * parent + 1;
	while (child < n) {
		if (child + 1 < n && arr[child + 1] > arr[child])
			child++;
		if (arr[child] > arr[parent]) {
			Swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		} else {
			break;
		}
	}
}
void heapSort(int* arr, int n) {
	//原地建堆
	for (int i = (n - 2) / 2; i >= 0; i--) {
		shiftDown(arr, n, i);
	}
	//循环删除堆顶元素
	while (n) {
		Swap(arr, 0, n - 1);
		n--;
		shiftDown(arr, n, 0);
	}
}
//冒泡排序
void bubbleSort(int* arr, int n) {
	for (int bound = 0; bound < n - 1; bound++) {
		//添加标记flag，在发现剩下未排序部分已经有序时跳出循环,flag为1表示有序
		int flag = 1;
		for (int i = n - 1; i > bound; i--) {
			if (arr[i] < arr[i - 1]) {
				Swap(arr, i, i - 1);
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}

//快速排序递归实现
//hoare划分方法
int partion1(int* arr, int start, int end) {
	int key = arr[start], keyPos = start;
	while (start < end) {
		//从后向前找第一个小于key的位置
		while (start < end && arr[end] >= key)
			end--;
		//从前往后找第一个大于key的位置
		while (start < end && arr[start] <= key)
			start++;
		//交换end和start处的元素
		Swap(arr, end, start);
	}
	//将基准值处和相遇位置处交换
	Swap(arr, end, keyPos);
	return end;
}
//挖坑划分法
int partion2(int* arr, int start, int end) {
	int key = arr[start];
	while (start < end) {
		//从后往前找第一个小于key的位置
		while (start < end && arr[end] >= key)
			end--;
		//将元素填入坑中
		arr[start] = arr[end];
		//从前往后找第一个大于key的位置
		while (start < end && arr[start] <= key)
			start++;
		arr[end] = arr[start]; 
	}
	//将基准值填入坑中
	arr[start] = key;
	return start;
}
//前后指针划分法
int partion3(int* arr, int start, int end) {
	int key = arr[start];
	//最后一个小于基准值的位置
	int pre = start;
	//下一个小于基准值的位置
	int cur = start + 1;
	while (cur <= end) {
		//新发现的小数据和尾指针指向的位置不连续，则中间含有大于基准值的数据，故进行交换
		//大数据向后移动，小数据向前移动
		if (arr[cur] < key && ++pre != cur)
			Swap(arr, pre, cur);
		++cur;
	}
	Swap(arr, pre, start);
	return pre;
}
void quickSort(int* arr, int start, int end) {
	if (start >= end)
		return;
	int key = arr[start];
	//根据基准值划分区间
	int keyPos = partion3(arr, start, end);
	//左右区间分别排序
	quickSort(arr, 0, keyPos - 1);
	quickSort(arr, keyPos + 1, end);
}
