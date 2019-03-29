#include <iostream>
using namespace std;
#include <iomanip>
using std::setw;
int main()
{
	int data[10]; //n是一个包含10个数组的数组
	//初始化数组元素
	for (int i = 0; i < 10; i++)
	{
		data[i] = i + 100; //设置元素i为i+100
	}
	cout << "Element" << setw(13) << "Value" << endl;
	//输出数组中每个元素的值
	for (int j = 0; j < 10; j++)
	{
		cout << setw(7) << j << setw(13) << data[j] << endl;
	}
	return 0;
}