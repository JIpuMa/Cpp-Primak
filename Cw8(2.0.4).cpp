#include <iostream>
using namespace std;

int main()
{
	const int s = 5;
	int M[s] = {0};

	int el = 0;
	int max = 0;

	for (int i = 0; i < s; i++)
	{
		int el;
		cout << "Element " << i + 1 << ": ";
		cin >> el;
		M[i] = el;

		if (i == 0)
			max = el;
		else if (el > max)
			max = el;
	}

	cout << "Max = " << max;

	return 0;
}