#include<iostream>
#include<cstring>
using namespace std;
void printBook(struct Books *book);//需要声明函数，之后定义函数

//声明一个结构体类型Books
struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};
int main()
{
	Books Book1;
	Books Book2;

	////Book1详述
	strcpy(Book1.title, "C++ 教程");
	strcpy(Book1.author, "Runob");
	strcpy(Book1.subject, "编程语言");
	Book1.book_id = 12345;

	//Book2详述
	strcpy(Book2.title, "CSS 教程");
	strcpy(Book2.author, "Runob");
	strcpy(Book2.subject, "前端技术");
	Book2.book_id = 12346;

	//通过传Book1的地址来输出Book1信息
	printBook(&Book1);

	//通过传Book2的地址来输出Boo2信息
	printBook(&Book2);

	return 0;
}
void printBook(struct Books *book)
{
	cout << "书标题：" << book->title << endl;
	cout << "书作者：" << book->author << endl;
	cout << "书类目：" << book->subject << endl;
	cout << "书ID：" << book->book_id << endl;
}