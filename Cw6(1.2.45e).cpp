#include <iostream>
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
	double element = 0;
	double index = 0;

	do {
		element = pow(x, index) / factorial(index);
		y += element;
		++index;
	} while (element > eps);

	cout << "y = e^x = " << y;

	return 0;
}