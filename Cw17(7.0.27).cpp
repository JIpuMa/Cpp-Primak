#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lenSentense(vector<string>& array);
float findPercent(string word, vector<string>& array, int lenSent);
void toWords(vector<string>& array, string sentense);

int main()
{
	cout << "Input sentense: ";
	string sentense;
	getline(cin, sentense);

	vector<string> words(0);

	toWords(words, sentense);
	int lenSent = lenSentense(words);
	for (int index = 0; index < words.size(); ++index)
	{
		float wordPercent = findPercent(words[index], words, lenSent);
		cout << endl << "For word: \"" << words[index] << "\": " << wordPercent << "%" << endl;
	}

	return 0;
}

int lenSentense(vector<string>& array)
{
	int lenSentense = 0;
	for (int index = 0; index < array.size(); ++index)
	{
		lenSentense += array[index].length();
	}
	return lenSentense;
}

float findPercent(string word, vector<string>& array, int lenSent)
{
	float wordPercent = 0;
	int lenWord = word.length();
	int countSymbol = 0;
	for (int index1 = 0; index1 < lenWord; ++index1)
	{
		if (lenWord != 1)
		{
			for (int index2 = index1 + 1; index2 < lenWord; ++index2)
			{
				if (word[index1] == word[index2])
				{
					break;
				}
				else
				{
					countSymbol = 0;
					for (int index3 = 0; index3 < array.size(); ++index3)
					{
						for (int index4 = 0; index4 < array[index3].length(); ++index4)
						{
							if (word[index1] == array[index3][index4])
							{
								++countSymbol;
							}
						}
					}
					float symbolPercent = (float)countSymbol / lenSent * 100;
					wordPercent += symbolPercent;
				}
			}
		}
		else
		{
			countSymbol = 0;
			for (int index3 = 0; index3 < array.size(); ++index3)
			{
				for (int index4 = 0; index4 < array[index3].length(); ++index4)
				{
					if (word[index1] == array[index3][index4])
					{
						++countSymbol;
					}
				}
			}
			float symbolPercent = (float)countSymbol / lenSent * 100;
			wordPercent += symbolPercent;
		}
	}
	return wordPercent;
}

void toWords(vector<string>& array, string sentense)
{
	auto pos1 = sentense.find(" ");
	if (pos1 != string::npos)
	{
		array.push_back(sentense.substr(0, pos1));
	}
	auto pos2 = sentense.find(" ");
	if (pos2 != string::npos)
	{
		toWords(array, sentense.substr(pos1 + 1));
	}
	else
	{
		array.push_back(sentense.substr(pos1 + 1));
	}
}