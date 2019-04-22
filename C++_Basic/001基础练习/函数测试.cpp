#include<iostream>
using namespace std;
int HeartBeat = 0;
int *p;
void  Calculate()
{
	HeartBeat++;
	p = &HeartBeat;
	cout << "心跳数目为：" << HeartBeat << endl;
}
int main()
{
	for (int i = 0; i < 100; i++)
	{
		Calculate();
	}
}
//录制视频备选项
//1：首先录制一个视频，讲解TREACE使用，结合心跳变量来使用。
//2：使用一个例子讲解对象使用方法。
//3：指针变量需要取一个地址。