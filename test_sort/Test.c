#include "Sort.h"

void TestInsertSort()
{
	int a[] = { 4, 3, 7, 1, 9, 8, 4, 3, 5 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	//int a[] = {11,9, 4, 3, 7, 1, 9, 8, 4, 3, 5, 0, 1, 3};
	int a[] = { 10,9,8,7,6,5,4,3,2,1,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11};

	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	//int a[] = { 9, 3, 7, 1, 0, 8, 4, 3, 5 };
	//int a[] = {11,9, 4, 3, 7, 1, 9, 8, 4, 3, 5, 0, 1, 3};
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 };

	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = {11,9, 4, 3, 7, 1, 9, 8, 4, 3, 5, 0, 1, 3};
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 };

	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
	int a[] = { 11, 9, 4, 3, 7, 1, 9, 8, 4, 3, 5, 0, 1, 3 };
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 };

	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	int a[] = {9,8,7,6,5,4,3,2,1,0 };
	//int a[] = { 11, 9, 4, 3, 7, 1, 9, 8, 4, 3, 5, 0, 1, 3 };
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 };

	QuickSortNonR(a, 0, sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestMergeSort()
{
	//int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	//int a[] = { 11, 9, 4, 3, 7, 1, 9, 8, 4, 3, 5, 0, 1, 3 };
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 };
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2, 5, 6, 5};

	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestCountSort()
{
	//int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	//int a[] = { 11, 9, 4, 3, 7, 1, 9, 8, 4, 3, 5, 0, 1, 3 };
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 };
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2, 5, 6, 5,7,3,3,3,4,2,5};

	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


void TestOP()
{
	srand(time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];

	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	//ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSortNonR(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int fn(int n)
{
	return n < 2 ? n : fn(n - 1) + n;
}

int main()
{
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestMergeSort();
	TestCountSort();

	//TestOP();
	//printf("%d", fn(1000000));

	return 0;
}