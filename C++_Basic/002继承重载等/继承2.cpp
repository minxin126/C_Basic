#include<iostream>
using namespace std;
//基类
class Shape//用于返回（）里面的具体的数值，是设置函数的作用
{
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeigth(int h)
	{
		height = h;
	}
protected:
	int width;
	int height;
};//没写完，之后继续完成
//派生类
class Rectangle :public Shape
{
public:
	int getArea()
	{
		return (width *height);
	}
	int getLong()
	{
		return 2 * (width + height);
	}
};
class Triangle :public Shape  //等腰三角形类
{
public:
	int getArea()
	{
		return (width*height) / 2;
	}
	int getLong() //计算等腰三角形的周长
	{
		float slideDistance = 0;
		slideDistance = sqrt((width / 2)* (width / 2) + height * height); //斜边长计算的简单的算法
		return (2 * slideDistance + width);//周长的计算的简单的算法
	}
};
int main(void)
{
	Rectangle Rect;
	Triangle Tria;

	Rect.setWidth(5);//直接设置对应的数值大小
	Rect.setHeigth(7);//直接设置对应的数值大小

	Tria.setHeigth(3);//直接设置对应的数值大小
	Tria.setWidth(8);//直接设置对应的数值大小

	//输出矩形的面积
	cout << "Total area:" << Rect.getArea() << endl;//调用计算函数，输出结果。
	cout << "Total Long:" << Rect.getLong() << endl;//调用计算函数，输出结果。

	//输出三角形的面积
	cout << "Total area:" << Tria.getArea() << endl;//调用计算函数，输出结果。
	cout << "Total Long:" << Tria.getLong() << endl;//调用计算函数，输出结果。
	return 0;
}