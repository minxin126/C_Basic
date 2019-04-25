#include"iostream"
using namespace std;
void search(int a[], int len) //O(n)
{
	int sp[1000] = { 0 };
	int i = 0;
	int max = 0;

	for (i = 0; i < len; i++) //n
	{
		//把数字出现的次数，放在数组sp中。存放的方法 求下标的方法：数字-1
		int index = a[i] - 1;

		sp[index]++;//累计数字出现的次数
	}

	for (i = 0; i < 1000; i++) //1000
	{
		if (max < sp[i])
		{
			max = sp[i];
		}
	}

	for (i = 0; i < 1000; i++) //1000
	{
		if (max == sp[i])
		{
			printf("%d\n", i + 1);
		}
	}
}

int main()
{
	int array[] = { 1, 1, 3, 4, 5, 6, 6, 6, 2, 3 };

	//search(array, sizeof(array)/sizeof(*array));
	search(array, sizeof(array) / sizeof(array[0]));
	system("pause");
	return 0;
}