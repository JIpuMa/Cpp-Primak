#include <iostream>
using namespace std;

int main()
{
	const int m = 2;
	const int n = 3;
	double array[m][n] = { 0 };
	for (int index1 = 0; index1 < m; ++index1)
	{
		for (int index2 = 0; index2 < n; ++index2)
		{
			cout << "Array[" << index1 << "][" << index2 << "] = ";
			int element = 0;
			cin >> element;
			array[index1][index2] = element;
		}
	}

	return 0;
}