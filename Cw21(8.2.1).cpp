#include <iostream>
#include <cmath>
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

        result.Decrease();

        return result;
    }
    Rational operator + (double num)
    {
        Rational result;
        result.nominator = this->nominator + num * this->denominator;

        result.Decrease();

        return result;
    }
    Rational operator - (Rational& rat)
    {
        Rational result(1, 1);
        result.nominator = (this->nominator * rat.getDen()) - (rat.getNom() * this->getDen());
        result.denominator = this->denominator * rat.denominator;

        result.Decrease();

        return result;
    }
    Rational operator * (Rational& rat)
    {
        Rational result(1, 1);
        result.setNom(this->nominator * rat.getNom());
        result.setDen(this->denominator * rat.getDen());

        result.Decrease();

        return result;
    }
    Rational operator * (double num)
    {
        Rational result;
        result.setNom(this->nominator * num);

        result.Decrease();

        return result;
    }
    Rational operator / (Rational& rat)
    {
        Rational result(1, 1);
        result.setNom(this->nominator * rat.getDen());
        result.setDen(this->denominator * rat.getNom());

        result.Decrease();

        return result;
    }
    Rational Abs()
    {
        if (nominator < 0)
        {
            nominator = -nominator;
            return *this;
        }
        else 
        { 
            return *this; 
        }
    }
    void operator -()
    {
        nominator = -nominator;
    }
    bool operator > (Rational& rat)
    {
        if ((*this - rat).nominator > 0) 
        { 
            return true; 
        }
        else if ((*this - rat).nominator < 0) 
        { 
            return false; 
        }
        else
        {
            return (*this == rat);
        }

    }
    bool operator < (Rational& rat)
    {
        return !(*this > rat);
    }
    bool operator == (Rational& rat)
    {
        if ((*this - rat).nominator == 0) 
        { 
            return true; 
        }
        else 
        { 
            return false; 
        }
    }


};


int main()
{
    Rational array[5];

    for (int index = 0; index < 5; ++index)
    {
        Rational rat('c');
        array[index] = rat;
    }

    Rational max = array[0].Abs();

    for (int index = 1; index < 5; ++index)
    {
        if (array[index].Abs() > max)
        {
            max = array[index];
        }
    }

    cout << max.getNom() << "/" << max.getDen() << endl;

    return 0;
}