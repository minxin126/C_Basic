#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"algorithm"
#include"set"
#include "functional"

template <typename T>
class funcE {
public:
	//函数对象是回调函数的理念
	void operator()(T& t) {
		++num;//用来记录调用了几次
		cout << t << endl;
	}
	void getN() {
		cout << "num:" << num << endl;
	}
private:
	int num = 0;;
};

template <typename T>
void funcEt(T& t) {
	cout << t << endl;
}

void funcEt(string& t) {
	cout << t << endl;
}

//函数对象定义； 函数对象与普通函数的异同。
void main01() {
	funcE <string> fe; //fe称为函数对象
	string name = "goku";
	fe(name);//函数对象()的执行，很像一个函数 //也称为仿函数

	funcEt<string>(name);//函数对象和函数调用非常相似
	funcEt(name);
}

void funcEt2(int& t) {
	cout << "我是回调函数" << endl;
	cout << t << endl;
}
//函数对象是属于类对象，能突破函数的概念，能保持状态调用信息
//函数对象的好处
//for_each算法中，函数对象作函数参数
//for_each算法中，函数对象作返回值
void main02() {
	vector <int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(4);

	//funcE<int>fe;
	for_each(v1.begin(), v1.end(), funcE<int>());//for_each()函数，需要三个参数，首部指针和尾部指针，加上一个函数
							   //通过匿名函数对象
	//fe = for_each(v1.begin(),v1.end(),fe);

	for_each(v1.begin(), v1.end(), funcEt2);//通过回调函数(函数指针) 谁使用for_each 谁去填写回调函数的入口地址
								 //回调函数地址
	//for_each函数的作用：给出首尾地址，再给出一个函数地址，让这个函数从首位遍历元素

	//要点：分清楚stl算法返回的值是迭代器还是谓词(函数对象)，是stl算法入门的重要点
	funcE<int> f;
	//_Fn for_each(_InIt _First, _InIt _Last, _Fn _Func)
	f = for_each(v1.begin(), v1.end(), f);
	//inline_Fn for_each(_InIt _First, _InIt _Last, _Fn _Func){  }return (_Func);
	f.getN();//为什么这里的n就可以返回出结果？？？？？？   _Fn _Func  是个函数对象  _InIt _First  是个指针
}
static int n = 0;
template<typename T3>
class isdiv {
public:

	isdiv(T3 num) {
		this->num = num;
	}
	bool operator()(T3& t) {//t是被除数  是vector容器中的值
		++n;
		cout << "调用第" << n << "次" << endl;
		return (t % num == 0);
	}
	void getN() {
		cout << "回调函数执行：" << n << "次" << endl;
	}
private:
	int num;//作为除数
};
void main03() {
	vector<int> v3;
	for (int i = 10; i < 21; i++) {
		v3.push_back(i);
	}

	isdiv<int> div3(4);//传进去一个除数4

	vector<int>::iterator it;
	it = find_if(v3.begin(), v3.end(), div3);
	//_NODISCARD inline _InIt find_if(_InIt _First, const _InIt _Last, _Pr _Pred){  } return (_First);
	if (it == v3.end()) {                   //指针               指针       指针
		cout << "容器中没有能整除4的元素" << endl;
	}
	else {
		cout << "第一个元素是" << *it << endl;
	}
	div3.getN();//为什么这里的n返回不出结果？？？？？？
}

template <typename T>
class trans {
public:
	T operator()(T t1, T t2) {
		return t1 + t2;
	}
};

//v1 + v2 --> v3
void main04() {
	vector<int> v1, v2, v3;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);

	v3.resize(10);//给v3设置大小的函数
	//直接写匿名对象，不用声明
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), trans<int>());
	//transform(const _InIt1 _First1, const _InIt1 _Last1,const _InIt2 _First2,_OutIt _Dest ,_Fn _Func)
   //类型 _OutIt      _InIt                 _InIt         _InIt                _OutIt        _Fn
	  //transform 函数的返回值类型是 （_OutIt： 输出It）It是迭代器的意思！！！！！！ 也就是指针类型
	  //InIt的意思就是输入迭代器  OutIt的意思就是输出迭代器  所以返回值都是指针类型！！！！！！
	  //把运算结果的迭代器位置返回出来
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {
		cout << *it << "\t";
	}
}

bool mysort(int a, int b) {
	return a < b;//a<b 从小到大
}

void main05() {
	vector<int> v5(10);
	for (int i = 0; i < 10; i++) {
		int tmp = rand() % 100;
		v5[i] = tmp;
	}

	for (vector<int>::iterator it5 = v5.begin(); it5 != v5.end(); it5++) {
		cout << *it5 << "  ";
	}
	cout << endl;

	sort(v5.begin(), v5.end(), mysort);
	//void sort(const _RanIt _First, const _RanIt _Last, _Pr _Pred)
													  // 回调函数类型
	for (vector<int>::iterator it5 = v5.begin(); it5 != v5.end(); it5++) {
		cout << *it5 << "  ";
	}
	cout << endl;
}

void printF(const string& t) {
	cout << t << "  ";
}

const struct  rocket {
public:
	bool operator()(const string& t1, const string& t2) {
		string tm1;
		tm1.resize(t1.size());
		transform(t1.begin(), t1.end(), tm1.begin(), tolower);//tolower:预定义函数对象 已经在库中写好了

		string tm2;
		tm2.resize(t2.size());
		transform(t2.begin(), t2.end(), tm2.begin(), tolower);//tolower:预定义函数对象 已经在库中写好了

		return (tm1 < tm2);
	}
};

void main06() {
	//set<string> set1;
	//set1.insert("ccc");
	//set1.insert("bbb");
	//set1.insert("aaa");
	////for_each(set1.begin(), set1.end(), printF);
	//set<string>::iterator it6 = set1.find("aAa"); //set的find()函数如果找到了会返回一个该类型的迭代器
	////set<string>::iterator it6 = set1.find("aAa");  find()函数默认区分大小写
	//if (it6 == set1.end()) {
	//	cout << "查找失败" << endl;
	//}
	//else {
	//	cout << "查找成功" << *it6 << endl;
	//}
	////要变成不区分大小写的

	set <string, const rocket>  set2;
	//set<string> set2;

	set2.insert("zzz");
	set2.insert("xxx");
	set2.insert("ccc");

	set<string, const rocket>::iterator itop = set2.find("aAa");
	set<string>::iterator it66 = set2.find("aAa");
	if (itop == set2.end()) {
		cout << "查找失败" << endl;
	}
	else {
		cout << "查找成功" << *itop << endl;
	}
}

int main() {
	//main01();//函数对象的基本概念
	//main02();//函数对象的好处 函数对象做函数参数 函数对象做返回值  for_each()函数
	//main03();//一元函数对象，一元谓词                              find_if()函数
	//main04();//二元函数对象，二元谓词                              transform()函数
	//main05();                                                      sort()函数
	main06();//二元谓词在set中的应用
	system("pause");
	return 0;
}