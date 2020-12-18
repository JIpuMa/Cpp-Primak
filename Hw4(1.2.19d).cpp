#include <iostream>
using namespace std;

int main()
{
	cout << "Input x: ";
	double x = 0;
	cin >> x;

	cout << "Input k: ";
	int k = 0;
	cin >> k;

	double xk = 1;

	for (int index = 1; index <= k; ++index)
	{
		xk *= -x / index;
	}

	cout << "xk = " << xk;

	return 0;
}