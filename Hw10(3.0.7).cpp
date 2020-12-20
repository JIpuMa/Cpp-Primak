#include <iostream>
using namespace std;

int inputN();
int inputM();
double** mulMatrix(unsigned int n1, unsigned int m1, unsigned int n2, unsigned int m2, double** array1, double** array2);
double **inputArray(unsigned int m, unsigned int n);
void printArray(unsigned int n, unsigned int m, double** array);
void delete2DimArray(unsigned int n, double** array);
void deleteLength(unsigned int len, int** array);

int main()
{
	cout << "Input array length: ";
	unsigned int len = 0;
	cin >> len;

	int** arrayLength = new int* [len];
	double*** array = new double**[len];
	for (int index = 0; index < len; ++index)
	{
		cout << "For matrix " << index+1 << ": " << endl;
		unsigned int n = inputN();
		unsigned int m = inputM();
		double** array0 = inputArray(m, n);
		array[index] = array0;
		arrayLength[index] = new int[2];
		arrayLength[index][0] = n;
		arrayLength[index][1] = m;
	}

	int check = 1;
	for (int index = 0; index < len - 1; ++index)
	{
		if (arrayLength[index][1] != arrayLength[index + 1][0])
		{
			check = 0;
		}
	}

	double** arrayResult = array[0];
	if (check == 1)
	{
		for (int index = 0; index < len-1; ++index)
		{
			unsigned int n1 = arrayLength[index][0];
			unsigned int m1 = arrayLength[index][1];
			unsigned int n2 = arrayLength[index+1][0];
			unsigned int m2 = arrayLength[index+1][1];
			arrayResult = mulMatrix(n1, m1, n2, m2, arrayResult, array[index+1]);
		}
		unsigned int n = arrayLength[0][0];
		unsigned int m = arrayLength[0][1];
		printArray(n, m, arrayResult);
	}
	else
	{
		cout << "It is impossible" << endl;
	}

	for (int index = 0; index < len; ++index)
	{
		delete2DimArray(arrayLength[index][0], array[index]);
	}
	delete[] array;

	deleteLength(len, arrayLength);

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

double **mulMatrix(unsigned int n1, unsigned int m1, unsigned int n2, unsigned int m2, double** array1, double** array2)
{
	double** arrayResult = new double* [n1];
	for (int index1 = 0; index1 < n1; ++index1)
	{
		arrayResult[index1] = new double[m2];
		for (int index2 = 0; index2 < m2; ++index2)
		{
			arrayResult[index1][index2] = 0;
			for (int index3 = 0; index3 < m1; ++index3)
			{
				arrayResult[index1][index2] += array1[index1][index3] * array2[index3][index2];
			}
		}
	}
	return arrayResult;
}

double **inputArray(unsigned int m, unsigned int n)
{
	double** newArray = new double*[n];
	for (int index1 = 0; index1 < n; ++index1)
	{
		newArray[index1] = new double [m];
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

void deleteLength(unsigned int len, int** array)
{
	for (int index = 0; index < len; ++index)
	{
		delete[] array[index];
	}
	delete[] array;
}