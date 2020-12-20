#include <iostream>
using namespace std;

int inputN();
int inputM();
double** createNewArray(unsigned int m, unsigned int n, double** array);
double** inputArray(unsigned int m, unsigned int n);
void printArray(unsigned int n, unsigned int m, double** array);
void delete2DimArray(unsigned int n, double** array);

int main()
{
	unsigned int n = inputN();
	unsigned int m = inputM();

	double** array0 = inputArray(m, n);
	cout << "Your array:" << endl;
	printArray(n, m, array0);

	double** array = createNewArray(m, n, array0);
	if (m % 2 == 0)
	{
		m /= 2;
	}
	else
	{
		m /= 2;
		m += 1;
	}
	cout << "New array:" << endl;
	printArray(n, m, array);

	delete2DimArray(n, array0);
	delete2DimArray(n, array);

	return 0;
}

int inputN()
{
	cout << "Input n: ";
	unsigned int n = 0;
	cin >> n;
	return n;
}

int inputM()
{
	cout << "Input m: ";
	unsigned int m = 0;
	cin >> m;
	return m;
}

double** createNewArray(unsigned int m, unsigned int n, double** array)
{
	double** newArray = new double* [n];
	for (int index1 = 0; index1 < n; ++index1)
	{
		int newIndex2 = 0;
		newArray[index1] = new double[m];
		for (int index2 = 0; index2 < m; ++index2)
		{
			if (((index2 + 1) % 2) != 0)
			{
				newArray[index1][index2-newIndex2] = array[index1][index2];
			}
			else
			{
				newIndex2 += 1;
			}

		}
	}
	return newArray;
}

double** inputArray(unsigned int m, unsigned int n)
{
	double** newArray = new double* [n];
	for (int index1 = 0; index1 < n; ++index1)
	{
		newArray[index1] = new double[m];
		for (int index2 = 0; index2 < m; ++index2)
		{
			cout << "Input array[" << index1 << "][" << index2 << "] = ";
			double element = 0;
			cin >> element;
			newArray[index1][index2] = element;
		}
	}

	return newArray;
}

void printArray(unsigned int n, unsigned int m, double** array)
{
	for (int index1 = 0; index1 < n; ++index1)
	{
		for (int index2 = 0; index2 < m; ++index2)
		{
			cout << array[index1][index2] << " ";
		}
		cout << endl;
	}
}

void delete2DimArray(unsigned int n, double** array)
{
	for (int index = 0; index < n; ++index)
	{
		delete[] array[index];
	}
	delete[] array;
}