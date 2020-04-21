#include "heap.h"

// 堆的构建(建小堆）
void HeapCreate(Heap* hp, HPDataType* arr, int n) {
	//拷贝数据
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_capacity = hp->_size = n;
	memcpy(hp->_a, arr, sizeof(HPDataType) * n);
	//从最后一个非叶节点开始进行多次向下调整
	for (int i = (n - 2) / 2; i >= 0; i--) {
		shiftDown(hp->_a, hp->_size, i);
	}
}
//交换数据
void Swap(HPDataType* arr, int left, int right) {
	HPDataType tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
//一次向下调整
void shiftDown(HPDataType* arr, int size, int parent) {
	int child = 2 * parent + 1;
	while (child < size) {
		if (child + 1 < size && arr[child + 1] < arr[child]) {
			child++;
		}
		if (arr[child] < arr[parent]) {
			Swap(arr, parent, child);
			parent = child;
			child = 2 * parent + 1;
		} else {
			break;
		}
	}
}
//遍历堆的元素
void HeapPrint(Heap* hp) {
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x) {
	//检查容量
	if (hp->_size == hp->_capacity) {
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * hp->_capacity);
	}
	//尾插
	hp->_a[hp->_size++] = x;
	//向上调整
	int child = hp->_size - 1;
	int parent = (child - 1) / 2;
	while (parent >= 0) {
		if (hp->_a[child] < hp->_a[parent]) {
			Swap(hp->_a, parent, child);
			child = parent;
			parent = (child - 1) / 2;
		} else {
			break;
		}
	}
}
// 堆的删除
void HeapPop(Heap* hp) {
	if (hp->_size == 0) {
		return;
	}
	//交换头结点和最后一个叶节点
	Swap(hp->_a, 0, hp->_size - 1);
	//尾删除
	hp->_size--;
	//从根节点向下调整一次
	shiftDown(hp->_a, hp->_size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp) {
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp) {
	return hp->_size == 0;
}
// 堆的销毁
void HeapDestory(Heap* hp) {
	free(hp->_a);
	hp->_size = hp->_capacity = 0;
}
// 对数组进行堆排序
void HeapSort(int* arr, int n) {
	//原地建堆
	for (int i = (n - 2) / 2; i >= 0; i--) {
		shiftDown(arr, n, i);
	}
	while (n > 1) {
		//堆的删除（将最值放置数组最后一个元素）
		Swap(arr, 0, n - 1);
		n--;
		//向下调整一次
		shiftDown(arr, n, 0);
	}
} 

// TopK问题：找出N个数里面最大 / 最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k) {
	//以前k个元素建堆(小堆）
	Heap hp;
	HeapCreate(&hp, a, k);
	
	//遍历后面的元素
	for (int i = k; i < n; i++) {
		int top = HeapTop(&hp);
		if (a[i] > top) {
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
}
void TestTopk() {
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintTopK(a, 10, 3);
}
