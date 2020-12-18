#include <iostream>
using namespace std;

bool f1(int n)
{
	bool k = false;
	if (n % 2 == 0)
	{
		k = true;
	}
	return k;
}

bool f2(int n)
{
	bool k = false;
	if (n % 10 == 0)
	{
		k = true;
	}
	return k;
}

bool f3(int n, int m)
{
	bool k = false;
	if (n % m == 0)
	{
		k = true;
	}
	return k;
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;

	bool ans1;
	ans1 = f1(n);
	cout << "a) " << ans1 << endl;

	bool ans2;
	ans2 = f2(n);
	cout << "b) " << ans2 << endl;

	int m;
	cout << "m = ";
	cin >> m;

	bool ans3;
	ans3 = f3(n, m);
	cout << "c) " << ans3 << endl;
}