#include<iostream>
using namespace std;
class Point
{
public:
	int p_x;//点的横坐标
	int p_y;//点的纵坐标
	float distance;
	int getX()
	{
		cin >> p_x;
		return  p_x;
	}
	int getY()
	{
		cin >> p_y;
		return p_y;
	}
	int Calculate()
	{
		distance = sqrt(p_x*p_x + p_y * p_y);//错误，后期更改
		return distance;
	}

};
class  Circle
{
public:
	int c_x;//圆心
	int c_r;//半径
};
Point p1;
Point p2;

int main()
{
	cout << "输入横坐标：" <<endl;
	p1.getX();
	cout << "输入纵坐标："<<endl;
	p1.getY();
	cout << "两点的距离为：" << p1.Calculate() << endl;


}