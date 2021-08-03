#include"heap.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//建堆 大堆
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
//向上调整
void AdjustUp(int* a,  int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//初始化
void HeapInit(HP* php, HPDataType* a, int n)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	memcpy(php->a, a, sizeof(HPDataType) * n);
	php->size = n;
	php->capacity = n;
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->a, php->size, i);
	}
}
//销毁
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}
//入数据
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	//满了需要增容
	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, php->capacity * 2 * sizeof(HPDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	php->size++;
	//向上调整 沿着插入节点到根的路径
	AdjustUp(php->a, php->size-1);
}
//删数据
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[php->size - 1], &php->a[0]);//将堆顶数据换到最后
	//删掉这个数据
	php->size--;
	
	AdjustDown(php->a, php->size, 0);
}
//返回堆顶数据
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}
//返回堆的数据个数
int HeapSize(HP* php)
{
	assert(php);
	
	
	return php->size;
}
//判断堆是否为空
bool HeapEmpty(HP* php)
{
	assert(php);
	
	return php->size == 0;
}
//打印
void HeapPrint(HP* php)
{
	//for (int i = 0; i < php->size; i++)
	//{
	//	printf("%d ", php->a[i]);
	//}
	//printf("\n");
	int num = 0;
	int levelSize = 1;
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
		num++;
		if (num == levelSize)
		{
			printf("\n");
			levelSize *= 2;
			num = 0;
		}
	}
	printf("\n\n");
}