#include <iostream>
using namespace std;

int main()
{
	const int N = 10;
	int A[N] = { 0 };
	int moda = 0;
	int max_repeats = 1;
	int num_of_repeats = 1;
	int num_of_repeats_for_several = 1;

	for (int index1 = 0; index1 < N; ++index1)
	{
		cout << "Input A[" << index1 << "] = ";
		int element = 0;
		cin >> element;

		A[index1] = element;
		num_of_repeats = 1;

		for (int index2 = 0; index2 < index1; ++index2)
		{
			if (A[index1] == A[index2])
				++num_of_repeats;
			if (num_of_repeats > max_repeats)
			{
				max_repeats = num_of_repeats;
				moda = A[index1];
			}
			else if (num_of_repeats == max_repeats)
			{
				num_of_repeats_for_several = num_of_repeats;
			}
		}
	}

	cout << "Moda = ";

	if ((max_repeats == num_of_repeats_for_several) && (max_repeats != 1))
	{
		for (int index1 = 0; index1 < N; ++index1)
		{
			num_of_repeats = 0;
			for (int index2 = index1+1; index2 < N; ++index2)
			{
				if (A[index1] == A[index2])
				{
					++num_of_repeats;
					if (num_of_repeats = num_of_repeats_for_several)
					{
						cout << A[index1] << " ";
						break;
					}
				}
			}
		}
	}
	else if (max_repeats == 1)
	{
		for (int index = 0; index < N; ++index)
		{
			cout << A[index] << " ";
		}
	}
	else
		cout << moda;

	return 0;
}