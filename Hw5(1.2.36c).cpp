#include <iostream>
using namespace std;

double calc(int n);

int main()
{
	cout << "Input n: ";
	int n = 0;
	cin >> n;

	cout << "X(2n): " << 1+1/calc(n);

	return 0;
}

double calc(int n)
{
	if (n == 0)
		return 2;
	else
		return 2 + 1 / calc(n - 1);
}