#include <iostream>
using namespace std;

int main()
{
	int element = 0;
	int index = 1;
	int min_el = 1000000;
	int index_min = 0;

	do {
		cout << "Input number: ";
		cin >> element;
		if ((element < min_el) && (element != 0))
		{
			min_el = element;
			index_min = index;
		}
		++index;
	} while (element != 0);

	cout << "Index of minimal element: " << index_min;

	return 0;
}