#include"string.h"
#include"stdio.h"
#include"stdlib.h"
void main1()
{
	//函数三要素：名称、参数、返回值\
	//如何定义一个数组指针类型
	//如何定义一个指向数组类型的一个指针变量
	// int aray[10]
	typedef int(MyAray)[10];
	MyAray myArray;
	myArray[0] = 1;
	{
		typedef int(*PMyArrayType)[10];
		PMyArrayType pmyArray;
		pmyArray = &pmyArray;

		(*pmyArray)[0] = 111;
		{
			int a = 10;
			int *p = NULL;
			p = &a;
		}
	}
	{
		int array3[10];
		int(*pM)[10];//定义了一个指针变量，告诉c编译器给我分配了四个字节的内存，这个指针变量指向一个数组
		//言外之意是：pM++会后裔一个数组单位。。。。（4*10）个字节

		pM = &array3;
		(*pM)[0] = 12;
		printf("%d \n", array3[0]);
	}
}
//定义函数类型
//如何定义一个指针类型
	//如何定义一个指向数组类型的一个指针变量
//test函数名，名代表首地址，名是指针
int test(int a)
{
	printf("a:%d", a);
	return 0;
}
void main()
{
	//定义一个函数类型。。。
	typedef int (myFunc)(int);
	MYFuncType *myfun;
	myfun = test;
	myfun(2);
}
{
	//对函数名字&地址，和不取地址，效果一样。。。。
	//历史遗留
	myfun = &test;
	myfun(3);
}
{
	//定义了函数指针类型
	typedef int(*PMYFuncType)(int);
	PMYFuncType pMyFuncType;

	ret pMyFuncType(1);
}
{
	int(*PmyFunc) (int);
	PmyFunc = test;
	PmyFunc(1);
}