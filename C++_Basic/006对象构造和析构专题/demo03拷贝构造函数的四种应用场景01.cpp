#include"iostream"
using namespace std;

class AA
{
public:
	AA()//无参构造函数 默认构造函数
	{
		cout << "我是构造函数，自动被调用了" << endl;
	}
	AA(const AA &obj)
	{
		cout << "我也是构造函数，我是通过另外一个对象obj2，来初始化自己" << endl;
	}
	~AA()//无参构造函数 默认构造函数
	{
		cout << "我是析构函数，自动被调用了" << endl;
	}
protected:
private:
	int a;
};
//单独搭建一个舞台
void objPlay()
{
	AA a1;//变量定义
	//赋值构造函数的第一个应用场景
	//我用对象1 初始化 对象2
	AA a2 = a1;//定义变量并初始化
	a2 = a1;//用a1来=号给a2,编译器给我提供的浅copy
}
void main()
{
	objPlay();
	//printf("A:%d \n", sizeof(A));
	//printf("C:%d \n", sizeof(C));
	//B b1;
}