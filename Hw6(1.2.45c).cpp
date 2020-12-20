#include <iostream>
#include <cmath>
using namespace std;

double factorial(double n)
{
	double factorial_from_n = 1;

	for (int index = 1; index <= n; ++index)
	{
		factorial_from_n *= index;
	}

	return factorial_from_n;
}

int main()
{
	cout << "Input e (e > 0): ";
	double eps = 0;
	cin >> eps;

	cout << "Input x: ";
	double x = 0;
	cin >> x;

	double y = 0;
	double ak = 0;
	double index = 1;

	do {
		ak = pow(x, 2 * index - 1) / factorial(2 * index - 1);
		y += ak;
		++index;
	} while (abs(ak) > eps);

	cout << "y = sh(x) = " << y;

	return 0;
}