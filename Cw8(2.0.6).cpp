#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	int sum = 0;

	do
	{
		cout << "a[" << i << "]=";
		int el;
		cin >> el;

		sum += el;

		if (el == 0)
			break;

		i++;
	} while (true);

	cout << "Sum = " << sum;

	return 0;
}