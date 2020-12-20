#include <iostream>
#include <string>
using namespace std;

int checkDate(string str);
void printDate(string str, int correctDate);

int main()
{
	cout << "Input date: ";
	string str;
	cin >> str;

	int correctDate = checkDate(str);
	printDate(str, correctDate);

	return 0;
}

int checkDate(string str)
{
	int date = stoi(str);
	int day = date / 1000000;
	int month = (date % 1000000) / 10000;
	int year = date % 10000;

	int correctDate = 0;

	if (month <= 12)
	{
		if (((month == 1) | (month == 3) |
			(month == 5) | (month == 7) |
			(month == 8) | (month == 10) |
			(month == 12)) && (day <= 31))
		{
			correctDate = 1;
		}
		else if (((month == 4) | (month == 6) | (month == 9) | (month == 11)) && (day <= 30))
		{
			correctDate = 1;
		}
		else if ((year % 4 == 0) && (day <= 29))
		{
			correctDate = 1;
		}
		else if ((year % 4 != 0) && (day <= 28))
		{
			correctDate = 1;
		}
	}

	return correctDate;
}

void printDate(string str, int correctDate)
{
	cout << endl << "1 variant" << endl;

	string strDate;

	if (correctDate == 1)
	{
		for (int index = 0; index < 8; ++index)
		{
			strDate += str[index];
			if ((index == 1) | (index == 3))
			{
				strDate += '-';
			}
		}
	}
	else
	{
		strDate = "Incorrect date";
	}

	cout << strDate << endl;

	cout << endl << "2 variant" << endl;

	if (correctDate == 1)
	{
		for (int index1 = 0; index1 < 8; ++index1)
		{
			if (index1 == 2)
			{
				str += str[7];
				for (int index2 = 8; index2 > index1; --index2)
				{
					str[index2] = str[index2 - 1];
				}
				str[index1] = '-';
			}
			else if (index1 == 5)
			{
				str += str[8];
				for (int index2 = 9; index2 > index1; --index2)
				{
					str[index2] = str[index2 - 1];
				}
				str[index1] = '-';
			}
		}
	}
	else
	{
		strDate = "Incorrect date";
	}

	cout << str << endl;
}