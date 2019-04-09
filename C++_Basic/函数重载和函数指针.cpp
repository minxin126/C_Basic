#include<iostream>
using namespace std;
int func(int x)//int (int a)
{
	return x;
}
int func(int a,int b)  //int (int a)这个地方应该是方法重载
{
	return a+b;
}
int func(const char* s)  //int (int a)这个地方应该是方法重载
{
	return strlen(s);
}
//定义一个数组类型0
typedef int MYTYPEAarry[10];//定义一个结构体数组
MYTYPEAarry a1;//int a[10]

//定义一个数组类型指针类型
typedef int(*MYArrayP)[10];

MYArrayP myarray = NULL;
//myarray=&a1;

int(*myP[10]);//告诉编译器给我分配4个字节的内存。。。。
//我要做一个指针变量 这个变量指向一个数组。。

//定义一个类型，函数类型。。
//这个函数是 int aaa(int a)
typedef int(*PFUNC)(int a);//int(int a)
typedef int(*PFUNC2)(const char *p);//int(int a)

int main(int argc, char *argv[])
{
	int c = 0;
	//func是一个函数名，函数名代表函数的入口地址，函数名就是函数指针变量
	{
		PFUNC p = func;
		c = p(1);
	}
	//c=p("ddddd");
	printf("c=%d\n", c);
	{
		PFUNC2 myp2 = func;
		myp2("aaaa");
	}
	printf("press enter to continue...");
	getchar();
	return 0;
}


