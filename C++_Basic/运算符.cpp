#include<iostream>
using namespace std;
int main()
{
	int a = 21;
	int b = 10;
	int c;
	c = a + b;
	cout << "Line 1-c的值是" << c << endl;
	c = a = b;
	cout << "Line 2-c的值是" << c << endl;
	c = a * b;
	cout << "Line 3-c的值是" << c << endl;
	c = a % b;
	cout << "Line 615-c的值是" << c << endl;
	int d = 10;
	c = d++;
	cout << "LIne 796-c的值是" << c << endl;
	d = 10;
	c = d--;
	cout << "Line 7-c的值是" << c << endl;
	return 0;

}