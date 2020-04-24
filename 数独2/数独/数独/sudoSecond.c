#include<stdio.h>
//负责输出二维数组的一行，并给数组添加格式
void row_output(int i, int x[9][9])
{
	int j, flag;
	for (j = 0; j < 9; j++)
	{
		//检查是否为3的倍数
		flag = (j + 1) % 3;
		//当是3的倍数时加入两个空格
		if (flag == 0)
			printf("%d  ", x[i][j]);
		//否则加入一个空格
		else
			printf("%d ", x[i][j]);
	}
}
//000 000 000
//负责按照九宫格的形式将数组输出
void output(int x[9][9])
{
	int i, flag;
	for (i = 0; i < 9; i++)
	{
		//检查是否为3的倍数
		flag = (i + 1) % 3;
		row_output(i, x);
		//当是3的倍数时加入两个空行
		if (flag == 0)
			printf("\n\n");
		//否则加入一个空行
		else
			printf("\n");
	}
}
/*
0 0 0

0 0 0

0 0 0*/
//validate函数负责检查下x[i][j]是否为可行的值
int validate(int x[9][9], int i, int j, int num)
{
	int row, column;
	int isPossible = 1;
	//遍历第i行查询是否有重复的值
	for (column = 0; column < 9; column++)
	{
		if (num == x[i][column]) isPossible *= 0;
		else isPossible *= 1;
	}
	//遍历第j列查询是否有重复的值
	for (row = 0; row < 9; row++)
	{
		if (num == x[row][j]) isPossible *= 0;
		else isPossible *= 1;
	}
	//遍历x[i][i]所在宫(box)查询是否有重复的值
	int box_i, box_j;
	//定位宫的位置
	int offset_x, offset_y;
	//计算x方向(即j序号增加方向)偏移量
	offset_x = j - j % 3;
	//计算y方向(即i序号增加方向)偏移量
	offset_y = i - i % 3;
	for (box_i = 0; box_i < 3; box_i++)
	{
		for (box_j = 0; box_j < 3; box_j++)
		{
			//将box_i,box_j修正到正确的九宫格
			if (num == x[box_i + offset_y][box_j + offset_x]) isPossible *= 0;
			else isPossible *= 1;
		}
	}
	//验证无误返回1，否则返回0
	return isPossible;
}

void solve_soduku(int x[9][9])
{
	int i, j, num, flag = 0;
	//新建一个二维数组负责记录不可更改数字（即开始时就被填入的数字）的位置
	int can_not_modify[9][9] = { 0 };
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (x[i][j] != 0) can_not_modify[i][j] = 1;
		}
	}
	//初始化i和j
	i = 0;
	j = 0;
	//遍历九宫格，从x[0][0]开始尝试
	while (i < 9)
	{
		while (j < 9)
		{
			//判断是否为上一行试错跳转而来
		start:if (flag == 1 && j == -1)
		{
			i--;
			j = 8;
			goto start;
		}
		//判断是否为试错跳转而来且当前值不可修改
		else if (flag == 1 && can_not_modify[i][j] == 1)
		{
			//继续返回上一层
			j--;
			continue;
		}
		//判断当前格子是否不可修改
		else if (can_not_modify[i][j] == 1)
		{
			j++;
			continue;
		}
		//开始尝试
		else
		{
			num = x[i][j];
			//若当前格子还未赋值，即不是由上一次试错跳转而来，从1开始尝试
			if (num == 0) num = 1;
			//若flag==1即是由上一次试错而来，从上一次错误的值+1继续尝试
			else if (flag == 1) num = x[i][j] + 1;
			//初始化跳转标识的值
			flag = 0;
			//从num开始向后逐个尝试
			for (; num <= 10; num++)
			{
				//用validate函数判断尝试的值是否可行
				//如果可行将当前格子的值变为num
				if (validate(x, i, j, num) == 1 && num < 10)
				{
					x[i][j] = num;
					j++;
					break;
				}
				//如果到9还没有可行的值填入，说明前面有错，初始当前值为0，返回上一次尝试
				else if (num == 10)
				{
					x[i][j] = 0;
					j--;
					//打上跳转标识flag=1
					flag = 1;
					break;
				}
			}
		}
		}
		//一行填满从下一行第一个继续尝试
		j = 0;
		i++;
	}
}

void main()
{
	int i, j;
	char temp;
	int soduku[9][9];
	printf("数独求解by minx:\n 2019/12/22\n\n\n");
	printf("请输入您要求解的数独:\n");
	printf("  123456789\n");
	for (i = 0; i < 9; i++)
	{
		printf("%d:", i + 1);
		for (j = 0; j < 10; j++)
		{
			temp = getchar();
			if (j < 9) soduku[i][j] = temp - '0';
		}
	}
	printf("\n您输入的数独是:\n");
	output(soduku);
	solve_soduku(soduku);
	printf("结果是:\n");
	output(soduku);
}
/*
003070000
010906230
050130006
060000180
901000504
082000070
700084050
048502060
000010800
*/

/*
6 9 3  2 7 5  4 1 8
8 1 7  9 4 6  2 3 5
2 5 4  1 3 8  7 9 6

4 6 5  7 2 9  1 8 3
9 7 1  8 6 3  5 2 4
3 8 2  4 5 1  6 7 9

7 2 6  3 8 4  9 5 1
1 4 8  5 9 2  3 6 7
5 3 9  6 1 7  8 4 2
*/

/*
6 9 3 2 7 5 4 1 8
8 1 7 9 4 6 2 3 5
2 5 4 1 3 8 7 9 6
4 6 5 7 2 9 1 8 3
9 7 1 8 6 3 5 2 4
3 8 2 4 5 1 6 7 9
7 2 6 3 8 4 9 5 1
1 4 8 5 9 2 3 6 7
5 3 9 6 1 7 8 4 2*/