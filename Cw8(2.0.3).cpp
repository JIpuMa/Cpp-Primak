#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int s = 10;
	double M[s] = {};
	int sum = 0;

	for (int i = 0; i < s; i++)
	{
		cout << "Element " << i+1 << ": ";
		int el;
		cin >> el;

		M[i] = el;

		if (el > exp(1))
		{
			sum += el;
		}
	}

	cout << "Sum = " << sum;

	return 0;
}