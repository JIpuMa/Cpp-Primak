#include <iostream>
#include <vector>
using namespace std;

void input_array(vector<int> &array)
{
	cout << "Input n: ";
	int n = 0;
	cin >> n;

	for (int index = 0; index < n; ++index)
	{
		cout << "Input M[" << index << "] = ";
		int element = 0;
		cin >> element;
		array.push_back(element);
	}
}

void print_array(vector<int> array)
{
	int size = array.size();
	for (int index = 0; index < size; ++index)
	{
		cout << "M[" << index << "] = " << array[index] << "; ";
	}
	cout << endl;
}

void sum_vectors(vector<int> array1, vector<int> array2, vector<int> &array3)
{
	int size = array1.size();
	for (int index = 0; index < size; ++index)
	{
		int element = array1[index] + array2[index];
		array3.push_back(element);
	}
}

double scalar_mul(vector<int> array1, vector<int> array2)
{
	int size = array1.size();
	double scal_mul = 0;
	for (int index = 0; index < size; ++index)
	{
		scal_mul += array1[index] * array2[index];
	}
	return scal_mul;
}

int main()
{
	vector<int> array1(0);
	input_array(array1);
	print_array(array1);

	vector<int> array2(0);
	input_array(array2);
	print_array(array2);

	vector<int> array3(0);
	sum_vectors(array1, array2, array3);
	print_array(array3);

	cout << "Scalar multiplication: " << scalar_mul(array1, array2);

	return 0;
}