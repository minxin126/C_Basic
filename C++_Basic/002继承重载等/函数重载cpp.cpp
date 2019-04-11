#include<iostream>
using namespace std;
class printData
{
public:
	void print(int i)
	{
		cout << "整数为：" << i << endl;
	}
	void print(double f)
	{
		cout << "浮点数为：" << f << endl;
	}
	void print(char c[])
	{
		cout << "字符串为：" << c << endl;
	}
};
int main(void)
{
	printData pd;
	//输出整数
	pd.print(5);
	//输出浮点数
	pd.print(5.1234);
	//输出字符串
	char c[] = "i love coding";
	pd.print(c);
	return 0;
	//自动选择函数，函数重载
}