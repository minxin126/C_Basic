#include<stdlib.h>
#include<stdio.h>
#include"string.h"
typedef struct Teacher
{
	char name[64];
	int age;
	char studentInfo[1024];//s1,s2,s3,
}Teacher;
//添加老师
int AddTeacher(char *pfileName, Teacher *pTe)
{
	//准备些配置文件的关键字 根据ID动态构建
	char Teacher_InfoID[128];
	char Teacher_Name[128];
	char Teacher_Age[128];
	char Teacher_StudentInfo[128];
	char infold[128];

	sprintf(Teacher_InfoID, "%s%d", Teacher_InfoID_, pTe->infoId);
	sprintf(Teacher_Name, "%s%d", Teacher_Name_, pTe->infoId);
	sprintf(Teacher_Age, "%s%d", Teacher_Age_, pTe->infoId);
	sprintf(StudentInfo, "%s%d", StudentInfo_, pTe->infoId);
	sprintf(infoId, "%s", pTe->infoId);
	return 0;
	WriteCfgItem(*pFileName /*in*/, char *pItemName /*in*/, char *pItemValue/*in*/, int itemValueLen /*in*/);
}
//显示老师
int modifyTeacher(char *pfileName, Teacher *pTe);
void main()
{
	//main函数在最下面
}