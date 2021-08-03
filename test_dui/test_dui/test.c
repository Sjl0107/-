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
//		//选出左右孩子中小的那个
//		if (child+1 < n  && a[child + 1] > a[child])
//		{
//			child++;//选右边的
//		}//否则就是左边的
//		if (a[parent] < a[child])
//		{
//			Swap(&a[parent], &a[child]);
//			parent = child;//交换
//			child = parent * 2 + 1;//继续迭代
//		}
//		else
//		{
//			break;//已经满足条件
//		}
//	}
//}

//堆排序 排升序建大堆
//void HeapSort(int* a, int n)
//{
//	//建堆--》时间复杂度O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n - 1;
//	while (end>0)
//	{
//		Swap(&a[0], &a[end]);
//		//选出次大的
//		AdjustDown(a, end, 0);
//		end--;
//	}
//}

//void TopK()
//{
//	//找出n个数中最大或最小的前k个
//
//}

int main()
{
	//int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	int a[] = { 15,18,28,34,65,19,49,25,37,27 };
	int n = sizeof(a) / sizeof(a[0]);
	//AdjustDown(a, n, 0);
	//建堆
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