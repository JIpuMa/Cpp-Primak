#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int s = 20;
	int M[s] = {0};
	int i = 1, mul = 1;
	double el = 1, sum = 0;
	do
	{
		cout << "El " << i << ": ";
		cin >> el;
		if (el == 0)
		{
			i--;
			break;
		}
		M[i] = el;
		i++;
		mul *= el;
		sum += pow(el, -1);
	} while (i != 20);
	cout << "Number: " << i << endl;
	cout << "Multiplication: " << mul << endl;
	cout << "Harmonic mean: " << (double) (i / sum) << endl;
	return 0;
}