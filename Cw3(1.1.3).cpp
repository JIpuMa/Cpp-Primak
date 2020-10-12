#include <iostream>
using namespace std;

double f(double a, double b, double c)
{
	double max;
	if (a < b)
	{
		if (b < c)
		{
			max = c;
		}
		else
		{
			max = b;
		}
	}
	else
	{
		if (a < c)
		{
			max = c;
		}
		else
		{
			max = a;
		}
	}
	return max;
}

int main()
{
	double x, y, z;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "z = ";
	cin >> z;

	double a, b, c;
	a = x + z + y;
	b = x * y - x * z + y * z;
	c = x * y * z;

	double ans;
	ans = f(a, b, c);
	cout << "a) max = " << ans << endl;

	a = x * y;
	b = x * z;
	c = y * z;

	ans = f(a, b, c);
	cout << "b) max = " << ans << endl;
}