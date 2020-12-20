#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

void sortDatesOnRepeats(vector<tuple<int, int, int>>& dates, vector<tuple<int, int, int>>& newDates);
void sortDatesByValue(vector<tuple<int, int, int>>& dates);
void toDate(vector<tuple<int,int,int>>& dates, string row);

int main()
{
	ifstream file1("C:\\Users\\User\\Desktop\\dates.txt");

	vector<tuple<int, int, int>> dates;
	while (file1)
	{
		string row;
		getline(file1, row);
		if (row == "") { break; }
		toDate(dates, row);
	}
	file1.close();

	vector<tuple<int, int, int>> newDates;
	sortDatesOnRepeats(dates, newDates);
	sortDatesByValue(newDates);

	ofstream file2("C:\\Users\\User\\Desktop\\dates.txt");

	for (int index = 0; index < newDates.size(); ++index)
	{
		string day = to_string(get<0>(newDates[index]));
		string month = to_string(get<1>(newDates[index]));
		string year = to_string(get<2>(newDates[index]));
		if (get<0>(newDates[index]) < 10)
		{
			day = "0";
			day += to_string(get<0>(newDates[index]));
		}
		if (get<1>(newDates[index]) < 10)
		{
			month = "0";
			month += to_string(get<1>(newDates[index]));
		}
		if (get<2>(newDates[index]) < 10)
		{
			year = "0";
			year += to_string(get<2>(newDates[index]));
		}
		file2 << day << "/" << month << "/" << year << "\n";
	}
	file2.close();

	return 0;
}

void sortDatesOnRepeats(vector<tuple<int, int, int>>& dates, vector<tuple<int, int, int>>& newDates)
{
	for (int index1 = 0; index1 < dates.size(); ++index1)
	{
		int check = 1;
		for (int index2 = 0; index2 < newDates.size(); ++index2)
		{
			if ((get<0>(dates[index1]) == get<0>(newDates[index2])) && (get<1>(dates[index1]) == get<1>(newDates[index2])) && (get<2>(dates[index1]) == get<2>(newDates[index2])))
			{
				check = 0;
				break;
			}
		}
		if (check == 1)
		{
			newDates.push_back({ get<0>(dates[index1]), get<1>(dates[index1]), get<2>(dates[index1]) });
		}
	}
}

void sortDatesByValue(vector<tuple<int, int, int>>& dates)
{
	for (int index1 = 0; index1 < dates.size(); ++index1)
	{
		for (int index2 = index1 + 1; index2 < dates.size(); ++index2)
		{
			int year1 = get<2>(dates[index1]);
			int year2 = get<2>(dates[index2]);
			if (year1 < 50)
			{
				year1 += 100;
			}
			if (year2 < 50)
			{
				year2 += 100;
			}
			if (year1 < year2)
			{
				int tempDay = get<0>(dates[index1]);
				int tempMonth = get<1>(dates[index1]);
				int tempYear = get<2>(dates[index1]);
				get<0>(dates[index1]) = get<0>(dates[index2]);
				get<1>(dates[index1]) = get<1>(dates[index2]);
				get<2>(dates[index1]) = get<2>(dates[index2]);
				get<0>(dates[index2]) = tempDay;
				get<1>(dates[index2]) = tempMonth;
				get<2>(dates[index2]) = tempYear;
			}
			else if ((year1 == year2) && (get<1>(dates[index1]) < get<1>(dates[index2])))
			{
				int tempDay = get<0>(dates[index1]);
				int tempMonth = get<1>(dates[index1]);
				int tempYear = get<2>(dates[index1]);
				get<0>(dates[index1]) = get<0>(dates[index2]);
				get<1>(dates[index1]) = get<1>(dates[index2]);
				get<2>(dates[index1]) = get<2>(dates[index2]);
				get<0>(dates[index2]) = tempDay;
				get<1>(dates[index2]) = tempMonth;
				get<2>(dates[index2]) = tempYear;
			}
			else if ((year1 == year2) && (get<1>(dates[index1]) == get<1>(dates[index2])) && (get<0>(dates[index1]) < get<0>(dates[index2])))
			{
				int tempDay = get<0>(dates[index1]);
				int tempMonth = get<1>(dates[index1]);
				int tempYear = get<2>(dates[index1]);
				get<0>(dates[index1]) = get<0>(dates[index2]);
				get<1>(dates[index1]) = get<1>(dates[index2]);
				get<2>(dates[index1]) = get<2>(dates[index2]);
				get<0>(dates[index2]) = tempDay;
				get<1>(dates[index2]) = tempMonth;
				get<2>(dates[index2]) = tempYear;
			}
		}
	}
}

void toDate(vector<tuple<int,int,int>>& dates, string row)
{
	int day = 0;
	int month = 0;
	int year = 0;
	auto pos1 = row.find("/");
	if (pos1 != string::npos)
	{
		day = stod(row.substr(0, pos1));
		string monthAndYear = row.substr(pos1 + 1);
		auto pos2 = monthAndYear.find("/");
		if (pos2 != string::npos)
		{
			month = stod(monthAndYear.substr(0, pos2));
			year = stod(monthAndYear.substr(pos2+1));
		}
	}
	dates.push_back({ day, month, year });
}