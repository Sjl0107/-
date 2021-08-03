#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int HPDataType;
struct  Heap
{
	HPDataType* a;
	int size;
	int capacity;
};

typedef struct Heap HP;

//
void Swap(int* p1, int* p2);
//向下调整
void AdjustDown(int* a, int n, int parent);
//向上调整
void AdjustUp(int* a, int child);
//初始化
void HeapInit(HP* php,HPDataType* a, int n);
//销毁
void HeapDestroy(HP* php);
//入数据
void HeapPush(HP* php, HPDataType x);
//删数据
void HeapPop(HP* php);
//返回堆顶数据
HPDataType HeapTop(HP* php);
//返回堆的数据个数
int HeapSize(HP* php);
//判断堆是否为空
bool HeapEmpty(HP* php);
//打印
void HeapPrint(HP* php);
