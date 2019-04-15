#include<iostream>
using namespace std;
class Point
{
public:
	int p_x;//点的横坐标
	int p_y;//点的纵坐标

	int getX(int p_x)
	{
		cin >> p_x;
		return  p_x;
	}
	int getY(int p_y)
	{
		cin >> p_y;
		return p_y;
	}

};
Point p1;
Point p2;
int Calculate()//计算两点的距离
{
	float distance;
	distance = sqrt((p1.getX(p_x) - p2.getX(p_x)) ^ 2 + (p2.getY(p_y) - p2.getY(p_y) ^ 2);//
	return distance;
	//完全独立写，还是很不熟练。得更加独立写。明天继续
}
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
	cout << "输入横坐标：" << endl;
	p1.getX();
	cout << "输入纵坐标：" << endl;
	p1.getY();
	cout << "两点的距离为：" << Calculate() << endl;
}