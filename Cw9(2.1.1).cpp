#include <iostream>
using namespace std;

int main()
{
	const int n = 3;
	int array[n][n] = { {1,2,3},{4,5,6},{7,8,9} };
	int arrayTransposed[n][n] = { 0 };
	for (int index1 = 0; index1 < n; ++index1)
	{
		for (int index2 = 0; index2 < n; ++index2)
		{
			arrayTransposed[index2][index1] = array[index1][index2];
		}
	}

	cout << "N: ";
	int N = 0;
	cin >> N;

	cout << "M: ";
	int M = 0;
	cin >> M;

	for (int index1 = 0; index1 < n; ++index1)
	{
		for (int index2 = 0; index2 < n; ++index2)
		{
			if (arrayTransposed[index1][index2] == M)
			{
				arrayTransposed[index1][index2] = N;
			}
		}
	}

	cout << endl << "New matrix:" << endl;
	for (int index1 = 0; index1 < n; ++index1)
	{
		for (int index2 = 0; index2 < n; ++index2)
		{
			cout << arrayTransposed[index1][index2] << " ";
		}
		cout << endl;
	}

	return 0;
}