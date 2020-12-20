#include <iostream>
#include <cmath>
using namespace std;

int create_ak1(int index)
{
	int a1 = 0, a2 = 1;

	if (index == 1)
	{
		return a1;
	}
	else
	{
		if (index == 2)
		{
			return a2;
		}
		else
		{
			return create_ak1(index - 1) + index * create_ak1(index - 2);
		}
	}
}

double create_ak2(int index)
{
	int a1 = 1, a2 = 1;

	if (index == 1)
	{
		return a1;
	}
	else
	{
		if (index == 2)
		{
			return a2;
		}
		else
		{
			return create_ak2(index - 1) / index + create_ak2(index - 2);
		}
	}
}

int main()
{
	std::cout << "Input n = ";
	int n = 0;
	cin >> n;

	double S = 0;

	std::cout << "Which example do you want to see? (a/b): ";
	char example = '\0';
	cin >> example;

	if (example == 'a')
	{
		for (int index = 1; index <= n; ++index)
		{
			S += pow(2, index) * create_ak1(index);
		}
	}
	else
	{
		for (int index = 1; index <= n; ++index)
		{
			S += pow(3, index) / create_ak2(index);
		}
	}

	std::cout << "S = " << S;

	return 0;
}