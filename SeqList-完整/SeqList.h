#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// ��̬��˳���
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
	int size;      // ��Ч���ݵĸ���
	int capacity;  // ����
}SeqList, SEQ;

// �ڴ��и��������ݵĽṹ��ɾ��ĵĽ��

// ͷ��β�壬ͷɾβɾ
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