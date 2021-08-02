#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// 静态的顺序表
//#define N 100
//struct SeqList
//{
//	int a[N];
//	int size;
//};

//typedef ContactInfo SeqDataType;
typedef int SeqDataType;

typedef struct SeqList
{
	SeqDataType* a;
	int size;      // 有效数据的个数
	int capacity;  // 容量
}SeqList, SEQ;

// 内存中个管理数据的结构增删查改的借口

// 头插尾插，头删尾删
void SeqListInit(SeqList* pq);
void SeqListDestory(SeqList* pq);
void SeqListPrint(SeqList* pq);

//void SeqListPushBack(SEQ seq, SeqDataType x);
void SeqListPushBack(SeqList* pq, SeqDataType x);
void SeqListPushFront(SeqList* pq, SeqDataType x);
void SeqListPopBack(SeqList* pq);
void SeqListPopFront(SeqList* pq);
int SeqListFind(SeqList* pq, SeqDataType x);
void SeqListInsert(SeqList* pq, int pos, SeqDataType x);
void SeqListErase(SeqList* pq, int pos);
void SeqListModify(SeqList* pq, int pos, SeqDataType x);