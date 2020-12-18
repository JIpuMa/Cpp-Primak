#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double _1, _2, _3;
	do
	{
		cin >> _1 >> _2 >> _3;
	} while ((_1 == _2) || (_1 == _3) || (_2 == _3));

	_1 = fabs(_1);
	_2 = fabs(_2);
	_3 = fabs(_3);

	double max, min;

	if (_1 < _2)
	{
		if (_1 < _3)
		{
			min = _1;
			if (_2 < _3)
			{
				max = _3;
			}
			else
			{
				max = _2;
			}
		}
		else
		{
			min = _3;
			max = _2;
		}
	}
	else
	{
		if (_2 < _3)
		{
			min = _2;
			if (_1 < _3)
			{
				max = _3;
			}
			else
			{
				max = _1;
			}
		}
		else
		{
			min = _3;
			max = _1;
		}
	}
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
}