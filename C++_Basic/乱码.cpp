#include <iostream>
using namespace std; //c++�������ռ�
class circle
{
  public:
	double r;

	double pi = 3.1415926;
<<<<<<< HEAD
	double area = pi*r*r;

=======
	double area = pi * r * r;
>>>>>>> 9758e77c854b79fc47d397c558c4f1811bf9d8e2
};
int main()
{
	circle pi;
	cout << "������area" << endl;
	cin >> pi.r;

	cout << pi.area << endl; //����

	system("pause");
	return 0;
}