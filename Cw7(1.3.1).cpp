#include <iostream>
using namespace std;

int main()
{
	cout << "n = ";
	unsigned long long n = 0;
	cin >> n;

	unsigned long long m;
	m = 1 << n;
	cout << "2^n = " << m;
}