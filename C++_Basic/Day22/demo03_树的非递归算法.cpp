#include "iostream"
#include "stack"
using namespace std;
//二叉链表
typedef struct BiNode
{
	int data;
	struct BiNode  *lchild, *rchild;
}BiNode, *BiTree;

BiNode *GoFarLeft(BiNode *T, stack<BiNode *> &s)
{
	if (T == NULL)
	{
		return NULL;
	}
	while (T->lchild)
	{
		s.push(T);
		T = T->lchild;
	}
	return T;
}
void InOrder2(BiNode *T)
{
	stack<BiNode *> s;
	//步骤1：一直往左走，找到中序遍历的起点
	BiTree t = GoFarLeft(T, s);
	while (t)
	{
		printf("%d ", t->data); //中序遍历打印

		//如果t节点有右子树，那么重复步骤1
		if (t->rchild != NULL)
		{
			t = GoFarLeft(t->rchild, s);
		}
		//如果t没有右子树，根据栈顶指示，访问栈顶元素
		else if (!s.empty())
		{
			t = s.top();
			s.pop();
		}
		//如果t没有右子树，并且栈为空
		else
		{
			t = NULL;
		}
	}
}
void main()
{
	BiNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BiNode));
	memset(&t2, 0, sizeof(BiNode));
	memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
	memset(&t5, 0, sizeof(BiNode));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	InOrder2(&t1);

	system("pause");
}