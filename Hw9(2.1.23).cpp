#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	const int n = 3;
	const int m = 3;
	int array[n][m] = { 0 };
	for (int index1 = 0; index1 < n; ++index1)
		for (int index2 = 0; index2 < m; ++index2)
		{
			cout << "Input array[" << index1 << "][" << index2 << "] = ";
			int element = 0;
			cin >> element;
			array[index1][index2] = element;
		}
	int min = 0;
	int arrayOfMin[m] = { 0 };
	for (int index1 = 0; index1 < m; ++index1)
	{
		for (int index2 = 0; index2 < n; ++index2)
		{
			if (index2 == 0)
				min = array[index2][index1];
			else if (min > array[index2][index1])
				min = array[index2][index1];
		}
		arrayOfMin[index1] = min;
	}

	cout << endl << "Your array: " << endl;
	for (int index1 = 0; index1 < n; ++index1)
	{
		for (int index2 = 0; index2 < m; ++index2)
			cout << array[index1][index2] << " ";
		cout << endl;
	}

	for (int index1 = 0; index1 < m-1; ++index1)
	{
		int smallestIndex = index1;
		for (int index2 = index1+1; index2 < m; ++index2)
		{
			if (arrayOfMin[index2] < arrayOfMin[index1])
				smallestIndex = index2;
		}
		swap(arrayOfMin[index1], arrayOfMin[smallestIndex]);
		for (int index3 = 0; index3 < n; ++index3)
			swap(array[index3][index1], array[index3][smallestIndex]);
	}

	cout << endl << "New array: " << endl;
	for (int index1 = 0; index1 < n; ++index1)
	{
		for (int index2 = 0; index2 < m; ++index2)
			cout << array[index1][index2] << " ";
		cout << endl;
	}
	
	return 0;
}