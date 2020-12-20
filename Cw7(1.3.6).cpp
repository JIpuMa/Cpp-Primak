#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	cout << "Input n: ";
	unsigned short n = 0;
	cin >> n;

	unsigned short m = 0;

	for (int index = 8 * sizeof(n)-1; index >= 0; --index)
	{
		m = m | (((n >> index) & 1) << (8*sizeof(n)-1-index));
	}

	cout << '\n' << "n(2) = " << bitset<sizeof(n)* CHAR_BIT>(n);
	cout << '\n' << "m(2) = " << bitset<sizeof(m)* CHAR_BIT>(m);
	cout << '\n' << "n(10) = " << n;
	cout << '\n' << "m(10) = " << m;

	return 0;
}