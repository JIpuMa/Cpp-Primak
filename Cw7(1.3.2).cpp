#include <iostream>
using namespace std;

int main()
{
	cout << "n = ";
	unsigned n;
	cin >> n;

	cout << "k = ";
	unsigned k;
	cin >> k;

	n = n | (1 << k);
	cout << "m = " << n;

	return 0;
}