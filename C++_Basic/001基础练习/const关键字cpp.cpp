#include<iostream>
using namespace std;
struct Teacher
{
	char name[32];
	int age;
};
void printTe(const Teacher *p)
{
	//const修饰指针内存空间不能被修改
	//p->age = 10;
}
void printTe2(Teacher * const p)
{
	//const修饰指针p变量不能被修改
	//p=null; //err
}