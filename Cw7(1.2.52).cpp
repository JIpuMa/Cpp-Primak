#include <iostream>
#include <cmath>
using namespace std;

double yx(double x)
{
	return pow(x, 3) + 4 * pow(x, 2) + x - 6;
}

double un(double b)
{
	double u = 0;
	if (b == 0)
		u = 0;
	else
		u = un(b - 1) - yx(b - 1) * (b - un(b - 1)) / (yx(b) - yx(b - 1));
	return u;
}

int main()
{
	cout << "Input e(e>0): ";
	double eps = 0;
	cin >> eps;

	int answer = 0;
	for (int b = 2; b >= 1; --b)
	{
		if (abs(un(b) - un(b - 1)) < eps)
			answer = un(b);
	}

	cout << "x = " << answer;

	return 0;
}