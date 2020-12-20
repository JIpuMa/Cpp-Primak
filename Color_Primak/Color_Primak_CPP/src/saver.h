#ifndef SAVER_H_INCLUDED
#define SAVER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include "image.h"

using namespace std;

/*Клас для збереження матриці в файл*/
class ImageSaver
{
    ofstream out;  //Файл для запису матриці
public:
    ImageSaver(const string& filename);  //Конструктор класу ImageSaver
    ~ImageSaver();                       //Деструктор класу ImageSaver
    void save(const Image& image);       //Запис матриці в файл
};

#endif // SAVER_H_INCLUDED
