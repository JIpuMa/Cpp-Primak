#include <iostream>
using namespace std;

int main()
{
	const int n = 3;
	int array[n][n] = { 0 };
	for (int index1 = 0; index1 < n; ++index1)
		for (int index2 = 0; index2 < n; ++index2)
		{
			cout << "Input array[" << index1 << "][" << index2 << "] = ";
			int element = 0;
			cin >> element;
			array[index1][index2] = element;
		}

	cout << "Your array: " << endl;
	for (int index1 = 0; index1 < n; ++index1)
	{
		for (int index2 = 0; index2 < n; ++index2)
		{
			cout << array[index1][index2] << " ";
		}
		cout << endl;
	}

	cout << "Input your element: ";
	int inputElement = 0;
	cin >> inputElement;

	int deleteRow = 0;
	int deleteCol = 0;
	for (int index1 = 0; index1 < n; ++index1)
		for (int index2 = 0; index2 < n; ++index2)
			if (inputElement == array[index1][index2])
			{
				deleteRow = index1;
				deleteCol = index2;
			}

	const int m = n - 1;
	int arraySmall[m][m] = { 0 };

	int check1 = 1;
	int check2 = 1;
	for (int index1 = 0; index1 < n; ++index1)
	{
		check2 = 1;
		if (index1 != deleteRow)
			if (check1 == 1)
			{
				for (int index2 = 0; index2 < n; ++index2)
				{
					if (index2 != deleteCol)
					{
						if (check2 == 1)
						{
							arraySmall[index1][index2] = array[index1][index2];
						}
						else
						{
							arraySmall[index1][index2 - 1] = array[index1][index2];
						}
					}
					else if (index2 == deleteCol)
						check2 = 0;
				}
			}
			else
			{
				for (int index2 = 0; index2 < n; ++index2)
				{
					if (index2 != deleteCol)
					{
						if (check2 == 1)
						{
							arraySmall[index1 - 1][index2] = array[index1][index2];
						}
						else
						{
							arraySmall[index1 - 1][index2 - 1] = array[index1][index2];
						}
					}
					else if (index2 == deleteCol)
						check2 = 0;
				}
			}
		else if (index1 == deleteRow)
			check1 = 0;
	}

	cout << "New array:" << endl;
	for (int index1 = 0; index1 < m; ++index1)
	{
		for (int index2 = 0; index2 < m; ++index2)
		{
			cout << arraySmall[index1][index2] << " ";
		}
		cout << endl;
	}

	return 0;
}