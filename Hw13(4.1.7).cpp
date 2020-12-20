#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream f("C:\\Users\\User\\Desktop\\f.txt");
	ofstream h("C:\\Users\\User\\Desktop\\h.txt");
	ofstream g("C:\\Users\\User\\Desktop\\g.txt");

	cout << "Input N: ";
	int N = 0;
	cin >> N;

	cin.ignore();

	string str;
	for (int index = 0; index < N; ++index)
	{
		cout << "Input string " << index + 1 << ": ";
		getline(cin, str);

		f << str << '\n';
		if (((index + 1) % 2) == 1)
		{
			h << str << '\n';
		}
		else
		{
			g << str << '\n';
		}
	}

	return 0;
}