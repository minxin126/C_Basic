#include<iostream>
using namespace std;
int main()
{
	const int a = 1;
	const int b = 2;
	int array[a + b] = { 0 };
	int i = 0;
	for (i = 0; i < (a + b); i++)
	{
		cout << "array" << i <<"="<< array[i] << endl;
	}
	cout << "Press enter to continue..." << endl;
	getchar();
	return 0;
}