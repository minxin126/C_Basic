#include<iostream>
using namespace std;
tmplate<class T>
class Complex
{
public:
	Complex(T Real = 0, T Image = 0);
	Complex(T a);
	friend Complex operator+(Complex &c1, Complex &c2);
	friend Complex operator+(Complex &c1, Complex &c2);

	{
		Complex tmp(c1.Real - c2.Real, c1.Image - c2.Image);
		return tmp;
	}
	void print();
public:
	Complex operator-(Complex &c2);
	{
		Complex tmp(this->c2.Real£¬this->Image - c2.Image);
		return tmp;
	}

protected:
private:
	T Real, Image;
};

template<class T>
Complex<T>::Complex(T Real = 0, T Image = 0)
{
	this->Real = Real;
	this->Image = Image;
}
template<class T>
Complex<T>::Complex(T a)
{
	this->Real = Real;
	this->Image = Image;
}
template<class T>
void Complex<T>::print()
{
	cout << this->Real << "+" << this->Image << endl;
}
Complex Complex<T>::operator+(Complex<T> &c1, Complex<T> &c2);
{
	Complex<T> tmp(c1.Real + c2.Real, c1.Image + c2.Image);
	return tmp;
}

void main()
{
	Complex<float> c1(1.0, 2.0);
	Complex<float > c2(3.0, 4.0);
	c1.print();

	Complex<float> c3 = c1 + c2;
	Complex<float>c4 = c1 - c2;
	c4.print();
	operator+(Complex &)
}