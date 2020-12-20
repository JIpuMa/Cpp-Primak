#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Student
{
	string surname;
	string name;
	string byFather;
	string sex;
	unsigned int age;
	unsigned int course;
};

int main()
{
	cout << "Input N: ";
	unsigned int N = 0;
	cin >> N;

	vector<Student> students(0);

	for (int index = 0; index < N; ++index)
	{
		cout << endl << "Student " << index + 1 << endl;
		Student student;

		cout << "Surname: ";
		string surname;
		cin >> surname;
		student.surname = surname;

		cout << "Name: ";
		string name;
		cin >> name;
		student.name = name;

		cout << "By father: ";
		string byFather;
		cin >> byFather;
		student.byFather = byFather;

		cout << "Sex: ";
		string sex;
		cin >> sex;
		student.sex = sex;
		
		cout << "Age: ";
		unsigned int age;
		cin >> age;
		student.age = age;

		cout << "Course: ";
		unsigned int course;
		cin >> course;
		student.course = course;

		students.push_back(student);
	}
	
	int check = 1;
	string manPopularName;
	int manMaxRepeats = 1;
	int manTemporaryRepeats = 1;
	string womanPopularName;
	int womanMaxRepeats = 1;
	int womanTemporaryRepeats = 1;

	for (int index1 = 0; index1 < N; ++index1)
	{
		manTemporaryRepeats = 1;
		womanTemporaryRepeats = 1;
		for (int index2 = index1+1; index2 < N; ++index2)
		{
			if (students[index1].sex == "man")
			{
				if (students[index1].name == students[index2].name)
				{
					++manTemporaryRepeats;
					if (manMaxRepeats <= manTemporaryRepeats)
					{
						manPopularName = students[index1].name;
						manMaxRepeats = manTemporaryRepeats;
					}
				}
			}
			else if (students[index1].sex == "woman")
			{
				if (students[index1].name == students[index2].name)
				{
					++womanTemporaryRepeats;
					if (womanMaxRepeats <= womanTemporaryRepeats)
					{
						womanPopularName = students[index1].name;
						womanMaxRepeats = womanTemporaryRepeats;
					}
				}
			}
			else
			{
				cout << endl << "Entered the wrong sex" << endl;
				index1 = N;
				check = 0;
				break;
			}
		}
	}

	if (check == 1)
	{
		cout << "The most common man name: " << manPopularName << endl;
		cout << "The most common woman name: " << womanPopularName << endl;
	}

	return 0;
}