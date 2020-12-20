#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include "image.h"

using namespace std;

/*Клас для отримання матриці з файлу*/
class ImageLoader
{
    ifstream in;   //Файл для читання матриці
public:
    ImageLoader(const string& filename);   //Конструктор класу ImageLoader
    ~ImageLoader();                        //Деструктор класу ImageLoader
    Image load();                          //Зчитування матриці з файлу
};

#endif // LOADER_H_INCLUDED
