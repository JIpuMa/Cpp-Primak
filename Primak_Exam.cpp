#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

void toCoords(vector<string>& array, string row, string symbol);

int main()
{
	ifstream file("C:\\Users\\User\\Desktop\\points.txt");
	
    cout << "Your points:" << endl;
    vector< tuple<int, int, int> > points;
    while (file)
    {
        string row;
        getline(file, row);
        if (row == "") { break; }
        vector<string> rowFile;
        toCoords(rowFile, row, ";");
        
        for (int i = 0; i < rowFile.size()-1; ++i)
        {
            vector<string> coords;
            toCoords(coords, rowFile[i], ",");
            cout << coords[0] << " " << coords[1] << " " << coords[2] << " " << endl;
            points.push_back({ (int)stod(coords[0]), (int)stod(coords[1]), (int)stod(coords[2]) });
        }
    }
    file.close();

    vector< tuple<double, int, int> > offcuts;
    for (int i = 0; i < points.size(); ++i)
    {
        int x1 = get<0>(points[i]);
        int y1 = get<1>(points[i]);
        int z1 = get<2>(points[i]);
        for (int j = 0; j < points.size(); ++j)
        {
            if (i != j)
            {
                int x2 = get<0>(points[j]);
                int y2 = get<1>(points[j]);
                int z2 = get<2>(points[j]);
                double len = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
                offcuts.push_back({ len, i, j });
            }
        }
    }

    int maxP1 = get<1>(offcuts[0]);
    int maxP2 = get<2>(offcuts[0]);
    double maxLen = get<0>(offcuts[0]);
    for (int i = 0; i < offcuts.size(); ++i)
    {
        if (maxLen < get<0>(offcuts[i]))
        {
            maxP1 = get<1>(offcuts[i]);
            maxP2 = get<2>(offcuts[i]);
            maxLen = get<0>(offcuts[i]);
        }
    }
    
    cout << "AB = " << maxLen << " is the longest offcut, where A("
        << get<0>(points[maxP1]) << "," << get<1>(points[maxP1]) << "," << get<2>(points[maxP1])
        << ") and B("
        << get<0>(points[maxP2]) << "," << get<1>(points[maxP2]) << "," << get<2>(points[maxP2])
        << ")" << endl;

	return 0;
}

void toCoords(vector<string>& array, string row, string symbol)
{
    auto pos1 = row.find(symbol);
    if (pos1 != string::npos)
    {
        array.push_back(row.substr(0, pos1));
    }
    auto pos2 = row.find(symbol);
    if (pos2 != string::npos)
    {
        toCoords(array, row.substr(pos1 + 1), symbol);
    }
    else
    {
        array.push_back(row.substr(pos1 + 1));
    }
}