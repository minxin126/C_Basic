#include<iostream>
using namespace std;
//圆的例子
//类是把属性和方法封装
//类的内部
//类的外部
//我们抽象了一个类，用类取定义对象
//类是一个数据类型，类是抽象的
//对象是一个具体的变量，占用具体内存空间
class Circle
{
public: 
	double r;
	double s;
public:
	double getR()
	{
		return r;
	}
	 void setR(double val)
	 {
		 r = val; 
	 }
public :
	double getS() //我增加功能的时候，是在修改类，修改类中的函数属性或者方法
	{
		s = 3.14f*r*r;
		return s; 
	}
private:
	int a;

};
 
  
void main1()
{
	cout << "请输入圆的半径";
	double r;
	cin >> r;
	double s = 3.14f*r*r;
	cout << "圆的面积" << s << endl;

}  
//面向过程编程加工的是：函数
//面向对象编程加工的是：类， 
void main11()
{
	//通过类定义变量（对象）
	Circle c1, c2;
	//c1.a = 10;
	//给对象的属性赋值
	c1.setR(10);
	cout << "圆的面积是：" << c1.getS() << endl;

	//给对象的属性赋值
	c2.setR(12);
	cout << "圆的面积是：" << c2.getS() << endl;
	//抛砖：C++编译器如何指导是c1、c2调用了getS()函数那？
	//抛砖：C中学习的内存四区概念如何在C++中能够用吗？如何用啊？


}