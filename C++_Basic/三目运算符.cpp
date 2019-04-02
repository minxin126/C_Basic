#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	int b = 20;
	(a < b ? a : b)=30;  //C++中三目运算符可以作为左值，返回的是变量本身。
	cout << "a=" << a << endl;  //左值是有内存空间的，寄存器没有内存空间。
	cout << "b=" << b << endl;
}