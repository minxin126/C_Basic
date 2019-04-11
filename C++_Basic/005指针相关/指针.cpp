#include<iostream>
using namespace std;
int main()
{
	int var = 20;  //实际变量的声明
	int *ip;       //指针变量的声明，指明它为指针变量
	ip = &var;    //在指针变量中存储var的地址
	cout << "Value of var variable:";
	cout << var << endl;
	//输出在指针变量中存储的地址
	cout << "Address stored in ip variable:ox";
	cout << ip << endl;

	//访问指针中地址的值
	cout << "Value of *ip variable:";
	cout << *ip << endl;  //*x,相当于取x这个内存地址中的数据变量
	return 0;
}
//使用指针变量前先声明其为指针变量*p
//然后对p赋值
//*p则是取p这个内存地址中的数据