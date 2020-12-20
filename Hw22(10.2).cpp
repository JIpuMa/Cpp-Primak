#include <iostream>
#include <cmath>
using namespace std;

double checkEps(double eps);
double checkZ(double z);
double arctg(double z, double eps);

int main()
{
	cout << "e(e>0): ";
	double eps = 0;
	cin >> eps;
	
	cout << "z(|z|<1): ";
	double z = 0;
	cin >> z;
	
	try
	{
		checkEps(eps);
		checkZ(z);
		cout << "arctg(" << z << ") = " << arctg(z, eps) << endl;
	}
	catch (const char* exp1)
	{
		cout << "Exception: " << exp1 << endl;
	}

	return 0;
}

double checkEps(double eps)
{
	if (eps <= 0)
	{
		throw "e must be < 0";
	}
	return eps;
}

double checkZ(double z)
{
	if (abs(z) >= 1)
	{
		throw "|z| must be < 1";
	}
	return z;
}

double arctg(double z, double eps)
{
	double result = 0;
	int n = 0;
	double element = eps + 1;
	do {
		element = pow(-1, n) * pow(z, 2 * n + 1) / (2 * n + 1);
		result += element;
		++n;
	} while (abs(element) > eps);

	return result;
}