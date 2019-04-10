#include<iostream>
using namespace std;
class Box
{
public:
	double length;  //长度
	double breadth;//高度
	double height;//高度

};
int main()
{
	Box Box1;//声明Box1，类型为Box
	Box Box2;//声明Box2，类型为Box
	double volume = 0.0;//用于存储体积

	//Box1详述
	Box1.height = 5.0;
	Box1.length = 6.0;
	Box1.breadth = 7.0;

	//Box2详述
	Box2.height = 10.0;
	Box2.length = 12.0;
	Box2.breadth = 13.0;

	//Box1的体积
	volume = Box1.height*Box1.length*Box1.breadth;
	cout << "Box1的体积：" << volume << endl;

	//Box2的体积
	volume = Box2.height*Box2.length*Box2.breadth;
	cout << "Box2的体积：" << volume << endl;

	return 0;

}