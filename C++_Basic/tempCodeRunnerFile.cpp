/********************************************************
author:minx
function:calculate
version:v1.0
time:2010-3-29
*********************************************************/
#include <iostream>
using namespace std; //c++的命名空间
class circle		 //为一个类，也为一个结构体
{
  public:
	double r; //此时为一个随机数，也是一个乱码数值
	double pi = 3.1415926;
	double area = pi * r * r;
	double getS()
	{
		return area = 3.14 * r * r;
	}
};
int main()
{
	circle pi;
	cout << "请输入半径r:" << endl;
	cin >> pi.r; //输入半径
	pi.getS();   //输入半径后，重新计算得正确结果。
	cout << pi.area << endl;
	system("pause");
	return 0;
}