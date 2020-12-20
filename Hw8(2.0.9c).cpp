#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int N = 5;
	int array[N] = { 0 };
	int numDegreeNums = 0;
	
	cout << "Input n(n>1): ";
	int n = 0;
	cin >> n;

	for (int index1 = 0; index1 < N; ++index1)
	{
		cout << "Input array[" << index1 << "] = ";
		int element = 0;
		cin >> element;
		array[index1] = element;
		if (array[index1] > 1)
			for (double index2 = 2; index2 <= n; ++index2)
			{
				if ((pow(array[index1], (double)1 / index2) == (int)pow(array[index1], (double)1 / index2)) || 
					(pow(((int)pow(array[index1], (double)1 / index2)+1),index2) == array[index1]))
				{
					++numDegreeNums;
					break;
				}
			}
	}
	cout << "Number of numbers of n-th degrees: " << numDegreeNums << endl;

	return 0;
}
