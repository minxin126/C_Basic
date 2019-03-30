#include<iostream>
using namespace std;//c++的命名空间
class circle
{
public:

	double r;

	double pi = 3.1415926;
	double area = pi*r*r;

};
int main()
{
	circle pi;
	cout << "请输入area" << endl;
	cin >> pi.r;

	cout << pi.area << endl;	//乱码

	system("pause");
	return 0;


}