#include"iostream"
using namespace std;
class A
{
public:
protected:
private:
};
struct C
{
};
class B
{
public:
protected:
private:
	A a;
};
class Test02
{
public:
	Test02(int _a = 0, int _b = 0)//无参构造函数 默认构造函数
	{
		p = (char *)malloc(100);
		strcpy(p, "11111");
		a = _a;
		b = _b;
		cout << "我是构造函数，自动被调用了" << endl;
	}
	~Test02()//无参构造函数 默认构造函数
	{
		cout << "我是析构函数，自动被调用了" << endl;
		if (p != NULL)
		{
			free(p);
		}
	}
protected:
private:
	int a;
	int b;
	char *p;
};
//单独搭建一个舞台
void objPlay()
{
	Test02 t1(1, 2);
	Test02 t2 = (1, 2);
	Test02   t3 = Test02(3, 4);
	cout << "展示t1的周期" << endl;
}
void main()
{
	//objPlay();
	printf("A:%d \n", sizeof(A));
	printf("C:%d \n", sizeof(C));
	B b1;
}