#include"sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序
void InsertSort(int* a, int n)
{
	//多趟排序
	for (int i = 0; i < n - 1; i++) 
	{
		//每趟，把tmp插入到数组的[0,end]的有序区间中
		int end = i;
		int tmp = a[end+1];
		
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}
//希尔排序
void ShellSort(int* a, int n)
{
	//gap>1时，是预排序
	//gap=1时，是直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//对gap组数据排完
		for (int i = 0; i < n - gap; i++)
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
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
}
//交换
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = *p1;
}
//选择排序
void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		//选出最大值和最小值
		int minIndex = left, maxIndex = left;
		for (int i = left; i <= right; i++)
		{
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
			if (a[i] > a[maxIndex])
			{
				maxIndex = i;
			}
		}
		Swap(&a[left], &a[minIndex]);//最小的放左边
		//如果max和left位置重叠，max被换走了，要修正回来
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(&a[right], &a[maxIndex]);//最大的放右边
		left++;
		right--;
	}
	
}

//堆排序
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右孩子中小的那个
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;//选右边的
		}//否则就是左边的
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;//交换
			child = parent * 2 + 1;//继续迭代
		}
		else
		{
			break;//已经满足条件
		}
	}
}

void HeapSort(int* a, int n)
{
	//升序建大堆
	for (int i = (n - 1 - 1) / 2; i > 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int end = n; end > 0; end--)
	{
		int exchange = 0;
		//一趟冒泡排序
		for (int i = 1; i < n; i++) {
			if (a[i - 1] < a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		//没交换说明有序了 可以退出排序
		if (exchange == 0)
		{
			break;
		}
	}
}


//优化
//三数取中法
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;// /2
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if(a[left]>a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[left])
		{
			return mid;
		}
		else if (a[left]<a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//hoare版本--左右指针法
int PartSort1(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[right]);
	//单趟操作
	//int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		//右边找小
		while (a[right] >= a[keyi] && left < right)
		{
			right--;
		}
		//左边找大
		while (a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	int meeti = left;
	Swap(&a[keyi], &a[meeti]);
	return left;
}
//挖坑法
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	int key = a[left];
	while (left < right)
	{
		//找小的
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//放到左边的坑中
		a[left] = a[right];
		//右边就形成了新的坑
		//找大的
		while (a[left] <= key)
		{
			left++;
		}
		//放到右边的坑中
		a[right] = a[left];
		//左边又形成了新的坑
	}
	//相遇后 把key放到最后相遇的坑中
	a[left] = key;
	return left;
}
//前后指针法
//cur和prev开始一前一后
//cur去找比keyi位置小的值，找到后，prev++，再交换prev和cur位置的值，直到数组尾
//最后再交换keyi和prev位置的值
int PartSort3(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

//快速排序
void QuickSort(int* a, int begin,int end)
{
	if (begin >= end)
	{
		return;
	}
	//小区间优化
	//如果数据较多，则选key，分割子区间，分治递归
	if ((end - begin) > 10)
	{
		int keyi = PartSort3(a, begin, end);

		//[begin,meeti-1] [meeti+1,end]这两段再进行上述操作
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	//如果数据较少，则用插入排序
	else
	{
		InsertSort(a + begin, end - begin + 1);
	}

	
}
//快速排序非递归
//
//void QuickSortNonR(int* a, int begin, int end)
//{
//
//}
// 
void _MergeSort(int* a, int left, int right,int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	//左右都要有序 
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//归并
	//两段有序子区间归并到tmp，并拷贝回去
	int begin1 = left, end1 = mid;
	int begin2 = mid+1, end2 = right;
	int i = left;
	while (begin1<=end1 && begin2<=end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1<=end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	//归并完后 拷贝回原数组
	for (int j = left; j <= right; j++)
	{
		a[j] = tmp[j];
	}
}
//归并排序
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if(tmp==NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}