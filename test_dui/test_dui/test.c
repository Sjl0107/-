//#include<iostream>
//using namespace std;
#include"heap.h"

//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//ѡ�����Һ�����С���Ǹ�
//		if (child+1 < n  && a[child + 1] > a[child])
//		{
//			child++;//ѡ�ұߵ�
//		}//���������ߵ�
//		if (a[parent] < a[child])
//		{
//			Swap(&a[parent], &a[child]);
//			parent = child;//����
//			child = parent * 2 + 1;//��������
//		}
//		else
//		{
//			break;//�Ѿ���������
//		}
//	}
//}

//������ �����򽨴��
//void HeapSort(int* a, int n)
//{
//	//����--��ʱ�临�Ӷ�O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n - 1;
//	while (end>0)
//	{
//		Swap(&a[0], &a[end]);
//		//ѡ���δ��
//		AdjustDown(a, end, 0);
//		end--;
//	}
//}

//void TopK()
//{
//	//�ҳ�n������������С��ǰk��
//
//}

int main()
{
	//int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	int a[] = { 15,18,28,34,65,19,49,25,37,27 };
	int n = sizeof(a) / sizeof(a[0]);
	//AdjustDown(a, n, 0);
	//����
	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	//{
	//	AdjustDown(a, n, i);
	//}
	//HeapSort(a, n);
	HP hp;
	HeapInit(&hp, a, n);
	HeapPrint(&hp);

	HeapPush(&hp, 8);
	HeapPrint(&hp);
	
	HeapPush(&hp, 88);
	HeapPrint(&hp);
	
	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);



	return 0;
}