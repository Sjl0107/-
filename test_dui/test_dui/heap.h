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
//���µ���
void AdjustDown(int* a, int n, int parent);
//���ϵ���
void AdjustUp(int* a, int child);
//��ʼ��
void HeapInit(HP* php,HPDataType* a, int n);
//����
void HeapDestroy(HP* php);
//������
void HeapPush(HP* php, HPDataType x);
//ɾ����
void HeapPop(HP* php);
//���ضѶ�����
HPDataType HeapTop(HP* php);
//���ضѵ����ݸ���
int HeapSize(HP* php);
//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(HP* php);
//��ӡ
void HeapPrint(HP* php);
