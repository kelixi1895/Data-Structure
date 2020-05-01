#pragma once
#include <stdlib.h>
#include <stdio.h>

//打印数组
void printArr(int* arr, int n);
//插入排序
void insertSort(int* arr, int n);
//希尔排序
void shellSort(int* arr, int n);
//选择排序
void selectSort(int* arr, int n);

//堆排序
void shiftDown(int* arr, int n, int parent);
void heapSort(int*arr, int n);
//冒泡排序
void bubbleSort(int* arr, int n);

//快速排序递归实现
//hoare划分方法
int partion1(int* arr, int start, int end);
//挖坑划分法
int partion2(int* arr, int start, int end);
//前后指针划分法
int partion3(int* arr, int start, int end);
void quickSort(int* arr, int start, int end);
