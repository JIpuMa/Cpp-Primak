#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream file1("C:\\Users\\User\\Desktop\\symbols.txt");
	string str((istreambuf_iterator<char>(file1)), istreambuf_iterator<char>());
	file1.close();

	cout << "Input symbol: ";
	string firstSymbol;
	cin >> firstSymbol;

	str = firstSymbol + str;
	
	ofstream file2("C:\\Users\\User\\Desktop\\symbols.txt");
	file2 << str;
	file2.close();

	return 0;
}