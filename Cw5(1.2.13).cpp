#include <iostream>
using namespace std;

int main()
{
	int index = 0;
	int element = 0;
	int sum_of_elements = 0;

	do {
		cout << "a[" << index << "]=";
		cin >> element;
		sum_of_elements += element;
		index++;
	} while (element != 0);

	cout << "Sum = " << sum_of_elements;

	return 0;
}