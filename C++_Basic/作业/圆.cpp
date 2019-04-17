/*************************************
author:min
time:2019-4-16
**************************************/
#include<iostream>
using namespace std;
//点类
class Point
{
public:
	void setCenter(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	//计算和另外一个点之欧几里得距离的方法
	double getDistance(Point &another)  //函数参数只是给函数内部使用，使用对象.x时候一般在对象前面取&
	{//Point表示应该是放入一个点，然后&Point
		int d_x = m_x - another.m_x;
		int d_y = m_y - another.m_y;
		double distance = sqrt(d_x*d_x + d_y * d_y);

		return distance;
	}
private:
	int m_x;
	int m_y;
};
class  Circle
{
public:
	Point p3;//圆心坐标
	Point p4;//圆心坐标
	//有点的属性和方法

	int c_r;//半径
	//通过引入点的属性
	int setCircleCenter()
	{
	}
	int  setR(int r)
	{
		c_r = r;
		return c_r;
	}
	int getDoubleR(Circle &another)
	{
		int sumR;
		sumR = c_r + another.c_r;
		return sumR;
	}
	//明天继续
};

int main()
{
	Point p1;
	Point p2;
	Point p4;
	//通过设置固定点的值，或者手动输入点的数值
	int x = 0, y = 0;

	cout << "输入第一个点的坐标：" << endl;
	cin >> x >> y;
	p1.setCenter(x, y);//分别返回p1的m_x和m_y

	cout << "输入第二个点的坐标：" << endl;
	cin >> x >> y;
	p2.setCenter(x, y);//分别返回p2m_x和m_y

	p1.getDistance(p2);//返回计算的距离的结果

	cout << "两点的距离为：" << p1.getDistance(p2) << endl;;
	Circle c1;
	Circle c2;

	int r1 = 0;
	int r2 = 0;
	cout << "输入第一个圆的半径:" << endl;
	cin >> r1;
	c1.setR(r1);

	cout << "输入第二个圆的半径:" << endl;
	cin >> r2;
	c1.setR(r2);

	int c_distance = 0;
	c_distance = c1.p3.getDistance(p4);
	if (c_distance > c1.getDoubleR(c2))
	{
		cout << "两个圆相离" << endl;
	}
	else if (c_distance < c1.getDoubleR(c2))
	{
		cout << "两个圆相交" << endl;
	}
}
//过程：我看了一晚上也不知道	double getDistance(Point &another)怎么调用传递参数
//我一直尝试	p1.getDistance(Point &p2);始终报错，最后是抄网上的程序，发现（Point &another)直接
//	p1.getDistance(p2);就可以调用，对于这种带指针参数的函数，我根本不知道如何调用。我还是需要自己多独立搞，独立
//循序渐进搞。还是多做搜索。总之独立，按自己的节奏循序渐进。跨度大容易卡久。