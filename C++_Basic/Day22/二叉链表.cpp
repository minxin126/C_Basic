#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

typedef struct TreeNode
{
	struct TreeNode* lchild;//左子树
	struct TreeNode* rchild;//右子树
	char elem;//根结点
}TreeNode;//树结点

TreeNode* BinaryTree(char *preorder, char *inorder, int len)//二叉树，先序，中序，长度
{
	if (len <= 0)
		return NULL;
	TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));//分配内存
	root->elem = preorder[0];//根为先序的第一个点root.elem(因为root为指针所以->)
	int rootindex = -1;//初值
	for (int i = 0; i < len; i++)//
	{
		if (inorder[i] == preorder[0])//中序中的某个节点等于先序第一个，则这个是真的根节点
		{
			rootindex = i;
			break;
		}
	}
	//cout << root->elem << endl;
	//将长度传递给rootindex
	root->lchild = BinaryTree(preorder + 1, inorder, rootindex);//preorder为地址，所以地址加1，为数组的下一个元素。根据数组的头地址，然后可以一次探寻数组的元素。
	root->rchild = BinaryTree(preorder + rootindex + 1, inorder + rootindex + 1, len - rootindex - 1);//inorder为地址，所以地址加1，为数组的下一个元素。根据数组的头地址，然后可以一次探寻数组的元素。
	return root;//返回根
}

void Traversal(TreeNode *root)
{
	if (root != NULL)
	{
		Traversal(root->lchild);
		Traversal(root->rchild);
		cout << root->elem << endl;//显示树的过程
	}
}
int main()
{
	char inorder[100];//数组
	char preorder[100];//数组
	cout << "请输入先序序列：" << endl;
	cin >> preorder;
	cout << "请输入中序序列：" << endl;
	cin >> inorder;
	int len = strlen(preorder);//获取长度

	TreeNode * root = BinaryTree(preorder, inorder, len);//将整个树都给*root这个指针变量
	Traversal(root);//因为函数的参数为指针变量，所以直接传入变量则可以，通过这个函数打印所有的树节点。

	return 0;
}