#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	int a, b, c;
	cout << "����i�� 3 �i��� �����: ";
	cin >> a >> b >> c;

	int m;
	m = a * b * c;

	if ((fabs(a) < pow(2, 10)) && (fabs(b) < pow(2, 10)) && (fabs(c) < pow(2, 10)))
	{
		cout << "a) a*b*c = " << m << endl;
	}

	if ((fabs(a) < pow(2, 21)) && (fabs(b) < pow(2, 21)) && (fabs(c) < pow(2, 21)))
	{
		cout << "�) a*b*c = " << m << endl;
	}
}