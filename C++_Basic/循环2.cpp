#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
	string str("some string");
	// range for 语句
	for (auto &c : str)
	{
		c = toupper(c);
	}
	cout << str << endl;
	return 0;
}

// 上面的程序使用Range for语句遍历一个字符串，并将所有字符全部变为大写，然后输出结果为：

// SOME STRING