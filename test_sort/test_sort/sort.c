#include"sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������
void InsertSort(int* a, int n)
{
	//��������
	for (int i = 0; i < n - 1; i++) 
	{
		//ÿ�ˣ���tmp���뵽�����[0,end]������������
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
//ϣ������
void ShellSort(int* a, int n)
{
	//gap>1ʱ����Ԥ����
	//gap=1ʱ����ֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//��gap����������
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
//����
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = *p1;
}
//ѡ������
void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		//ѡ�����ֵ����Сֵ
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
		Swap(&a[left], &a[minIndex]);//��С�ķ����
		//���max��leftλ���ص���max�������ˣ�Ҫ��������
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(&a[right], &a[maxIndex]);//���ķ��ұ�
		left++;
		right--;
	}
	
}

//������
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//ѡ�����Һ�����С���Ǹ�
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;//ѡ�ұߵ�
		}//���������ߵ�
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;//����
			child = parent * 2 + 1;//��������
		}
		else
		{
			break;//�Ѿ���������
		}
	}
}

void HeapSort(int* a, int n)
{
	//���򽨴��
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

//ð������
void BubbleSort(int* a, int n)
{
	for (int end = n; end > 0; end--)
	{
		int exchange = 0;
		//һ��ð������
		for (int i = 1; i < n; i++) {
			if (a[i - 1] < a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		//û����˵�������� �����˳�����
		if (exchange == 0)
		{
			break;
		}
	}
}


//�Ż�
//����ȡ�з�
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

//hoare�汾--����ָ�뷨
int PartSort1(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[right]);
	//���˲���
	//int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		//�ұ���С
		while (a[right] >= a[keyi] && left < right)
		{
			right--;
		}
		//����Ҵ�
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
//�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	int key = a[left];
	while (left < right)
	{
		//��С��
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//�ŵ���ߵĿ���
		a[left] = a[right];
		//�ұ߾��γ����µĿ�
		//�Ҵ��
		while (a[left] <= key)
		{
			left++;
		}
		//�ŵ��ұߵĿ���
		a[right] = a[left];
		//������γ����µĿ�
	}
	//������ ��key�ŵ���������Ŀ���
	a[left] = key;
	return left;
}
//ǰ��ָ�뷨
//cur��prev��ʼһǰһ��
//curȥ�ұ�keyiλ��С��ֵ���ҵ���prev++���ٽ���prev��curλ�õ�ֵ��ֱ������β
//����ٽ���keyi��prevλ�õ�ֵ
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

//��������
void QuickSort(int* a, int begin,int end)
{
	if (begin >= end)
	{
		return;
	}
	//С�����Ż�
	//������ݽ϶࣬��ѡkey���ָ������䣬���εݹ�
	if ((end - begin) > 10)
	{
		int keyi = PartSort3(a, begin, end);

		//[begin,meeti-1] [meeti+1,end]�������ٽ�����������
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	//������ݽ��٣����ò�������
	else
	{
		InsertSort(a + begin, end - begin + 1);
	}

	
}
//��������ǵݹ�
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
	//���Ҷ�Ҫ���� 
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//�鲢
	//��������������鲢��tmp����������ȥ
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
	//�鲢��� ������ԭ����
	for (int j = left; j <= right; j++)
	{
		a[j] = tmp[j];
	}
}
//�鲢����
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