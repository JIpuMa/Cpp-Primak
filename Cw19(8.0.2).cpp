#include <iostream>
using namespace std;


class Vector
{
private:
    int len;
    int* vector;

public:
    Vector(int len)
    {
        this->len = len;
        vector = new int[len];

        for (int index = 0; index < len; ++index)
        {
            cout << "Input vecror[" << index << "] = ";
            int element = 0;
            cin >> element;
            vector[index] = element;
        }
    }
    Vector(const Vector& copyVec)
    {
        vector = nullptr;

        if (copyVec.vector != nullptr)
        {
            vector = copyVec.vector;
        }

    }
    void setVector()
    {
        for (int index = 0; index < len; ++index)
        {
            cout << "Input vector[" << index << "] = ";
            int element = 0;
            cin >> element;
            vector[index] = element;
        }
    }
    void setConElement(int index)
    {
        cout << "Value: ";
        int val = 0;
        cin >> val;
        vector[index] = val;
    }
    void setElement(int element, int index)
    {
        vector[index] = element;
    }
    int getLen()
    {
        return len;
    }
    int* getVector()
    {
        return this->vector;
    }

    ~Vector()
    {
        if (vector != nullptr)
        {
            delete[] vector;
        }
    }
};

int main()
{
    return 0;
}