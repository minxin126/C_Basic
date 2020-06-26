#include<iostream>

using namespace std;

class A {
public:
    void foo() {
        printf("1\n");
    }

    virtual void fun() {
        printf("2\n");
    }
};

class B : public A {
public:
    void foo()  //隐藏：派生类的函数屏蔽了与其同名的基类函数
    {
        printf("3\n");
    }

    void fun()  //多态、覆盖
    {
        printf("4\n");
    }
};

int main1(void) {
    A a;
    B b;
    a.foo();
    a.fun();
    b.foo();
    b.fun();
    cout << "********************************" << endl;
    A *p = &a;
    cout << p << endl;
    p->foo();  //输出1
    p->fun();  //输出2
    p = &b;
    cout << p << endl;
    p->foo();  //取决于指针类型，输出1，其实还是父类的方法，只有虚函数才可以重写
    p->fun();  //取决于对象类型，输出4，体现了多态
//use pointer only virtual can use overwrite.other will keep the same.

    cout << "********************************" << endl;

    int i = 1, j = 5;
    int &k = i;
    k = j;        //语句[1]
    j = 10;
    cout << "i=" << i << "; j=" << j << "; k=" << k << endl;

    return 0;
}