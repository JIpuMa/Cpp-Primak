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
        if (words[index] == "one") 
        { 
            words[index] = "1"; 
        }
        else if (words[index] == "two") 
        {
            words[index] = "2"; 
        }
        else if (words[index] == "three") 
        { 
            words[index] = "3"; 
        }
        else if (words[index] == "four") 
        { 
            words[index] = "4"; 
        }
        else if (words[index] == "five") 
        { 
            words[index] = "5"; 
        }
        else if (words[index] == "six") 
        { 
            words[index] = "6"; 
        }
        else if (words[index] == "seven") 
        { 
            words[index] = "7"; 
        }
        else if (words[index] == "eight") 
        { 
            words[index] = "8"; 
        }
        else if (words[index] == "nine") 
        { 
            words[index] = "9"; 
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