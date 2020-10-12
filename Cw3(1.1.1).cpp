#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	int max, min;

	if (a < b)
	{
		max = b;
		min = a;
	}
	else
	{
		max = a;
		min = b;
	}

	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
}