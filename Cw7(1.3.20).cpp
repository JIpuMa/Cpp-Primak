#include <iostream>
using namespace std;

int main()
{
	int M = (1 << 24) + (2 << 16) + (3 << 8) + 4;
	int a1 = M & 0xFF;
	int a2 = (M & 0xFF00) >> 8;
	if ((a1 == 4) && (a2 == 3))
	{
		cout << "little";
	}
	else if ((a1 == 4) && (a2 == 2))
	{
		cout << "middle";
	}
	else if (a1 == 1)
	{
		cout << "big";
	}
	else
	{
		cout << "unknown";
	}
}