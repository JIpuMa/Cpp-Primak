#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printWords(vector<string>& words, char symbol);
void toWords(vector<string>& words, string row);

int main()
{
	cout << "Input row: ";
	string row;
	getline(cin, row);

	cout << "Input symbol: ";
	char symbol;
	cin >> symbol;

	vector<string> words(0);
	toWords(words, row);
	printWords(words, symbol);

	return 0;
}

void printWords(vector<string>& words, char symbol)
{
	cout << "Words which ending in \"" << symbol << "\": ";
	for (int index = 0; index < words.size(); ++index)
	{
		if ((char)words[index][words[index].length() -1] == symbol)
		{
			cout << words[index] << " ";
		}
	}
	cout << endl;
}

void toWords(vector<string>& words, string row)
{
	auto pos1 = row.find(" ");
	int step = 1;
	for (int index = pos1 + 1; index < row.length(); ++index)
	{
		if ((char)row[index] != ' ')
		{
			step = index - pos1;
			break;
		}
	}
	if (pos1 != string::npos)
	{
		words.push_back(row.substr(0, pos1));
	}
	auto pos2 = row.find(" ");
	if (pos2 != string::npos)
	{
		toWords(words, row.substr(pos1 + step));
	}
	else
	{
		words.push_back(row.substr(pos1 + step));
	}
}