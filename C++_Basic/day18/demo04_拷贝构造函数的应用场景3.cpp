#include"iostream"
using namespace std;
class Location
{
public:
	Location(int xx = 0, int yy = 0)
	{
		X = xx; Y = yy; cout << "Constructor Object.\n";
	}
	Location()
	{
		cout << X << "," << Y << "Object destroyed." << endl;
	}
	int GetX()
	{
		return X;
	} int GetY()
	{
		return Y;
	}
private:int X, Y;
};
void f(Location p)
{
	cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl;
}
void main()
{
	Location A(1, 2);
	f(A);
}