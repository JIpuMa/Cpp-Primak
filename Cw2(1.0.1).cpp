#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "n = ";
	cin >> n;

	int _1, _10, _100;
	_100 = n / 100;
	_10 = (n % 100) / 10;
	_1 = n % 10;

	cout << "1)" << n << " = " << "100*" << _100 << " + " << "10*" << _10 << " + " << _1 << endl;

	int s;
	s = _100 + _10 + _1;

	cout << "2)" << s << endl;

	int r;
	r = _1 * 100 + _10 * 10 + _100;

	cout << "3)" << r << endl;
}