#include <iostream>
using namespace std;

int main()
{
	const int N = 2;
	const int M = 3;
	int array[N][M] = { 0 };
	for (int index1 = 0; index1 < N; ++index1)
	{
		for (int index2 = 0; index2 < M; ++index2)
		{
			cout << "Array[" << index1 << "][" << index2 << "] = ";
			int element = 0;
			cin >> element;
			array[index1][index2] = element;
		}
	}

	cout << "Input k: ";
	int k = 0;
	cin >> k;

	int sum = 0;
	for (int index1 = 0; index1 < N; ++index1)
	{
		for (int index2 = 0; index2 < M; ++index2)
		{
			if ((index1 - index2) == k)
			{
				sum += array[index1][index2];
			}
		}
	}
	cout << "Result: " << sum << endl;

	return 0;
}