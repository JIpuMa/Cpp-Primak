#include <iostream>
using namespace std;

int main()
{
	int M[4] = { 5, 112, 4, 3 };
	cout << M[3] << " " << M[2] << " " << M[1] << " " << M[0] << endl;
	for (int index = 3; index >= 0; --index)
	{
		cout << M[index] << " ";
	}
	return 0;
}