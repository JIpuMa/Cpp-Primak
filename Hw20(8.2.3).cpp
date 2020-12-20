#include <iostream>
using namespace std;

class Dymanic_Array
{
public:
	int *createArray(int n)
	{
		int* array = new int [n];
		for (int index = 0; index < n; ++index)
		{
			cout << "Input array[" << index << "] = ";
			int element = 0;
			cin >> element;
			array[index] = element;
		}
		return array;
	}
	void deleteArray(int* array)
	{
		delete[] array;
	}
	int getElement(int* array, int index)
	{
		return array[index];
	}
	void changeElement(int* array, int index, int value)
	{
		array[index] = value;
	}
};

int main()
{
	Dymanic_Array array1, array2;

	cout << "Input is correct if m > n" << endl;

	cout << "Input m: ";
	int m = 0;
	cin >> m;
	int *ar1 = array1.createArray(m);


	cout << "Input n: ";
	int n = 0;
	cin >> n;
	int *ar2 = array2.createArray(n);


	int scalMul = 0;
	for (int index = 0; index < n; ++index)
	{
		scalMul += array1.getElement(ar1, m - n + index) * array2.getElement(ar2, index);
	}

	cout << "Scalar multiplication: " << scalMul << endl;

	array1.deleteArray(ar1);
	array2.deleteArray(ar2);

	return 0;
}