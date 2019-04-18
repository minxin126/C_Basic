#include"stdio.h"
#include"stdlib.h"
#include"string.h"
char **readFile1(const char *pfilename, int *lineNum)
{
	int rv = 0;
	FILE *fp = NULL;
	char lineBuf[1024 * 4];

	char **pTmp = NULL;
	char *p = NULL;
	int tmpLine = 0, strLine = 0, i = 0;

	if (pfilename == NULL || lineNum == NULL)
	{
		rv = -1;
		printf("readFile1() err.param err \n");
		goto End;
	}
	fp = fopen(pfilename, "r");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		goto End;
	}
	//第一遍 读取文件有多少行
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		p = fgets(lineBuf, 1024 * 4, fp);
		if (p = NULL)
		{
			break;
		}
		else
		{
			tmpLine++;
		}
	}
	pTmp = (char **)malloc(tmpLine * sizeof(char *));
	if (pTmp == NULL)
	{
		rv = -2;
		printf("malloc() err. \n");
		goto End;
	}
	//文件指针指向文件的开头，目的：第二次从头检索
	fseek(fp, 0l, SEEK_SET);
	//
	i = 0;
	while (!feof(fp))
	{
		//读取每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		p = fgets(lineBuf, 1024 * 4, fp);
		if (p = NULL)
		{
			break;
		}
		strLine = strlen(lineBuf);
		pTmp[i] = (char *)malloc((strLine + 1) * sizeof(char));
		if (pTmp[i] == NULL)
		{
			rv = -3;
			printf("malloc() err. \n");
			goto End;
		}
		strcpy(pTmp[i], lineBuf);
		i++;
	}
End:
	if (fp != NULL)
	{
		fclose(fp);
	}
	//赋值
	*lineNum = tmpLine;
	return pTmp;
}
void FreeMypp(char **p, int linenum)
{
	int i = 0;
	if (p = NULL)
	{
		return NULL;
	}
	for (i = 0; i < linenum; i++)
	{
		if (p[i] != NULL)
		{
			free(p[i]);
		}
		free(p);
		return;
	}
}
void main()
{
	char **mypp = NULL;
	const char *pfilename = "c:/1.txt";
	int lineNum = 0, i = 0;

	mypp = readFile1(pfilename, &lineNum);
	if (mypp == NULL)
	{
		return;
	}
	for (i = 0; i < lineNum; i++)
	{
		printf("%s\n", mypp[i]);
	}
	system("pause");
}