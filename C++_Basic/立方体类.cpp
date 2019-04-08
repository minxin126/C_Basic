#include<iostream>
using namespace std;
int flag = 0;//判断标志位
//目标：设计立方体,求出立方体的面积和体积
class Cube
{
public:
	int getA()
	{
		return m_a; 
	}
	int getB()
	{
		return m_b;
	}
	int getC()
	{
		return m_b;
	}
	void setABC(int a = 0, int b = 0, int c = 0)
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}
	//
	void setA(int a)
	{
		m_a = a;
	}
	void setB(int b)
	{
		m_b = b;
	}
	void setC(int c)
	{
		m_c = c;
	}
public:
	int getV()
	{
		m_v = m_a * m_b*m_c;
		return m_v;
	}
	int getS()
	{
		m_s = 2*(m_a * m_b+ m_b *m_c+ m_a * m_c);
		return m_s;
	}
protected:
private:
	int m_a;
	int m_b;
	int m_c;
	int m_v;
	int m_s;
};
struct Teacher
{
	char name[32];
	int age;
};
//c++对象管理模型
//1相等，0不相等
int judgeCube(Cube &c1, Cube &c2)
{
	int s1 = 0, s2 = 0;
	
	s1 = c1.getS();
	s2 = c2.getS();
	if (s1==s2)
	{
		return flag=1;
	}
	else
	{
		return flag = 0;
	}
	
}
int judgeCube(Cube *pc1, Cube *pc2)
{
	return 1;
}
void main101()
{
	Teacher t1;
	Cube c1;
	c1.setA(1);
	c1.setB(2);
	c1.setC(3);

	cout << "s是："<<c1.getS();
	Cube c2;
	c2.setABC(1, 2, 3);//默认参数
	cout << "s是：" << c2.getS();

}

void main()
{
	Cube c1,c2;
	c1.setABC(1, 2, 3);
	c2.setABC(1, 2, 3);

	//judgeCube(&c1, &c2);
	judgeCube(c1,c2);
	if (flag==1)
	{
		cout << "两个立方体面积相同" << endl;
	}
	if (flag == 0)
	{
		cout << "两个立方体面积不相同" << endl;
	}
}
