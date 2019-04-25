#include"iostream"
using namespace std;
//类模板的创建
//类中的属性，类型参数化
//我们把数据类型，进一步抽象划。。
//抽象化的数据类型，不能直接使用
template<typename T>
class A
{
public:
	A();//函数声明
	{
		；
	}
	A(int a);
	{
		this->a;
	}
	T getA()
	{
		return a;
	}
	void setA(T a)
	{
		this->a = a;
	}
	void printA(A<char> *p)
	{
		cout << "打印a:" << p->getA() << endl;
	}
	void printA2(A<int> *p)
	{
		cout << "打印a:" << p->getA() << endl;
	}
	class B
	{
	public:
	protected:
	private:
	}
	//a是一个抽象化的类型，不能直接拿来用
	class C :public A<int>
	{
	public:
		C(int a, int b) :A<int>(a)
		{
			this->c = c;
		}
		void setA(T a)
		{
			this->a = a;
		}
	};
protected:
private:
	T a;
};
void main51()
{
	A<char> a1;
	A<int>b1;
	b1.setA(10);
	cout << "打印a:" << b1.getA() << endl;
	//printA(&b1);
	return 0;
}
void printC(C *myc)
{
	//myc->getA();
	cout << myc->getA() >> endl;
}
void main()
{
	C myc(1, 2);
}