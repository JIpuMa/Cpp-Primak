#include <iostream>
#include <cmath>
using namespace std;

double num_and_sol(double a, double b, double c)
{
	double x1, x2, x3, x4;
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
		if (-c / b > 0)
		{
			cout << "2 solutions" << endl;
			x1 = sqrt(-c / b);
			cout << "x1 = " << x1 << endl;
			x2 = -sqrt(-c / b);
			cout << "x2 = " << x2 << endl;
		}
		else
		{
			cout << "no solution" << endl;
		}
	}
	else if (a != 0)
	{
		if (b * b - 4 * a * c == 0)
		{
			if (-b / (2 * a) > 0)
			{
				cout << "2 solutions" << endl;
				x1 = sqrt(-b / (2 * a));
				cout << "x1 = " << x1 << endl;
				x2 = -sqrt(-b / (2 * a));
				cout << "x2 = " << x2 << endl;
			}
			else
			{
				cout << "no solution" << endl;
			}
		}
		else if (b * b - 4 * a * c > 0)
		{
			if (((-b + b * b - 4 * a * c) / (2 * a) > 0) && ((-b - b * b - 4 * a * c) / (2 * a) > 0))
			{
				cout << "4 solutions" << endl;
				x1 = sqrt(-b + b * b - 4 * a * c) / (2 * a);
				cout << "x1 = " << x1 << endl;
				x2 = -sqrt(-b + b * b - 4 * a * c) / (2 * a);
				cout << "x2 = " << x2 << endl;
				x3 = sqrt(-b - b * b - 4 * a * c) / (2 * a);
				cout << "x3 = " << x3 << endl;
				x4 = -sqrt(-b - b * b - 4 * a * c) / (2 * a);
				cout << "x4 = " << x4 << endl;
			}
			else if ((-b + b * b - 4 * a * c) / (2 * a) > 0)
			{
				cout << "2 solutions" << endl;
				x1 = sqrt(-b + b * b - 4 * a * c) / (2 * a);
				cout << "x1 = " << x1 << endl;
				x2 = -sqrt(-b + b * b - 4 * a * c) / (2 * a);
				cout << "x2 = " << x2 << endl;
			}
			else if ((-b - b * b - 4 * a * c) / (2 * a) > 0)
			{
				cout << "2 solutions" << endl;
				x1 = (-b - b * b - 4 * a * c) / (2 * a);
				cout << "x1 = " << x1 << endl;
				x2 = (-b - b * b - 4 * a * c) / (2 * a);
				cout << "x2 = " << x2 << endl;
			}
			else
			{
				cout << "no solution" << endl;
			}
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