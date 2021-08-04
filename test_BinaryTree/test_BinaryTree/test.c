#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTree
{
	struct BinaryTree* left;
	struct BinaryTree* right;
	BTDataType data;
}BTNode;

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
}

//遍历计数方式
//void TreeSize(BTNode* root,int* psize)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	(*psize)++;
//	TreeSize(root->left,psize);
//	TreeSize(root->right, psize);
//
//}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//k>0 第k层有几个节点
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}

//查找树里值为x的那个节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	//自己不是
	if (root->data == x)
	{
		return root;
	}
	//左边找
	BTNode* lret= TreeFind(root->left, x);
	if (lret)
	{
		return lret;
	}
	//右边找
	BTNode* rret = TreeFind(root->right, x);
	if (rret)
	{
		return rret;
	}
	//左右都没找到
	return NULL;
}

//销毁
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

//判断一棵树 是不是完全二叉树
//完全二叉树 层序遍历走 节点是连续的
//如果后面全是空 就是完全二叉树 不全是空 就不是

int main()
{

	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D = CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');

	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;

	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	
	printf("TreeSize:%d\n", TreeSize(A));
	printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	printf("TreeLeafSize:%d\n", TreeKLevelSize(A,3));
	printf("TreeLeafSize:%p\n", TreeFind(A,'E'));

	return 0;
}