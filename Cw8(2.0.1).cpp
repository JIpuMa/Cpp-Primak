#include <iostream>
using namespace std;

int main()
{
	const int s = 5;
	int M[s] = { 1, 2, 3, 4, 5 };

	cout << "Number: ";
	double num;
	cin >> num;

	int k = 0;

	for (int i = 0; i < s; i++)
	{
		if (M[i] < num)
		{
			k++;
		}
	}

	cout << k << " elements";

	return 0;
}