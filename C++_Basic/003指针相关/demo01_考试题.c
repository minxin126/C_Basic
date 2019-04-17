#include"stdio.h"
#include"stdlib.h"
#include"string.h"
int GetString_Adv(const char *str1, char **str2);
int GetString_Adv_Free1(char *str2);

int GetString(const char *str1, char *str2)
{
	int ret = 0;
	char *p1 = NULL, *p2 = NULL;//声明指针变量
	int len = 0, i = 0;
	if (str1 == NULL || str2 == NULL)//空指针
	{
		return -1;//如果是空指针的时候会返回-1给ret
		return ret;
	}
	len = strlen(str1);//获取字符串的长度
	//打造初始化环境
	strcpy(str2, str1); //拷贝字符串
	p1 = str2 + 1;//地址加一，*p1为*p2后面的一个元素的地址（一个字符对应一个地址）
	p2 = str2;//地址
	for (i = 0; i < len; i++)//len为str1的长度
	{
		if (isalpha(*p1) && isspace(*p2))//所以p1地址的为a，p2的地址为空格，则进入判断条件
		{
			*p1 = *p1 - 32;//对应每一个元素的位置，单词第一个字母转化大写
		}
		//打造循环条件
		p2 = p1;//地址赋值
		p1++;//再加一次地址
	}
	return ret;
}
void main()
{
	int ret = 0;
	const char *str1 = "i am student ,you are teacher";//应该获取的是首地址，因为肯能一个地址存不下，所以获取的是首地址
	char buf[1024] = { 0 };

	ret = GetString(str1, buf);//将读取的str1字符串的值依次存入buf中。有可能返回-1
	if (ret != 0)
	{
		printf("func GEtString() err:%d\n", ret);//失败
		return ret;
	}
	printf("buf:%s\n", buf);//打印buf
}
//通过这个例子，我详细了解了内存中一次读取每个字符的过程，并且存入buf，通过循环。判断空格和值。
//让我详细了调试查看内存的过程。知道了底层计算机内存执行的过程。
//指针的地址为首地址，一个字符一个地址。