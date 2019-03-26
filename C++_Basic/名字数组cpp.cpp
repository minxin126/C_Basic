#include<iostream>
using namespace std;
int main()
{
	typedef struct A_Linux_Window
	{
		char wang;
		char min;
		char xin;
		string fang;
		string bian;
		string guo;
	}namerecord;
	namerecord namedouble;
	namedouble = { 0 };
	namedouble.wang = 'wang';
	namedouble.min = 'min';
	namedouble.xin = 'xin';
	namedouble.fang = "fang";
	namedouble.bian = "bian";
	namedouble.guo = "guoguo";
	cout << "wang=%c"<<namedouble.wang << endl;
	cout << "min=%c,namedouble.min" << endl;
	cout << "xin=%c,namedouble.xin" << endl;
	cout << "fang=%s,namedouble.fang" << endl;
	cout << "bian=%s,namedouble.bian" << endl;
	cout << "guo=%s,namedouble.guo" << endl;
}