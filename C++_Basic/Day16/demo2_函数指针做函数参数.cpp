//#include"string.h"
#include"string.h"
#include"stdio.h"
#include"stdlib.h"
int add(int a, int b)
{
	int c;
	c = a + b;
	return c;
}
//写任务的人和执行任务的人分开了
int MyOP(int(*MyAdd)(int, int))
{
	add(1, 2);
	MyAdd(3, 4);
	return 0;
}
//1不光是函数入口地址给被调用函数。。
//2同时函数类型，是做了接口的约定。。。（任务类型的约定）
//放映到代码上。。函数三要素（参数，返回值）
//指针做参数核心思想 吧
typedef int(*PMyFuncType)(int, int);
int MyOP2(PMyFuncType)
void main()
{
	int(*pAdd)(int, int);
	pAdd = add;

	MyOP2();
}