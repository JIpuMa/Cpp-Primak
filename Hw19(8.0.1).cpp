#include <iostream>
#include <ctime>
using namespace std;

int NSD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return NSD(b, a % b);
}

class Rational
{
private:
    int nominator;
    int denominator;

    void Decrease()
    {
        nominator /= NSD(nominator, denominator);
        denominator /= NSD(nominator, denominator);
    }


public:
    Rational()
    {
        nominator = 1;
        denominator = 1;
    }
    Rational(const char mode)
    {
        if (mode == 'c')
        {
            cout << "Nominator: ";
            int nom;
            cin >> nom;

            cout << "Denominator: ";
            int den;
            cin >> den;
            if (den != 0)
            {
                nominator = nom;
                denominator = den;
            }
            else
            {
                cout << "Wrong denominator" << endl;
            }
        }
        else if (mode == 'r')
        {
            nominator = rand() % 100000;
            denominator = rand() % 1000000;
        }

    }
    Rational(int nom, int den)
    {
        if (den != 0)
        {
            nominator = nom;
            denominator = den;
        }
        else
        {
            cout << "Wrong denominator" << endl;
        }

    }
    int getNom()
    {
        return nominator;
    }
    int getDen()
    {
        return denominator;
    }
    void setNom(int nom)
    {
        nominator = nom;
    }
    void setDen(int den)
    {
        if (den != 0)
        {
            denominator = den;
        }
        else
        {
            cout << "Wrong denominator" << endl;
        }

    }
    Rational operator + (Rational& rat)
    {
        Rational result(1, 1);
        result.nominator = (this->nominator * rat.getDen()) + (rat.getNom() * this->getDen());
        result.denominator = this->denominator * rat.denominator;

        return result;
    }
    Rational operator * (Rational& rat)
    {
        Rational result(1, 1);
        result.setNom(this->nominator * rat.getNom());
        result.setDen(this->denominator * rat.getDen());

        return result;
    }
};


int main()
{
    Rational rat1;
    Rational rat2;

    Rational rat3 = rat1 + rat2;
    cout << rat3.getNom() << "/" << rat3.getDen() << endl;

    Rational rat4 = rat1 * rat2;
    cout << rat4.getNom() << "/" << rat4.getDen() << endl;

    return 0;
}