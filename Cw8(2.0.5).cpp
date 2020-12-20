#include <iostream>
using namespace std;

int main()
{
	const int size = 5;
	int M[size] = { 0 };

	int sum1 = 0;
	int sum2 = 0;

	for (int index = 0; index < size; ++index)
	{
		cout << "Input M[" << index + 1 << "] = ";
		int element = 0;
		cin >> element;
		if ((index + 1) % 2 == 1)
			sum1 += element;
		else
			sum2 += element;
	}
	cout << "Sum of odd numbers: " << sum1 << endl;
	cout << "Sum of even numbers: " << sum2 << endl;
	return 0;
}