#include <iostream>
using namespace std;

class Rectangle
{
private:
	int x = 0;
	int y = 0;
	int a = 0;
	int b = 0;
public:
	void inputX(int x0)
	{
		x = x0;
	}
	void inputY(int y0)
	{
		y = y0;
	}
	void inputA(int a0)
	{
		a = a0;
	}
	void inputB(int b0)
	{
		b = b0;
	}
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
	int getP()
	{
		return 2 * (a + b);
	}
	int getS()
	{
		return a * b;
	}
};

int main()
{
	Rectangle rec;

	cout << "x: ";
	int x = 0;
	cin >> x;
	rec.inputX(x);

	cout << "y: ";
	int y = 0;
	cin >> y;
	rec.inputY(y);

	cout << "a: ";
	int a = 0;
	cin >> a;
	rec.inputA(a);

	cout << "b: ";
	int b = 0;
	cin >> b;
	rec.inputB(b);

	cout << endl;

	cout << "a = " << rec.getA() << endl;
	cout << "b = " << rec.getB() << endl;
	cout << "P = " << rec.getP() << endl;
	cout << "S = " << rec.getS() << endl;

	return 0;
}