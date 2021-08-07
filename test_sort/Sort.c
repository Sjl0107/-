#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 插入排序
void InsertSort(int* a, int n)
{
	// 多趟排序
	for (int i = 0; i < n - 1; ++i)
	{
		// 把tmp插入到数组的[0,end]有序区间中
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

// 希尔排序
// 尝试算一下他的时间复杂度是多少？
// 平均 O(N^1.3)
// 最坏：O(log3(N) * N) 这里log3(N)是以3为底N的对数
void ShellSort(int* a, int n)
{
	// gap > 1的时候，预排序
	// gap == 1的时候，直接插入排序  O(N)
	int gap = n;
	while (gap > 1) // n/3/3/3.../3 == 1  -》 3^x = n  x就是这个while循环跑的次数
	{ 
		gap = (gap / 3 + 1);

		// 最坏的情况：逆序，gap很大的时-》O(N)
		// ...
		// 
		//                   gap很小时本来应该是O(N*N),但是经过前面的预排序，数组已经很接近有序的，所这里还是O(N)
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
		// 选出最大的值和最小的值
		int minIndex = left, maxIndex = left;
		for (int i = left; i <= right; ++i)
		{
			if (a[i] < a[minIndex])
				minIndex = i;

			if (a[i] > a[maxIndex])
				maxIndex = i;
		}

		Swap(&a[left], &a[minIndex]);
		// 如果max和left位置重叠，max被换走了，要修正一下max的位置
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}

		Swap(&a[right], &a[maxIndex]);
		++left;
		--right;
	}
}

// 堆排序
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
	// 升序  建大堆
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

// 最坏：O（N^2）
// 最好：O(N)
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

// 初闻不知曲中意，再闻已是曲中人
//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//		return;
//
//	int left = begin, right = end;
//	int keyi = left;
//	while (left < right)
//	{
//		// 找小
//		while (left < right && a[right] >= a[keyi])
//			--right;
//
//		// 找大
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



// hoare版本 -- 左右指针法
int PartSort1(int* a, int left, int right)
{
	// 三数取中
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int keyi = left;
	while (left < right)
	{
		// 找小
		while (left < right && a[right] >= a[keyi])
			--right;

		// 找大
		while (left < right && a[left] <= a[keyi])
			++left;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);

	return left;
}

// 挖坑法
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int key = a[left];
	while (left < right)
	{
		// 找小
		while (left < right && a[right] >= key)
		{
			--right;
		}

		// 放到左边的坑位中,右边就形成新的坑
		a[left] = a[right];

		// 找大
		while (left < right && a[left] <= key)
		{
			++left;
		}

		// 放到右边的坑位中，左边就形成新的坑
		a[right] = a[left];
	}

	a[left] = key;

	return left;
}

// 前后指针法
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


// 前后指针法
// [begin, end]
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	// 1、如果这个子区间是数据较多，继续选key单趟，分割子区间分治递归
	// 2、如果这个子区间是数据较小，再去分治递归不太划算
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

// 非递归
// 递归 现代编译器优化很好，性能已经不是大问题
// 最大的问题->递归深度太深，程序本身没问题，但是栈空间不够，导致栈溢出
// 只能改成非递归，改成非递归有两种方式：
// 1、直接改循环-》斐波那契数列求解
// 2、树遍历非递归和快排非递归等等，只能用Stack存储数据模拟递归过程
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

	// 归并完成以后，拷贝回到原数组
	for (; j <= end2; ++j)
		a[j] = tmp[j];
}

// 时间复杂度：O(N*logN)
// 空间复杂度：O(N)
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	// [left, mid][mid+1,right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	// 两段有序子区间归并tmp,并拷贝回去
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
			// [i,i+gap-1][i+gap, i+2*gap-1] 归并
			int begin1 = i, end1 = i + gap - 1, begin2 = i + gap, end2 = i + 2 * gap - 1;

			// 如果第二个小区间不存在就不需要归并了，结束本次循环
			if (begin2 >= n)
				break;

			// 如果第二个小区间存在，但是第二个小区间不够gap个，结束位置越界了，需要修正一下
			if (end2 >= n)
				end2 = n - 1;

			_Merge(a, tmp, begin1, end1, begin2, end2);
		}

		gap *= 2;
	}

	free(tmp);
}

// 时间复杂度：O(N+range)
// 只适合，一组数据，数据的范围比较集中. 如果范围集中，效率是很高的，但是局限性也在这里
// 并且只适合整数，如果是浮点数、字符串等等就不行了
// 空间辅助度：O(range)
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