#include<cstdlib>
#include<iostream>

using namespace std;
class Parent01
{
public:
	Parent01()
	{
		cout << "Parenet01:printf()..do" << endl;
	}
public:                   
	void func()
	{
		cout << "Parent01:void func()" << endl;
	}
	void abcd()
	{
		cout << "Parent01:void func()" << endl;
	}
	virtual void func(int i)
	{
		cout << "Parent:void func(int i)" << endl;
	}
	virtual void func(int i, int j)
	{
		cout << "Parent:void func(int i,int j)" << endl;
	}
};
//重写的两种情况
//如果函数重写，在父类中增加了virtual关键字，将能产生多态。。。
//如果函数重写，没有加virtual关键字，相当于在子类中重定义。。。不会发生多态。。。
class Child01 :public Parent01
{
public:
	//原因是发生了 名称覆盖，把子类中的没有函数参数的，这个函数abcd名称覆盖了。。。
	//在子类中，是不是重载父类的函数的。编译器就是这么做。顺从。。。。
	void abcd(int a, int b)
	{
		cout << "Parent01:void func()" << endl;
	}
	//此处2个参数，和子类func函数是什么关系
	void func(int i, int j)
	{
		cout << "Child:void func(int i,int j)" << "" << i + j << endl;
	}
	//此处3个参数的，和子类func函数是什么关系
	void func(int i, int j, int k)
	{
		cout << "Child:void func(int i,int j,int k)" << " " << i + j + k << endl;
	}
};
void run01(Parent01*p)
{
	p->func(1, 2);
}
int main()
{
	Parent01 p;
	p.func();
	p.func(1);
	p.func(1, 2);

	Child01 c;
	//c.Parent01::abcd();//这个函数是从父类中继承而来，可以使用。。。
	//子类和父类相同的名字（变量名字或者是函数名字的时，子类名字覆盖父类名字，如果想使用父类的资源，需要加：：）

	c.Parent01::func();//问题1 这个函数时从父类中继承而来，为什么这个地方不能使用
	//c.func();//问题1
	//c.func(1,2);
	/*
	run01(&p);
	run01(&c);
	*/
	return 0;
}