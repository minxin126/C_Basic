#include"iostream"
using namespace std;
struct  Teacher
{
	char name[64];
	int age;
};
int getTe(struct Teacher **myp)//结构体作为二级指针myp
{
	Teacher *p = (Teacher *)malloc(sizeof(Teacher));//p为指针变量
	if (p=NULL)
	{
		return -1;
	}
	memset(p, 0, sizeof(Teacher));//全部设置为0
	p->age = 33;//age
	*myp = p; 
	return 0;

}
//指针的引用而已
int getTe2(Teacher* &myp) //相当于一个二级指针
{
	myp = (Teacher *)malloc(sizeof(Teacher));
	myp->age = 34;

	return 0;
}

void main1()
{
	Teacher *p = NULL;
	//getTe(&p);
	getTe2(p);
	printf("age:%d \n", p->age);
}