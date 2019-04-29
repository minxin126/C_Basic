#include <stdlib.h>
#include"stdio.h"
void printArray05(int array[], int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}

void swap5(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
//划分过程 第一个元素当枢轴，分成2个有效子序列
int partition(int array[], int low, int high)
{
	int pv = array[low];

	while (low < high)
	{
		while ((low < high) && (array[high] >= pv))
		{
			high--; //比基准大，本来就在右边，所以high前移动
		}
		swap5(array, low, high);
		while ((low < high) && (array[low] <= pv))
		{
			low++;
		}
		swap5(array, low, high);
	}
	//返回枢轴的位置。。。重要
	return low;
}

//让n个元素 依此减少 减少到1个元素的时候，因为1个元素可以看成一个有序的序列

void QSort2(int array[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);

		//对子序列1排序
		QSort2(array, low, pivot - 1);
		//对子序列2排序
		QSort2(array, pivot + 1, high);
	}
}

void QSort(int array[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);

		//对子序列1排序
		QSort2(array, low, pivot - 1);
		//对子序列2排序
		QSort2(array, pivot + 1, high);
	}
}

void QuickSort(int array[], int len) // O(n*logn)
{
	QSort(array, 0, len - 1);
}

int main1()
{
	//int array[] = {12, 5, 433, 253, 216, 7};
	//int array[] = {12, 5, 433};
	int array[] = { 12, 5 };
	int len = sizeof(array) / sizeof(*array);
	printArray05(array, len);
	QuickSort(array, len);
	printArray05(array, len);
	system("pause");
	return 0;
}