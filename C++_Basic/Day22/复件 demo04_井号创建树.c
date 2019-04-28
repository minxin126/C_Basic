#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct BiTNode
{
	int data;//根节点
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//按给定的先序序列建立二叉链表
//输入值为12##3##
BiTNode* BiTree_Creat12()
{
	BiTNode *tmp = NULL;//BITNode成为指针变量*tmp,所以tmp是一个地址
	char ch;
	printf("\n请输入字符: ");
	scanf("%c", &ch);
	if (ch == '#')
	{
		return NULL;
	}
	else
	{
		tmp = (BiTNode *)malloc(sizeof(BiTNode));
		if (tmp == NULL)
		{
			return NULL;
		}
		tmp->data = ch; //生成根结点,所以tmp树的根节点
		tmp->lchild = BiTree_Creat12();//构建左子树
		tmp->rchild = BiTree_Creat12();//构建右子数
		return tmp;
	}
}

void preOrder(BiTNode *root)
{
	if (root != NULL)
	{
		printf("%c ", root->data);
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

//按给定的先序序列建立二叉链表
void  BiTree_Free(BiTNode* T)
{
	BiTNode *tmp = NULL;
	if (T != NULL)
	{
		if (T->rchild != NULL) BiTree_Free(T->rchild);
		if (T->lchild != NULL) BiTree_Free(T->lchild);
		if (T != NULL)
		{
			free(T);
			T = NULL;
		}
	}
}

void main()
{
	int nCount = 0, depthval = 0;
	BiTNode * my = BiTree_Creat12();
	printf("\n非递归算法c++访问\n");
	//InOrder(my);
	preOrder(my);

	BiTree_Free(my);
	printf("树释放完毕\n");

	printf("\n");
	system("pause");
}
//本程序不懂的地方：
//1首先为何tmp->data不是具体的的数据，而是打印出来才是具体的数
//为何会有49，50，51等数据