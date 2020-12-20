#include <iostream>
using namespace std;

int main()
{
	cout << "M = ";
	unsigned long long M;
	cin >> M;

	cout << "j = ";
	unsigned j;
	cin >> j;

	M = M & ~(1 << j);
	cout << "M(10) = " << M << endl;;
	cout << "M(16) = 0x" << hex << M;

	return 0;
}