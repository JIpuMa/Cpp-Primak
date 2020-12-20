#include <iostream>
#include <string>
using namespace std;

int main()
{
	printf("Input string: ");
	const int N = 255;
	char str[N];
	fgets(str, N, stdin);

	int len = strlen(str);

	char moda;
	int max_repeats = 1;
	int num_of_repeats = 1;
	int num_of_repeats_for_several = 1;

	for (int index1 = 0; index1 < len; ++index1)
	{
		num_of_repeats = 1;
		for (int index2 = index1+1; index2 < len; ++index2)
		{
			if (str[index1] == str[index2])
			{
				++num_of_repeats;
				if (num_of_repeats > max_repeats)
				{
					max_repeats = num_of_repeats;
					moda = str[index1];
				}
				else if (num_of_repeats == max_repeats)
				{
					num_of_repeats_for_several = num_of_repeats;
				}
			}
			else
			{
				break;
			}
		}
	}

	cout << "Element(s): ";

	if ((max_repeats == num_of_repeats_for_several) && (max_repeats != 1))
	{
		for (int index1 = 0; index1 < len; ++index1)
		{
			num_of_repeats = 0;
			for (int index2 = index1 + 1; index2 < len; ++index2)
			{
				if (str[index1] == str[index2])
				{
					++num_of_repeats;
					if (num_of_repeats = num_of_repeats_for_several)
					{
						cout << str[index1] << " ";
						break;
					}
				}
			}
		}
	}
	else if (max_repeats == 1)
	{
		for (int index1 = 0; index1 < len; ++index1)
		{
			int counter = 0;
			for (int index2 = 0; index2 < index1; ++index2)
			{
				if (str[index1] != str[index2])
				{
					counter += 1;
				}
			}
			if (counter == index1)
			{
				cout << str[index1] << " ";
			}
		}
	}
	else
		cout << moda;
	cout << endl << "Number of repeats: " << max_repeats << endl;

	return 0;
}