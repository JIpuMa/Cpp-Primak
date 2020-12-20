#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
using namespace std;

class Person
{
protected:
    string name;
    unsigned int byear;

public:
    void input()
    {
        cin >> name;
        cin >> byear;
    }
    void print()
    {
        cout << name << endl;
        cout << byear << endl;
    }
};

class Passenger : public Person
{
private:
    string start;
    string end;
    double len;
    double cost = 0;

public:
    Passenger(string& name, unsigned int year, string start, string end)
    {
        this->name = name;
        this->byear = year;
        this->start = start;
        this->end = end;
    }
    void input()
    {
        Person::input();
        cin >> start;
        cin >> end;
    }
    void print()
    {
        Person::print();
        cout << start << endl;
        cout << end << endl;
        if (cost != 0)
        {
            cout << cost << endl;
        }

    }
    void setName(string& name0)
    {
        name = name0;
    }
    void setYear(unsigned int year0)
    {
        byear = year0;
    }
    void setStart(string& start0)
    {
        start = start0;
    }
    void setEnd(string& end0)
    {
        end = end0;
    }
    string getStart()
    {
        return start;
    }
    string getEnd()
    {
        return end;
    }
    double getCost()
    {
        return calcCost();
    }
    double calcCost()
    {
        double cost = this->len*10;
        return cost;
    }
    void setLen(tuple<string, string, double>& route)
    {
        if (this->start == get<0>(route) && this->end == get<1>(route))
        {
            this->len = get<2>(route);
            this->cost = this->calcCost();
        }
        else
        {
            return;
        }

    }
};

void toWords(vector<string>& array, string row);

int main()
{
    ifstream file1("C:\\Users\\User\\Desktop\\routes.txt");

    vector< tuple<string, string, double> >  routes;

    while (file1)
    {
        string row;
        getline(file1, row);
        if (row == "") { break; }
        vector<string> inf;
        toWords(inf, row);
        tuple<string, string, double> route = make_tuple(inf[0], inf[1], stod(inf[2]));
        routes.push_back({ inf[0], inf[1], stod(inf[2]) });

    }

    ifstream file2("passengers.txt");

    vector< Passenger > passengers;

    while (file2)
    {
        string row;
        getline(file2, row);
        if (row == "") { break; }
        vector<string> inf;
        toWords(inf, row);
        Passenger pas(inf[0], stoi(inf[1]), inf[2], inf[3]);
        passengers.push_back(pas);
    }

    for (int index1 = 0; index1 < passengers.size(); ++index1)
    {
        for (int index2 = 0; index2 < routes.size(); ++index2)
        {
            passengers[index1].setLen(routes[index2]);
        }
    }

    for (int index = 0; index < passengers.size(); ++index)
    {
        passengers[index].print();
    }

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