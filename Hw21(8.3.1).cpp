#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Person
{
protected:
	string name;
	unsigned byear;

public:
	int input()
	{
		cin >> name;
		cin >> byear;
	}
	void print()
	{
		cout << name << endl;
		cout << byear << endl;
	}
};

class Familiar : public Person
{
protected:
	string number;

public:
	Familiar(string& name, unsigned int year, string number)
	{
		this->name = name;
		this->byear = year;
		this->number = number;
	}
	int input()
	{
		Person::input();
		cin >> number;
	}
	void print()
	{
		Person::print();
		cout << number << endl;
	}
	void setName(string& name0)
	{
		name = name0;
	}
	void setYear(unsigned year0)
	{
		byear = year0;
	}
	void setNumber(string number0)
	{
		number = number0;
	}
	string getName()
	{
		return name;
	}
	unsigned int getYear()
	{
		return byear;
	}
	string getNumber()
	{
		return number;
	}
};

vector<Familiar> directory();
void directoryAdd(vector<Familiar>& fams, string name, int year, string number);
string findNumber(vector<Familiar>& fams, string name);
void changeNumber(vector<Familiar>& fams, string name, string number);
void toWords(vector<string>& words, string row);


int main()
{
	ifstream file1("C:\\Users\\User\\Desktop\\directory.txt");

	vector<Familiar> fams = directory();
	while (file1)
	{
		string row;
		getline(file1, row);
		if (row == "") { break; }
		vector<string> inf;
		toWords(inf, row);
		directoryAdd(fams, inf[0], stod(inf[1]), inf[2]);
	}
	file1.close();

	cout << "Name: ";
	string name;
	cin >> name;
	cout << "Number: " << findNumber(fams, name) << endl;
	cout << "New number: ";
	string newNumber;
	cin >> newNumber;
	changeNumber(fams, name, newNumber);

	ofstream file2("C:\\Users\\User\\Desktop\\directory.txt");

	for (int index = 0; index < fams.size(); ++index)
	{
		file2 << fams[index].getName() << " " << fams[index].getYear() << " " << fams[index].getNumber() << "\n";
	}
	file2.close();

	return 0;
}

vector<Familiar> directory()
{
	vector<Familiar> fams;
	return fams;
}

void directoryAdd(vector<Familiar>& fams, string name, int year, string number)
{
	Familiar fam(name, year, number);
	fams.push_back(fam);
}

string findNumber(vector<Familiar>& fams, string name)
{
	for (int index = 0; index < fams.size(); ++index)
	{
		if (fams[index].getName() == name)
		{
			return fams[index].getNumber();
		}
	}
	return "indefinite";
}

void changeNumber(vector<Familiar>& fams, string name, string number)
{
	for (int index = 0; index < fams.size(); ++index)
	{
		if (fams[index].getName() == name)
		{
			fams[index].setNumber(number);
		}
	}
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