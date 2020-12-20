#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f("C:\\Users\\User\\Desktop\\f.txt", ios_base::binary);
	string str((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
	f.close();


	return 0;
}