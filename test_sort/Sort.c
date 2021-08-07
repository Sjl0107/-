#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// ��������
void InsertSort(int* a, int n)
{
	// ��������
	for (int i = 0; i < n - 1; ++i)
	{
		// ��tmp���뵽�����[0,end]����������
		int end = i;
		int tmp = a[end+1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// ϣ������
// ������һ������ʱ�临�Ӷ��Ƕ��٣�
// ƽ�� O(N^1.3)
// ���O(log3(N) * N) ����log3(N)����3Ϊ��N�Ķ���
void ShellSort(int* a, int n)
{
	// gap > 1��ʱ��Ԥ����
	// gap == 1��ʱ��ֱ�Ӳ�������  O(N)
	int gap = n;
	while (gap > 1) // n/3/3/3.../3 == 1  -�� 3^x = n  x�������whileѭ���ܵĴ���
	{ 
		gap = (gap / 3 + 1);

		// ������������gap�ܴ��ʱ-��O(N)
		// ...
		// 
		//                   gap��Сʱ����Ӧ����O(N*N),���Ǿ���ǰ���Ԥ���������Ѿ��ܽӽ�����ģ������ﻹ��O(N)
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else{
					break;
				}
			}

			a[end + gap] = tmp;
		}
		//printf("gap:%d->", gap);
		//PrintArray(a, n);
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// N N-2 N-4...
// O(N^2)
void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		// ѡ������ֵ����С��ֵ
		int minIndex = left, maxIndex = left;
		for (int i = left; i <= right; ++i)
		{
			if (a[i] < a[minIndex])
				minIndex = i;

			if (a[i] > a[maxIndex])
				maxIndex = i;
		}

		Swap(&a[left], &a[minIndex]);
		// ���max��leftλ���ص���max�������ˣ�Ҫ����һ��max��λ��
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}

		Swap(&a[right], &a[maxIndex]);
		++left;
		--right;
	}
}

// ������
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//O(N*log(N))
void HeapSort(int* a, int n)
{
	// ����  �����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

// ���O��N^2��
// ��ã�O(N)
void BubbleSort(int* a, int n)
{
	//for (int j = 0; j < n; ++j)
	//{
	//	for (int i = 1; i < n-j; ++i)
	//	{
	//		if (a[i - 1] > a[i])
	//		{
	//			Swap(&a[i - 1], &a[i]);
	//		}
	//	}
	//}

	for (int end = n; end > 0; --end)
	{
		int exchange = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
		{
			break;
		}
	}
}

// ���Ų�֪�����⣬��������������
//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//		return;
//
//	int left = begin, right = end;
//	int keyi = left;
//	while (left < right)
//	{
//		// ��С
//		while (left < right && a[right] >= a[keyi])
//			--right;
//
//		// �Ҵ�
//		while (left < right && a[left] <= a[keyi])
//			++left;
//
//		Swap(&a[left], &a[right]);
//	}
//	int meeti = left;
//
//	Swap(&a[keyi], &a[meeti]);
//
//
//	// [begin, meeti-1] meeti [meeti+1, end]
//	QuickSort(a, begin, meeti - 1);
//	QuickSort(a, meeti+1, end);
//}
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	// left  mid  right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		} 
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}



// hoare�汾 -- ����ָ�뷨
int PartSort1(int* a, int left, int right)
{
	// ����ȡ��
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int keyi = left;
	while (left < right)
	{
		// ��С
		while (left < right && a[right] >= a[keyi])
			--right;

		// �Ҵ�
		while (left < right && a[left] <= a[keyi])
			++left;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);

	return left;
}

// �ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int key = a[left];
	while (left < right)
	{
		// ��С
		while (left < right && a[right] >= key)
		{
			--right;
		}

		// �ŵ���ߵĿ�λ��,�ұ߾��γ��µĿ�
		a[left] = a[right];

		// �Ҵ�
		while (left < right && a[left] <= key)
		{
			++left;
		}

		// �ŵ��ұߵĿ�λ�У���߾��γ��µĿ�
		a[right] = a[left];
	}

	a[left] = key;

	return left;
}

// ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	//int midIndex = GetMidIndex(a, left, right);
	//Swap(&a[left], &a[midIndex]);

	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}

		++cur;
	}

	Swap(&a[keyi], &a[prev]);

	return prev;
}


// ǰ��ָ�뷨
// [begin, end]
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	// 1�������������������ݽ϶࣬����ѡkey���ˣ��ָ���������εݹ�
	// 2�������������������ݽ�С����ȥ���εݹ鲻̫����
	if (end-begin > 20)
	{
		int keyi = PartSort3(a, begin, end);

		// [begin, keyi-1] keyi [keyi+1, end]
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
	{
		//HeapSort(a + begin, end - begin + 1);
		InsertSort(a + begin, end - begin + 1);
	}
}

// �ǵݹ�
// �ݹ� �ִ��������Ż��ܺã������Ѿ����Ǵ�����
// ��������->�ݹ����̫�������û���⣬����ջ�ռ䲻��������ջ���
// ֻ�ܸĳɷǵݹ飬�ĳɷǵݹ������ַ�ʽ��
// 1��ֱ�Ӹ�ѭ��-��쳲������������
// 2���������ǵݹ�Ϳ��ŷǵݹ�ȵȣ�ֻ����Stack�洢����ģ��ݹ����
// [begin, end]
#include"Stack.h"

void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int left, right;
		right = StackTop(&st);
		StackPop(&st);

		left = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort1(a, left, right);
		if (left < keyi-1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi-1);
		}

		if (keyi+1 < right)
		{
			StackPush(&st, keyi+1);
			StackPush(&st, right);
		}
	}

	StackDestroy(&st);
}

void _Merge(int* a, int* tmp, int begin1, int end1, int begin2, int end2)
{
	int j = begin1;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}

	while (begin1 <= end1)
		tmp[i++] = a[begin1++];

	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	// �鲢����Ժ󣬿����ص�ԭ����
	for (; j <= end2; ++j)
		a[j] = tmp[j];
}

// ʱ�临�Ӷȣ�O(N*logN)
// �ռ临�Ӷȣ�O(N)
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	// [left, mid][mid+1,right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	// ��������������鲢tmp,��������ȥ
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	_Merge(a, tmp, left, mid, mid + 1, right);
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [i,i+gap-1][i+gap, i+2*gap-1] �鲢
			int begin1 = i, end1 = i + gap - 1, begin2 = i + gap, end2 = i + 2 * gap - 1;

			// ����ڶ���С���䲻���ھͲ���Ҫ�鲢�ˣ���������ѭ��
			if (begin2 >= n)
				break;

			// ����ڶ���С������ڣ����ǵڶ���С���䲻��gap��������λ��Խ���ˣ���Ҫ����һ��
			if (end2 >= n)
				end2 = n - 1;

			_Merge(a, tmp, begin1, end1, begin2, end2);
		}

		gap *= 2;
	}

	free(tmp);
}

// ʱ�临�Ӷȣ�O(N+range)
// ֻ�ʺϣ�һ�����ݣ����ݵķ�Χ�Ƚϼ���. �����Χ���У�Ч���Ǻܸߵģ����Ǿ�����Ҳ������
// ����ֻ�ʺ�����������Ǹ��������ַ����ȵȾͲ�����
// �ռ丨���ȣ�O(range)
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}

	int range = max - min + 1;
	int* count = malloc(sizeof(int)*range);
	memset(count, 0, sizeof(int)*range);
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	int i = 0;
	for (int j = 0; j < range; ++j)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}

	free(count);
}