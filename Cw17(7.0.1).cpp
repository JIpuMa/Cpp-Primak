#include <iostream>
#include <string>
#include <vector>
using namespace std;

void toWords(vector<string>& array, string row);

int main()
{
    cout << "Input string: ";
    string str;
    getline(cin, str);

    vector<string> words;
    toWords(words, str);

    for (int index = 0; index < words.size(); ++index)
    {
        if (words[index].find(" ") == -1)
        {
            string word = words[index];
            words[index].clear();
            for (int index2 = 1; index2 < word.length(); ++index2)
            {
                if (word[index2] != word[0])
                {
                    words[index].push_back(word[index2]);
                }
            }
        }
    }

    string newStr;
    for (int index = 0; index < words.size(); ++index)
    {
        if (index > 0) 
        { 
            newStr += ' ' + words[index]; 
        }
        else
        { 
            newStr += words[index];
        }
    }

    cout << "New string: " << newStr << endl;

    return 0;
}

void toWords(vector<string>& array, string row)
{
    auto pos1 = row.find(" ");
    if (pos1 != string::npos)
    {
        array.push_back(row.substr(0, pos1));
    }
    auto pos2 = row.find(" ");
    if (pos2 != string::npos)
    {
        toWords(array, row.substr(pos1 + 1));
    }
    else
    {
        array.push_back(row.substr(pos1 + 1));
    }
}