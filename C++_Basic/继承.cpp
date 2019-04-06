#include<iostream>
using namespace std;
//基类
class Shape
{
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
protected:
	int width;
	int height;
};
//派生类
class Rectangle :public Shape  //声明为Shape的派生类
{
public:                        //继承了对应的方法
	int getArea()
	{
		return(width*height);
	}
};

//派生类
class Sum :public Shape  //声明为Shape的派生类
{
public:                        //继承了对应的方法
	int getSum()
	{
		return(width+height);
	}
};

int main1(void)
{
	Rectangle Rect;          
	Rect.setWidth(5);  //Rect可以使用父类的方法
	Rect.setHeight(7);

	Sum S;
	S.setWidth(4);  //Rect可以使用父类的方法
	S.setHeight(3);
	//输出对象的面积
	cout << "Total area:" << Rect.getArea() << endl;

	//输出对象的和
	cout << "Total sum:" << S.getSum() << endl;
	return 0;
}
