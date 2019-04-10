#include<iostream>
using namespace std;
//static修饰变量的时候，变量是一个状态变量
//int j()
//{
//	static int a = 10;
//	a++;
//	printf("a:%d \n", a);
//	return a;
//
//}

int& j1()//引用类型，相当于返回一个地址变量，间接对a赋值
{
	static int a = 10;
	a++;
	printf("a:%d \n", a);
	return a;
}
int *j2()  //指针类型，则告诉它是一个地址
{
	static int a = 10;
	a++;
	cout << "a:" << a << endl;
	return &a;//返回a的地址的数值
	//下面的*（j2()）为去这个内存地址，进行赋值
}

int g1(int *p)
{
	*p = 100;
	return *p;
}

int& g2(int *p)
{
	*p = 100;
	return *p;
}

void main1()
{
	//j()的运算结果是一个数值，没有内存地址，不能当左值。
	//11=100；
	//*（a>b?&a:&b)=111;
	//当被调用的函数当左值的时候，必须返回一个引用
	j1() = 100;
	j1();
	*(j2()) = 200;//相当于我们程序员手工打造做左值的条件
	j2();
}
void main()
{
	int a1 = 10;
	a1 = g2(&a1);
	int &a2 = g2(&a1); //引用类型
	cout << "a1:" << a1 << endl;
	cout << "a2:" << a2 << endl;
}