#include <iostream>
#include <cmath>
using namespace std;

double ak(double n)
{
	if (n <= 3)
		return 1;
	else
		return ak(n - 1) + ak(n - 3);
}

int main()
{
	cout << "Input n: ";
	int n = 0;
	cin >> n;

	double S = 0;

	for (int index = 1; index <= n; ++index)
	{
		S += ak(index) / pow(2, index);
	}

	cout << "S = " << S;

	return 0;
}