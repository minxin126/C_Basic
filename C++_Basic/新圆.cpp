#include <iostream>
#include <string>
using namespace std;

struct Point //点信息
{
	float x;
	float y;
};

struct Circle  //圆的信息
{
	Point center;
	float radii;

	float Area() { return 3.14f * radii * radii; }
	float Perimeter() { return 2.0f * 3.14f * radii; } //直径
};

struct Ring  //环的信息
{
	Circle external;
	Circle internal;

	float Area() { return external.Area() - internal.Area(); }  //环的面积
	float Perimeter() { return external.Perimeter() + internal.Perimeter(); } //直径
};

int main()





{
	Point p1 = { 0.0, 0.0 };
	Circle c1 = { p1, 2.4 };
	Circle c2 = { p1, 1.5 };
	Ring rg1 = { c1, c2 };

	cout << "x-coordinate = " << p1.x << "\n"
		<< "y-coordinate = " << p1.y << "\n"//点的坐标
		<< endl;

	cout << "big circle's center = "
		<< "(" << c1.center.x << "," << c1.center.y << ")"//大圆的圆心、半径、面积、周长
		<< "\n"
		<< "radii = "
		<< c1.radii
		<< "\n"
		<< "Perimeter = "
		<< c1.Perimeter()
		<< "\n"
		<< "Area = "
		<< c1.Area() << "\n\n"
		<< endl;

	cout << "small circle's center = "
		<< "(" << c2.center.x << "," << c2.center.y << ")" //小圆的圆心、直径、面积、周长
		<< "\n"
		<< "radii = "
		<< c2.radii
		<< "\n"
		<< "Perimeter = "
		<< c2.Perimeter()
		<< "\n"
		<< "Area = "
		<< c2.Area() << "\n\n"
		<< endl;

	cout << "Ring's center = "
		<< "(" << rg1.internal.center.x << "," << rg1.internal.center.y << ")"//环的中心、半径、周长、面积
		<< "\n"
		<< "big radii = "
		<< rg1.external.radii
		<< "\n"
		<< "small radii = "
		<< rg1.internal.radii
		<< "\n"
		<< "Perimeter = "
		<< rg1.Perimeter()
		<< "\n"
		<< "Area = "
		<< rg1.Area() << "\n\n"
		<< endl;

	return 0;
}