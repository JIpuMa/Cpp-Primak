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

    int num = 0;
    for (int index = 0; index < words.size(); ++index)
    {
        if (words[index].find(" ") == -1)
        {
            if (words[index][0] == words[index][words[index].length() - 1])
            {
                ++num;
            }
        }
    }
    cout << "Result: " << num << endl;

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