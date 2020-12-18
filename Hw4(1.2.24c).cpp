#include <iostream>
using namespace std;

int main()
{
	cout << "Input n: ";
	int n = 0;
	cin >> n;

	int y = 0;
	int function = 0;

	for (int index = 0; index < n; ++index)
	{
		cout << "Input y" << index + 1 << " = ";
		cin >> y;
		if ((0 >= y) || (y >= 10))
			y = 0;
		function += y;
	}

	cout << "z1+...+zn = " << function;

	return 0;
}