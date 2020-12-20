#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <vector>
#include <string>

using namespace std;

/*Класи Image та Mask мають подібну структуру*/
class Image
{
    unsigned _m;                 //Значення параметру m
    unsigned _n;                 //Значення параметру n
    vector<vector<int>> _data;   //Матриця розмірності m*n цілих чисел
public:
    Image(unsigned m, unsigned n);                     //Конструктор класу Image
    int getPixel(unsigned i, unsigned j) const;        //Отримання значення пікселя
    void setPixel(int clr, unsigned i, unsigned j);    //Встановлення значення пікселя
    unsigned getM() const;                             //Отримання значення параметру
    unsigned getN() const;                             //Отримання значення параметру
    void applyFilter(const Image &mask);               //Накладання фільтра Mask на Image
    void show() const;                                 //Вивід матриці
    void save(const string& filename) const;           //Збереження в файл
    static Image load(const string& filename);         //Отримання матриці з файлу
};

#endif // IMAGE_H_INCLUDED
