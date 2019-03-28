/**************************************************************
author:minx
function:calculate area
time:2019-3-29
**************************************************************/
#include<iostream>
using namespace std;
//所有变量在初始化的时候必须初始化，否则会随机给一个数值。
double m_r=0;   //半径,成员变量
double m_s=0;  //面积，成员变量
double pi = 3.14159265458;
typedef  struct //结构体里面可以封装对应的方法
{
	double getarea()     
	{
		m_s = pi * m_r*m_r;
		return m_s;        //返回对应的面积数值
	}
}function;
int main()
{

	function fc;   //类型定义变量，只会分配内存
	cout << "请输入圆的半径：" << endl;
	cin >> m_r;  //输入半径数值
	double area = 0;
	//area = fc.getarea;
	cout << "圆的面积为：" << fc.getarea() << endl;
}