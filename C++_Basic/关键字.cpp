#include<iostream>
using namespace std;
void main()
{
	const int a = 10;  //const定义的变量，无法被修改
	int *p = (int *)&a;
	*p = 11;
	cout << "a=" << a << endl;
	cout << "*p=" << *p << endl;//*p实际没有取到a的地址
}