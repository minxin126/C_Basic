#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "linkstack.h"
#include"D:\学习资料\04-C++语言-王保明\day20\linkstack设计与实现\linkstack设计与实现\linkstack设计与实现\linklist.h"
void main()
{
	int a[10], i;
	LinkStack *stack = NULL;

	stack = LinkStack_Create();

	for (i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		LinkStack_Push(stack, &a[i]);
	}
	printf("top: %d \n", *((int *)LinkStack_Top(stack)));
	printf("size: %d \n", LinkStack_Size(stack));

	//删除栈中所有元素
	while (LinkStack_Size(stack) > 0)
	{
		printf("linkstack pop: %d \n", *((int*)LinkStack_Pop(stack)));
	}
	LinkStack_Destroy(stack);

	system("pause");
}