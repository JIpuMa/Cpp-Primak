#ifndef SAVER_H_INCLUDED
#define SAVER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include "image.h"

using namespace std;

/*���� ��� ���������� ������� � ����*/
class ImageSaver
{
    ofstream out;  //���� ��� ������ �������
public:
    ImageSaver(const string& filename);  //����������� ����� ImageSaver
    ~ImageSaver();                       //���������� ����� ImageSaver
    void save(const Image& image);       //����� ������� � ����
};

#endif // SAVER_H_INCLUDED
