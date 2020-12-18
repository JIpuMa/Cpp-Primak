#include <iostream>
using namespace std;

double num_and_sol(double a, double b, double c)
{
	double x1, x2;
	if ((a == 0) && (b == 0) && (c == 0))
	{
		cout << "infinite solution" << endl;
	}
	else if ((a == 0) && (b == 0) && (c != 0))
	{
		cout << "no solution" << endl;
	}
	else if ((a == 0) && (b != 0))
	{
		cout << "1 solution" << endl;
		x1 = -c / b;
		cout << "x1 = " << x1 << endl;
	}
	else if (a != 0)
	{
		if (b * b - 4 * a * c == 0)
		{
			cout << "1 solution" << endl;
			x1 = -b / (2 * a);
			cout << "x1 = " << x1 << endl;
		}
		else if (b * b - 4 * a * c > 0)
		{
			cout << "2 solutions" << endl;
			x1 = (-b + b * b - 4 * a * c) / (2 * a);
			cout << "x1 = " << x1 << endl;
			x2 = (-b - b * b - 4 * a * c) / (2 * a);
			cout << "x2 = " << x2 << endl;
		}
		else
		{
			cout << "no solution" << endl;
		}
	}
	return 0;
}

int main()
{
	double a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	int n;
	n = num_and_sol(a, b, c);
}